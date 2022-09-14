//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls


#include<stdio.h>
#include<unistd.h>

int main(){

int count;
char buffer[20];

 //read sys call reads from a fd
 
 //File descriptor /proc/PID/fd/0 is stdin , /proc/PID/fd/1 is stdout , and /proc/PID/fd/2 is stderr .
 
 count = read(0,buffer,10);
 write(1,buffer,count);

return 0;

}
