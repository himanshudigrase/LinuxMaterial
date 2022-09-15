//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question : Write a program to create a Zombie state of the running program


// ZOmbie processes that have completed their execution, but their entries are not removed from the process table
//If the parent decides not to wait for the child's termination and executes its subsequent task, then at the termination of the child, the exit status is not read.
//Hence, there remains an entry in the process table even after the termination of the child. This state of the child process is known as the Zombie state.
//ps -eaf check process table for xombie process
// ./a.out defunct shows that it is a zombie process

// we can avoid zombie state by using wait sys call, SIGCHLD signal, by using handler

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
