//Name: Himanshu Shankar Digrase
// ID: MT2022155

/* Question: Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes. 
    1. Check the return value of `lseek` 
    2. Open the file with `od` and check the empty spaces in between the data.
*/

#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

void main(int argc, char *argv[]){

 char *filename;
 int fileDescriptor;
 int offset;
 int writeByteCount;

 if(argc!=2) printf("File not passed");

 else{
    filename = argv[1];
    fileDescriptor = open(filename,O_RDWR);
     
    //lseek is a system call that is used to change the location of the read/write pointer of a file descriptor.
    offset = lseek(fileDescriptor,10,SEEK_SET);
    writeByteCount = write(fileDescriptor,"1234567890",10);
    if(writeByteCount == -1){
    perror("Error while writing");_exit(1);
    }
  
    offset = lseek(fileDescriptor,10,SEEK_CUR);
    writeByteCount = write(fileDescriptor,"1234567890",10);
    if(writeByteCount == -1){
     perror("Error while writing");_exit(1);
    }
   printf("Return value of lseek: %d\n",offset);
   close(fileDescriptor);
 }
}
//od is used to convert the content of input in different formats with octal format as the default format
