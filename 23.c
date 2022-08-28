//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question : Write a program to create a Zombie state of the running program


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
    int i;
    if(!fork()){
        for(i=0;i<20;i++){
            printf("Child\n");
        }
    }
    else{
        printf("Parent\n");
        while(1);
    }
}