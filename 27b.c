//Name: Himanshu Shankar Digrase
// ID: MT2022155

//Question 27b:  Write a program to execute `ls -Rl` by the following system calls 
    //2. `execlp`

#include<unistd.h>


//duplicate the actions of the shell in searching for an executable file if the specified filename does not contain a slash (/) character.

void main(){
    char *execpath = "/bin/ls";
    char *arg1 = "-Rl";
    char *arg2 = "/home/hims";

        
    execlp(execpath,execpath,arg1,arg2,NULL);
}
