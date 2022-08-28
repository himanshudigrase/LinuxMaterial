//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question 28: Write a program to get maximum and minimum real time priority


#include<sched.h>
#include<stdio.h>

void main(){
    int maxPriority,minPriority;
// for real time use SCHED_RR, SCHED_FIFO
// For non real time use SCHED_OTHER
    maxPriority = sched_get_priority_max(SCHED_RR);
    if(maxPriority == -1)perror("Error while finding max priority");
    else printf("max priority with RR is %d\n",maxPriority);

    minPriority=sched_get_priority_min(SCHED_RR);
    if(minPriority == -1)perror("Error while finding min priority");
    else printf("min priority with RR is %d\n",minPriority);

}