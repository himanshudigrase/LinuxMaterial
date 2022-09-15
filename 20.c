//Name: Himanshu Shankar Digrase
// ID: MT2022155


// Question 20: Find out the priority of your running program. Modify the priority with nice command.



#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void){
    printf("pid =%d\n",getpid());
    chdir("/");
    
    //umask (user file-creation mode) is a Linux command that lets you set up default permissions for newly created files and folders
    umask(777);
    
    //nice command in Linux helps in execution of a program/process with modified scheduling priority.
    nice(-20);
    perror("nice ret:");
    getchar();
}
