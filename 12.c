//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question: Write a program to find out the opening mode of a file. Use `fcntl`


#include<sys/stat.h>  // for open
#include<sys/types.h>   //for open
#include<fcntl.h>   // for open and fcntl
#include<unistd.h> // for fcntl
#include<stdio.h>  //for perror and printf

void main(int argc, char* argv[]){

	char *filename;
	int fd,status;

	if(argc!=2)printf("Filename not provided");
	else{
		filename = argv[1];
		fd = open(filename,O_RDONLY);

		if(fd == -1)perror("Error while opening");
		else{
			// F_GETFL returns  the file access mode and
              		//the file status flags
		 status = fcntl(fd,F_GETFL);   // f_getfl obtains open flagd for descriptor
		if(status==-1)perror("Error on executing fcntl");
		else{
			
			// O_ACCMODE This macro is a mask that can be bitwise-ANDed with the file status flag value to recover the file access mode
		  switch(O_ACCMODE & status){
			case 0: printf("FIle opened with O_RDONLY");break;
			case 1: printf("File opened with O_WRONLY");break;
			case 2: printf("File opened with O_RDWR");break;
			case 64: printf("File opened with O_CREAT");break;
			case 512: printf("File opened with O_TRUNC");break;
			case 1024: printf("File opened with O_APPEND");break;
			case 577: printf("File opened with O_WRONLY | O_CREAT | O_TRUNC");
			case 1089: printf("File opened with O_WRONLY | O_CREAT | O_APPEND");break;
			case 578: printf("File opened qith O_RDWR | O_CREAT| O_TRUNC");break;
			case 1090: printf("File opened with O_RDWR | O_CREAT | O_APPEND");
			default: printf("Error!");
			}
		}
close(fd);
		}
	}
}
