//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).


#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>


void main(){

 fd_set readFDSet, writeFDSet;
 struct timeval time;
 int returnVal;

 FD_SET(STDIN_FILENO, &readFDSet); // Adding STDIN to set of file descriptors to read
 FD_SET(STDOUT_FILENO, &writeFDSet); //Adding STDOUT to write

 time.tv_sec = 10;
 time.tv_usec = 0;

 returnVal = select(1,&readFDSet, &writeFDSet, NULL, &time);

 if(returnVal == -1) perror("ERROR");
 else if(returnVal) printf("Data available");
 else printf("No data given for 10 seconds");

}
