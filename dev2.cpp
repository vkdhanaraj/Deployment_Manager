#include<bits/stdc++.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string.h>
#include <pwd.h>
#include<unistd.h>
#define KNRM  "\x1B[40;0m"
#define KRED  "\x1B[31;1m"
#define KGRN  "\x1B[32;1m"
#define KYEL  "\x1B[33;1m"
#define KBLU  "\x1B[34;1m"
#define KMAG  "\x1B[35;1m"
#define KCYN  "\x1B[36;1m"
#define KWHT  "\x1B[37;1m"
#define RED  "\x1B[41;1m"

using namespace std;

class base_job
{
	public:
		virtual bool execute()=0;
		virtual char const *name()=0;
		virtual bool privilege()=0;
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
	bool result,result_copy[1000],execute_copy[1000]={false};	//To store results of the executed functions.
	char choice,mode,name[30],str[255],help_ch;
	char const *func_name;		//stores name of the function
	FILE *fp;
	time_t ptr;
	
	FILE *bufferp,*buffer_cp;	//pointers to buffer file and file containing count of buffer.
	char bufname[30],ch,current_file[32];
	int bufcount;
	
	cout<<KWHT;
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
	cout<<"\nEnter your current file name(Ex: Sample.cpp)\n";
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
	cout<<"\nDo you want to turn on silent mode(ie., Do you want to execute all tasks without displaying any result in between execution)?("<<KGRN<<"Y"<<KWHT<<"/"<<KRED<<"N"<<KNRM<<KWHT")\n";
	cin>>mode;
	
	fp=fopen(name,"a");
	fprintf(fp,"\nBuffer %d:\n",bufcount);
	fclose(fp);
	
	bool access;
	
	
	for(i=0;i<n;i++)
	{		
		time(&ptr);		
		func_name=a[i]->name();		//Get the name of function
		access=a[i]->privilege();
		if(access==true)
		{
		execute:
			try
			{
				execute_copy[i]=true;
				result=a[i]->execute();	//Execute the job
			}
			catch(int e)
			{
				cout<<RED<<"Error Found in "<<a[i]->name()<<"!"<<KNRM<<KWHT<<"\n";
				result=false;
			}
			//Save the result, date and time in a file
			fp=fopen(name,"a");
			if(result==true&&execute_copy[i]==true)
				fprintf(fp,"%s executed at %s		Result:Successful\n",func_name,ctime(&ptr));
			else if(result==false&&execute_copy[i]==true)
				fprintf(fp,"%s executed at %s		Result:Failure\n",func_name,ctime(&ptr));
			fclose(fp);
			if(mode=='n'||mode=='N')
			{		
				if(result==false)
				{
					cout<<RED<<"Fault detected."<<KNRM<<KWHT<<"\n";
					cout<<"Do you need any assistance?\n";
					cin>>help_ch;
					if(help_ch=='y'||help_ch=='Y')
					{
						system("google-chrome http://google.com"); //Open google in browser automatically if user needs help
					}
					cout<<"Do you still want to continue?("<<KGRN<<"Y"<<KNRM<<KWHT<<"/"<<KRED<<"N"<<KNRM<<KWHT")\n";
					cin>>choice;
					if(choice=='n'||choice=='N')
					{
						return;
					}			
				}
				else
				{
					cout<<KGRN<<func_name<<" executed successfully"<<KNRM<<KWHT<<"\n";
				}
			}
			result_copy[i]=result;
		}
		else
		{
			if (getuid()) 
    				cout<<KRED<<"You must be a root User to execute "<<a[i]->name()<<KNRM<<KWHT<<endl;
			else
				goto execute;
		}
	}
	
	if(mode=='y'||mode=='Y')
	{
		cout<<"\nResult:\n";
		for(i=0;i<n;i++)
		{
			func_name=a[i]->name();
			if(result_copy[i]==true&&execute_copy[i]==true)
			{
				cout<<KGRN<<func_name<<" executed successfully."<<KNRM<<KWHT<<endl;
			}
			else if(result_copy[i]==false&&execute_copy[i]==true)
			{
				cout<<KRED<<"Fault detected in "<<func_name<<KNRM<<KWHT<<endl;
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
	cout<<"\nPresent Buffer number = "<<bufcount<<"\nDo you want to rivert back to any of your previous code?("<<KGRN<<"Y"<<KWHT<<"/"<<KRED<<"N"<<KWHT")\n";
	cin>>buf_ch;
	if(buf_ch=='y'||buf_ch=='Y')
	{
		cout<<"Enter the Buffer number\n";
		cin>>buf_pos;
		if(buf_pos>bufcount||buf_pos<1)
			cout<<KRED<<"\nInvalid Buffer number"<<KNRM<<KWHT<<"\n";
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
			
			cout<<"Your codes have been riverted\n";

			strcpy(buf_temp2,"gedit ");
			strcat(buf_temp2,current_file);
			system(buf_temp2);
		}	
	} 	
	cout<<"\nHistory has been saved in the file "<<name<<endl;
	cout<<KNRM;
}
