//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question : Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.

#include<stdio.h>
#include<fcntl.h>
void main(){
 int fd[5];

 fd[0] = creat("file1.txt",S_IRUSR|S_IRWXU|S_IRGRP|S_IROTH);

  fd[1] = creat("file2.txt",S_IRUSR|S_IRWXU|S_IRGRP|S_IROTH);
 
 fd[2] = creat("file3.txt",S_IRUSR|S_IRWXU|S_IRGRP|S_IROTH);
 fd[3] = creat("file4.txt",S_IRUSR|S_IRWXU|S_IRGRP|S_IROTH);
fd[4] = creat("file5.txt",S_IRUSR|S_IRWXU|S_IRGRP|S_IROTH);
while(1);

}
