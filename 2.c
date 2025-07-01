//in jenkins 

1) check maven plugin, git plugin and deploy to container plugin is installed or not
2)decide the maven configuration in the global tool configuration ( maven installation and maven version and install locally ) 
3) + new iten -> deploy the war in tomcat
       freestyle project 
       configure git
       put repo link and branch should be master
4)add timestamp to the console outputs in build environments
5) in build steps click invoke the top level maven commands 
       select maven version and goals as clean install0
6) tomcat configuratioon is done in post build actions (deploy war/ear to  container)
    put war file as **/*.war
    add tomcat container select tomcat version
    select password

take ip address - ipconfig

  build now 
