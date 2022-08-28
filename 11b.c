//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question: Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not using `dup2`


#include<unistd.h>  //Import dup2 system call
#include<sys/types.h> //Import for open call
#include<sys/stat.h>  //Import for open
#include<fcntl.h>     //import for open
#include<stdio.h>     //import for perror


void main(int argc, char *argv[]){

	char *filename;
	int fd,dfd;
	int writeByCount;

	if(argc!=2)printf("File name missing");
       else{
		filename = argv[1];
		fd = open(filename, O_WRONLY|O_APPEND);
		if(fd == -1)perror("Error while opening the file");	


		else{
			dfd = dup2(fd,123);
			writeByCount = write(fd,"Original FD",11);
			if(writeByCount == -1)perror("Error while writing");

			writeByCount = write(dfd,"Duplicate fd",12);
			if(writeByCount == -1)perror("Error while dupicate file");


			close(fd);
		}

	}
}
