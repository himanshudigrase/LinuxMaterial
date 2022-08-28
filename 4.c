//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question : Write a program to open an existing file with read write mode. Try O_EXCL flag also.


#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

extern int errno;
// This program runs for the first time. If file is not created then it creates
// a new file and if file already exists then it throws error mentioning
// File already exists




int main(){
  int fd = open("new.txt",O_RDWR|O_CREAT|O_EXCL);
  
 printf("fd = %d\n",fd);

if(fd == -1){

printf("Error number %d\n",errno);
perror("Program");

}
return 0;
}
