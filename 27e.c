//Name: Himanshu Shankar Digrase
// ID: MT2022155

//Question 27e:  Write a program to execute `ls -Rl` by the following system calls 
    //5. `execvp`

#include<unistd.h>

void main(){
    // char *execpath = "/bin/ls";
    // char *arg1 = "-Rl";
    // char *arg2 = "/home/hims";
    char *args[] = {"/bin/ls","-Rl","/home/hims",NULL};
    
    execvp(args[0],args);
}