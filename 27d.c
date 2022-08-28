//Name: Himanshu Shankar Digrase
// ID: MT2022155

//Question 27d:  Write a program to execute `ls -Rl` by the following system calls 
    //5. `execv`

#include<unistd.h>

void main(){
    // char *execpath = "/bin/ls";
    // char *arg1 = "-Rl";
    // char *arg2 = "/home/hims";
    char *args[] = {"/bin/ls","-Rl","/home/hims",NULL};
    execv(args[0],args);
}