# Deployment_Manager
This simple C++ library helps any developer setup a local systematic deployment toolkit for pushing his code changes to production/testing environment.

## Note 
This program is written with limited knowledge of C++ and corporate setup, hence not adviced to be used on complex scenarios.

# How it works?
Developer should be able to write his own job definitions for deployment and this job definitions should be readable/understood by CDPF library.
We will define an interface which developer can use to define their job definition.
We will expose a public deployment_manager class, developer can instantiate this class and make the deployment. Developer has to pass the list jobs to deployment_manager and trigger the deployment.
Deployment_manager will take care of the rest.

# System Architecture
![System Architecture](https://github.com/vkdhanaraj/Deployment_Manager/blob/master/Images/system.png)


# Features
*If thers's any fault Print a message saying fault detected in that particular task (Using concept of exception handling).

*If fault is detected, ask user if he still wants to continue the process or stop. 

*Provides the option to access the internet browser via the program directly incase the user needs any assistance (ie., Open google in the browser automatically if the user needs any help).

*Silent mode: Provides the option to use silent mode.

  1. If silent mode is ON, then the program will directly execute all the tasks and display the result of all the tasks(i.e.,   either executed successfully or fault detected) at once after execution of all the tasks.

  2.  If Silent mode is OFF then, the program displays the results of each task as soon as  each task is executed. 

*History :A File that saves the date and time of execution of each task along with Buffer number and Result.

*Buffer : Every time the user calls (executes) the “execute_pipeline” function, a copy of his current code is saved in different files. Assume that the user called the function 'n' number of times and executed certain pipelines. Now, he wishes to rivert back to his code which was present during the i'th execution of the function. This feature allows the user to do so. 
The codes in the user's current file will be replaced by the codes which were present during the i'th execution (or call) of the “execute_pipeline” function.

*Automatically get the username from the system. Maintain seperate buffer files and history for each user.

*When the access to certain tasks are restricted only to the root user, it checks whether the current user is root user or not. 
  1. If it is root user, then execute the task. 
  2. If not, then an error message is displayed.
