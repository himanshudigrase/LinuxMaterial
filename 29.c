//Name: Himanshu Shankar Digrase
// ID: MT2022155
// Question 29: Write a program to get the scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).


#include<sched.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main(){
    int policyCur;
    pid_t pid;
    pid = getpid();

    
    //sched_getscheduler() queries the scheduling policy currently applied to the process identified by pid. 
    //If pid equals zero, the policy of the calling process will be retrieved.
    
    policyCur = sched_getscheduler(pid);
    struct sched_param priority;

    priority.sched_priority = 10; //low priority

    switch(policyCur){
        case SCHED_FIFO:
            printf("Current policy : FIFO\n");
            sched_setscheduler(pid,SCHED_RR,&priority);
            policyCur = sched_getscheduler(pid);
            printf("Current policy: %d\n",policyCur);
            break;

        case SCHED_RR:
            printf("Current policy is RR\n");
            sched_setscheduler(pid,SCHED_FIFO,&priority);
            policyCur = sched_getscheduler(pid);
            printf("Current policy is %d\n",policyCur);
            break;

        case SCHED_OTHER:
            printf("Current policy is OTHER\n");
            sched_setscheduler(pid,SCHED_RR,&priority);
            policyCur = sched_getscheduler(pid);
            printf("Current policy is %d\n",policyCur);
            break;

        default: perror("Error while getting policy");            
    }
}
