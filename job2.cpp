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
			cout<<"Performing Build operation\n";	
			wait(4);
			return false;
		}
		char const *name()
		{
			return("Build");
		}				
}ob1;

class job2: public base_job
{
	public:
		bool execute()
		{
			cout<<"Performing local test\n";
			wait(4);
			return true;
		}
		char const *name()
		{
			return("Local test");
		}
}ob2;

class job3: public base_job
{
	public:
		bool execute()
		{
			cout<<"Performing Deployment test\n";
			wait(4);
			return true;
		}
		char const *name()
		{
			return("Deployment test");
		}
}ob3;

class job4: public base_job
{
	public:
		bool execute()
		{
			cout<<"Performing Integration test\n";
			wait(4);
			return false;
		}
		char const *name()
		{
			return("Integration test");
		}
}ob4;

class job5: public base_job
{
	public:
		bool execute()
		{
			cout<<"Deploying to production environment\n";
			wait(4);
			return true;
		}
		char const *name()
		{
			return("Deploy to production environment");
		}
}ob5;

class job6: public base_job
{
	public:
		bool execute()
		{
			cout<<"Performing Smoke test\n";
			wait(4);
			return true;
		}
		char const *name()
		{
			return("Smoke test");
		}

}ob6;

int main()
{
	base_job *b[]={&ob1,&ob2,&ob3,&ob4,&ob5,&ob6};
	execute_pipeline(b,6);
	return 0;
}
