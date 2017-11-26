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
		}
		char const *name()
		{
			return("Build");
		}
		bool privilege()
		{
			return true;
		}				
}ob1;

class job2: public base_job
{
	public:
		bool execute()
		{
			cout<<"Performing local test\n";
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
		}
		char const *name()
		{
			return("Local test");
		}
		bool privilege()
		{
			return true;
		}				

}ob2;

class job3: public base_job
{
	public:
		bool execute()
		{
			cout<<"Performing Deployment test\n";
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
		}
		char const *name()
		{
			return("Deployment test");
		}
		bool privilege()
		{
			return true;
		}				

}ob3;

class job4: public base_job
{
	public:
		bool execute()
		{
			cout<<"Performing Integration test\n";
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
		}
		char const *name()
		{
			return("Integration test");
		}
		bool privilege()
		{
			return true;
		}				

}ob4;

class job5: public base_job
{
	public:
		bool execute()
		{
			cout<<"Deploying to production environment\n";
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
		}
		char const *name()
		{
			return("Deploy to production environment");
		}
		bool privilege()
		{
				return false;
		}				
}ob5;

class job6: public base_job
{
	public:
		bool execute()
		{
			cout<<"Performing Smoke test\n";
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
		}
		char const *name()
		{
			return("Smoke test");
		}
		bool privilege()
		{
			return true;
		}				

}ob6;

int main()
{
	base_job *b[]={&ob1,&ob2,&ob3,&ob4,&ob5,&ob6};
	execute_pipeline(b,6);
	return 0;
}





