#include<bits/stdc++.h>
#include "dev2.cpp"
using namespace std;

//Function to delay execution of next instruction
void wait ( int seconds ) 
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

class job1: public base_job
{
	public:
		bool execute()
		{
<<<<<<< HEAD
			int num;
			time_t t;
			// Declare random number generator 
			srand((unsigned) time(&t));	
			num=rand()%4;
			cout<<"Performing Build operation\n";	
			wait(3);
			if(num==2)
			{	
				throw 0;
				return false;
			}
			else 
				return true;
=======
			cout<<"Performing Build operation\n";	
			wait(4);
			return false;
>>>>>>> 84cd37ff7593e2e0adc8fd35a97c307f83817016
		}
		char const *name()
		{
			return("Build");
<<<<<<< HEAD
		}
		bool privilege()
		{
			return true;
=======
>>>>>>> 84cd37ff7593e2e0adc8fd35a97c307f83817016
		}				
}ob1;

class job2: public base_job
{
	public:
		bool execute()
		{
			cout<<"Performing local test\n";
<<<<<<< HEAD
			int num;
			time_t t;
							// Declare random number generator 
			srand((unsigned) time(&t));	
			num=rand()%4;
			wait(3);
			if(num==2)
			{
				throw 0;
				return false;
			}
=======
			wait(4);
>>>>>>> 84cd37ff7593e2e0adc8fd35a97c307f83817016
			return true;
		}
		char const *name()
		{
			return("Local test");
		}
<<<<<<< HEAD
		bool privilege()
		{
			return true;
		}				

=======
>>>>>>> 84cd37ff7593e2e0adc8fd35a97c307f83817016
}ob2;

class job3: public base_job
{
	public:
		bool execute()
		{
			cout<<"Performing Deployment test\n";
<<<<<<< HEAD
			int num;
			time_t t;
							// Declare random number generator 
			srand((unsigned) time(&t));	
			num=rand()%4;
		
			wait(3);
			if(num==2)
			{
				throw 0;
				return false;
			}
=======
			wait(4);
>>>>>>> 84cd37ff7593e2e0adc8fd35a97c307f83817016
			return true;
		}
		char const *name()
		{
			return("Deployment test");
		}
<<<<<<< HEAD
		bool privilege()
		{
			return true;
		}				

=======
>>>>>>> 84cd37ff7593e2e0adc8fd35a97c307f83817016
}ob3;

class job4: public base_job
{
	public:
		bool execute()
		{
			cout<<"Performing Integration test\n";
<<<<<<< HEAD
			int num;
			time_t t;
							// Declare random number generator 
			srand((unsigned) time(&t));	
			num=rand()%4;
			wait(3);
			if(num==2)
			{
				throw 0;
				return false;
			}
			return true;
=======
			wait(4);
			return false;
>>>>>>> 84cd37ff7593e2e0adc8fd35a97c307f83817016
		}
		char const *name()
		{
			return("Integration test");
		}
<<<<<<< HEAD
		bool privilege()
		{
			return true;
		}				

=======
>>>>>>> 84cd37ff7593e2e0adc8fd35a97c307f83817016
}ob4;

class job5: public base_job
{
	public:
		bool execute()
		{
			cout<<"Deploying to production environment\n";
<<<<<<< HEAD
			int num;
			time_t t;
							// Declare random number generator 
			srand((unsigned) time(&t));	
			num=rand()%4;
			wait(3);
			if(num==2)
			{
				throw 0;
				return false;
			}
=======
			wait(4);
>>>>>>> 84cd37ff7593e2e0adc8fd35a97c307f83817016
			return true;
		}
		char const *name()
		{
			return("Deploy to production environment");
		}
<<<<<<< HEAD
		bool privilege()
		{
				return false;
		}				
=======
>>>>>>> 84cd37ff7593e2e0adc8fd35a97c307f83817016
}ob5;

class job6: public base_job
{
	public:
		bool execute()
		{
			cout<<"Performing Smoke test\n";
<<<<<<< HEAD
			int num;
			time_t t;
							// Declare random number generator 
			srand((unsigned) time(&t));	
			num=rand()%4;
			wait(3);
			if(num==2)
			{
				throw 0;
				return false;
			}
=======
			wait(4);
>>>>>>> 84cd37ff7593e2e0adc8fd35a97c307f83817016
			return true;
		}
		char const *name()
		{
			return("Smoke test");
		}
<<<<<<< HEAD
		bool privilege()
		{
			return true;
		}				
=======
>>>>>>> 84cd37ff7593e2e0adc8fd35a97c307f83817016

}ob6;

int main()
{
	base_job *b[]={&ob1,&ob2,&ob3,&ob4,&ob5,&ob6};
	execute_pipeline(b,6);
	return 0;
}
<<<<<<< HEAD





=======
>>>>>>> 84cd37ff7593e2e0adc8fd35a97c307f83817016
