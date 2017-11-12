#include<bits/stdc++.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string.h>
#include <pwd.h>
#include<unistd.h>

using namespace std;

class base_job
{
	public:
		virtual bool execute()=0;
		virtual char const *name()=0;
};

//Function to convert int value into string value.
string to_string(int val)
{
	ostringstream str1;
	str1 << val;
	string conv=str1.str();
	return conv;
}

void execute_pipeline(base_job *a[],int n)
{
	int i;
	bool result,result_copy[1000];	//To store results of the executed functions.
	char choice,mode,name[30],str[255],help_ch;
	char const *func_name;		//stores name of the function
	FILE *fp;
	time_t ptr;
	
	FILE *bufferp,*buffer_cp;	//pointers to buffer file and file containing count of buffer.
	char bufname[30],ch,current_file[32];
	int bufcount;
	
	//open file containing buffer count and get the count.
	buffer_cp=fopen("Buffercount.txt","r");
	fscanf(buffer_cp,"%d",&bufcount);
	fclose(buffer_cp);
	
	//increment the buffer count.
	bufcount++;
	
	//write the incremented count back to the file.
	buffer_cp=fopen("Buffercount.txt","w");
	fprintf(buffer_cp,"%d",bufcount);
	fclose(buffer_cp);
	
	//Set a new filename for the buffer
	strcpy(bufname,"Buffer");
	string s= bufname+to_string(bufcount);
	strcpy(bufname,s.c_str());
	strcat(bufname,".cpp");
	
	//create a new file with previously set filename
	bufferp=fopen(bufname,"w");
	fclose(bufferp);
	
	fstream x,y;
	cout<<"Enter your current file name(Ex: Sample.cpp)\n";
	cin>>current_file;
	x.open(current_file); 		//The file from which the content will be copied
	y.open(bufname); 		//The file to which the content will be copied
	
	while (!x.eof())
	{
		x.get(ch); 		//reading from file object 'x'
		y<<ch; 			//writing to file 
	}
	x.close();
	y.close();
	
	//Get the System user name 
	register struct passwd *pw;
	register uid_t uid;
	uid = geteuid ();
	pw = getpwuid (uid);
	
	strcpy(name,pw->pw_name);
	strcat(name,"_history.txt");
	cout<<"Do you want to turn on silent mode?(Y/N)";
	cin>>mode;
	
	fp=fopen(name,"a");
	fprintf(fp,"\nBuffer %d:\n",bufcount);
	fclose(fp);
	for(i=0;i<n;i++)
	{
				
		time(&ptr);		
		func_name=a[i]->name();		//Get the name of function
		result=a[i]->execute();		//Execute the job
		//Save the result, date and time in a file
		fp=fopen(name,"a");
		if(result==true)
			fprintf(fp,"%s executed at %s		Result:Successful\n",func_name,ctime(&ptr));
		else
			fprintf(fp,"%s executed at %s		Result:Failure\n",func_name,ctime(&ptr));
		fclose(fp);
		if(mode=='n'||mode=='N')
		{		
			if(result==false)
			{
				cout<<"Fault detected.\n";
				cout<<"Do you need any help?\n";
				cin>>help_ch;
				if(help_ch=='y'||help_ch=='Y')
				{
					system("google-chrome http://google.com"); //Open google in browser automatically if user needs help
				}
				cout<<"Do you still want to continue?(Y/N)\n";
				cin>>choice;
				if(choice=='n'||choice=='N')
				{
					return;
				}			
			}
			else
			{
				cout<<func_name<<" executed successfully\n";
			}
		}
		result_copy[i]=result;
	}
	if(mode=='y'||mode=='Y')
	{
		for(i=0;i<n;i++)
		{
			func_name=a[i]->name();
			if(result_copy[i]==true)
			{
				cout<<func_name<<" executed successfully."<<endl;
			}
			else
			{
				cout<<"Fault detected in "<<func_name<<endl;
			}
		}
		cout<<"Do you need any help?\n";
		cin>>help_ch;
		if(help_ch=='y'||help_ch=='Y')
		{
			system("google-chrome http://google.com");
		}
	}
	char history_ch;
	cout<<"\nDo u want to display History?\n";
	cin>>history_ch;
	if(history_ch=='y'||history_ch=='Y')
	{
		cout<<"History :\n";
		ifstream in(name);
		//Read and Display history from the file
		while(in)
		{
			in.getline(str, 255);  
			if(in) cout << str << endl;
		}
		in.close();
	}
	
	char buf_ch;
	int buf_pos;
	char buf_temp[32];
	char buf_temp2[32];
	cout<<"\nPresent Buffer number = "<<bufcount<<"\nDo you want to rivert back to any of your previous codes?(y/n)\n";
	cin>>buf_ch;
	if(buf_ch=='y'||buf_ch=='Y')
	{
		cout<<"Enter the Buffer number\n";
		cin>>buf_pos;
		if(buf_pos>bufcount||buf_pos<1)
			cout<<"\nInvalid Buffer number\n";
		else
		{
			string buf_temp1="Buffer"+to_string(buf_pos);
			strcpy(buf_temp,buf_temp1.c_str());
			strcat(buf_temp,".cpp");
			
			x.open(buf_temp); 		//The file from which the content will be copied
			y.open(current_file); 		//The file to which the content will be copied
			while (!x.eof())
			{
				x.get(ch); 		//reading from file object 'x'
				y<<ch; 			//writing to file 
			}
			x.close();
			y.close();	

			strcpy(buf_temp2,"gedit ");
			strcat(buf_temp2,current_file);
			system(buf_temp2);
		}	
	} 	
	cout<<"\nHistory has been saved in the file "<<name<<endl;
}
