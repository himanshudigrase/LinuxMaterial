//Name: Himanshu Shankar Digrase
// ID: MT2022155

/* Question : Write a program to find the type of a file. 
    1. Input should be taken from command line. 
    2. Program should be able to identify any type of a file.
*/

#include<sys/types.h> // for stat call
#include<sys/stat.h> // for stat call
#include<unistd.h> // for stat
#include<fcntl.h> // for O_RDONLY
#include<stdio.h> // for printf

void main(int argc, char* argv[]){

    
 // gets status information about a specified file    
 struct stat statbuf;
 int fd;

if(argc!=2)printf("File name not passed");
else{
 fd = open(argv[1],O_RDONLY);
  //gets status information about the object specified by the open descriptor fd
    //and stores the information in the area of memory indicated by the buffer argument(statbuf). 
 fstat(fd,&statbuf);
 
    //The file mode, stored in the st_mode field of the file attributes, contains two kinds of information: the file type code, and the access permission bit
 if(S_ISREG(statbuf.st_mode)) write(STDOUT_FILENO,"Regular File\n",13);
 else if(S_ISDIR(statbuf.st_mode)) write(STDOUT_FILENO,"Directory File\n",15);
else if(S_ISCHR(statbuf.st_mode)) write(STDOUT_FILENO,"Character file\n",15);
else if(S_ISBLK(statbuf.st_mode)) write(STDOUT_FILENO,"Block file\n",11);
else if(S_ISFIFO(statbuf.st_mode)) write(STDOUT_FILENO,"FIFO File\n",10);
else if(S_ISLNK(statbuf.st_mode)) write(STDOUT_FILENO,"Symbolic Link\n",14);
else if(S_ISSOCK(statbuf.st_mode)) write(STDOUT_FILENO,"Socket\n",7);
else write(STDOUT_FILENO,"Error\n",6);
 }
}
