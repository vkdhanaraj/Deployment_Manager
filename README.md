# Deployment_Manager
This simple C++ library helps any developer setup a local systematic deployment toolkit for pushing his code changes to production/testing environment.

## Note 
This program is written with limited knowledge of C++ and corporate setup, hence not adviced to be used on complex scenarios.

# How it works?
Developer should be able to write his own job definitions for deployment and this job definitions should be readable/understood by CDPF library.
We will define an interface which developer can use to define their job definition.
We will expose a public deployment_manager class, developer can instantiate this class and make the deployment. Developer has to pass the list jobs to deployment_manager and trigger the deployment.
Deployment_manager will take care of the rest.
