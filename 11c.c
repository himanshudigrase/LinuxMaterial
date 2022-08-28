//Name: Himanshu Shankar Digrase
// ID: MT2022155
// Question: Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not using `fcntl`


#include<sys/types.h> //Import for open
#include<sys/stat.h> //Import for open
#include<fcntl.h>    //Import for fcntl system call
#include<unistd.h>   //Import for fcntl
#include<stdio.h>    //Import for perror

void main(int argc, char* argv[]){

 int fd,dfd,writeByCount;
 char *filename;


 if(argc!=2)printf("File name not provided");
 else{
	filename = argv[1];
	fd = open(filename,O_WRONLY|O_APPEND);
	if(fd == -1)perror("Error while opening");
	else{
		dfd = fcntl(fd,F_DUPFD);
		writeByCount = write(fd,"\nUsing fcntl original fd",21);
		if(writeByCount == -1)perror("Error while writing");
		writeByCount = write(dfd,"\n Using fcntl duplicate fd",23);
		if(writeByCount == -1)perror("Error while writing dup");

		close(fd);

	}
    }
}
