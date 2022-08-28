//Name: Himanshu Shankar Digrase
// ID: MT2022155


// Question 21: Write a program, call fork and print the parent and child process id.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    if(fork()){
        printf("Child id :%d\n",getpid());
    }
    else{
        printf("Parent id: %d\n",getpid());
    }
    return 0;
}