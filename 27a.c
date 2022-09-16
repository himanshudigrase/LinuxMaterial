//Name: Himanshu Shankar Digrase
// ID: MT2022155

//Question 27a:  Write a program to execute `ls -Rl` by the following system calls 
    //1 `execl`

#include<unistd.h>


// -Rl means recursively use a long listing format

void main(){
    char *execpath = "/bin/ls";
    char *arg1 = "-Rl";
    char *arg2 = "/home/hims";

    execl(execpath,execpath,arg1,arg2,NULL);
}
