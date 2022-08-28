//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question 19: Write a program to find out time taken to execute getpid system call. Use time stamp counter.


#include<sys/time.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
unsigned long long rdtsc(){
    unsigned long long dst;
    __asm__ __volatile__("rdtsc":"=A"(dst));
    return dst;
}

int main(){
    long long int start,end;
    start = rdtsc();
    for(int i=0;i<9;i++)getpid();

    end = rdtsc();

    printf("Difference is: %llu\n",end-start);
return 0;
}