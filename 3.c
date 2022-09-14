//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question: Write a program to create a file and print the file descriptor value. Use creat() system call

#include<stdio.h>
#include<fcntl.h>

void main(){
// creates a new file and gives r,w,x permission to user and r to others and grp 
 int fd = creat("a.txt",S_IRUSR|S_IRWXU|S_IRGRP|S_IROTH);
 printf("fd = %d\n",fd);
}
