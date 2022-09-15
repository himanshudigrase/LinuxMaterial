//Name: Himanshu Shankar Digrase
// ID: MT2022155


// Question 24: Write a program to create an orphan process

//Orphan processes are those processes that are still running even though their parent process has terminated or finished.


#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
void main(){
    if(fork() == 0){
        printf("parent process id of child: %d\n",(int)getppid());
        sleep(5);
        printf("parent process id of child: %d\n",(int)getppid());
    }
    else{
        sleep(1);
        printf("parent process id  %d\n",(int)getpid());
        exit(0);
    }
  //  return 0;
}
