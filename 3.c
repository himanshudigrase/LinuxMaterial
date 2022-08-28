//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question: Write a program to create a file and print the file descriptor value. Use creat() system call

#include<stdio.h>
#include<fcntl.h>

void main(){

 int fd = creat("a.txt",S_IRUSR|S_IRWXU|S_IRGRP|S_IROTH);
 printf("fd = %d\n",fd);
}
