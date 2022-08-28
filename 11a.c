//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question: Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not using `dup`



#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

void main(int argc, char *argv[]){
 
 char *filename;
 int fileDescriptor, dupFileDescriptor;
 int writeByteCount;

 if(argc !=2) printf("File not passed");
 else{

 filename = argv[1];
 fileDescriptor = open(filename, O_WRONLY | O_APPEND);
 if(fileDescriptor == -1) perror("Error while opening");
 else{
  dupFileDescriptor = dup(fileDescriptor);
  
  writeByteCount = write(fileDescriptor, "Using original FD",17 );

  writeByteCount = write(dupFileDescriptor,"Using duplicate FD",18);
 if(writeByteCount == -1)perror("Error while writing file using duplicate FD");
 close(fileDescriptor);

 }
 }

}
