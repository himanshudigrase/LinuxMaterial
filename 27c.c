//Name: Himanshu Shankar Digrase
// ID: MT2022155

//Question 27c:  Write a program to execute `ls -Rl` by the following system calls 
    //5. `execlp`


#include<unistd.h>

void main(){
    char *execpath = "/bin/ls";
    char *arg1 = "-Rl";
    char *arg2 = "/home/hims";

    execlp(execpath,execpath,arg1,arg2,NULL,NULL); // second null is for environ variable

}