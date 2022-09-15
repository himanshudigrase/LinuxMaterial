//Name: Himanshu Shankar Digrase
// ID: MT2022155

/*
Question: Write a program to perform mandatory locking. 
    - Implement write lock 
*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h> //for open
#include<sys/stat.h> // for open
#include<stdio.h>

void main(int argc, char* argv[]){

  char *filename;
	
// Apply or remove an advisory lock on the open file specified by fd
  struct flock lock, lockStatus;
  int fd; //filedescriptor

  if(argc!=2)printf("File name is missing");
  else{

	filename = argv[1];
	
	//Defining file parameters
	lock.l_type = F_WRLCK; //write lock
	lock.l_whence = SEEK_SET; // seek to start of file;
	lock.l_start = 0;         // lock from start of file
	lock.l_len = 0;           //locks the entire file
	lock.l_pid = getpid();

	//copying lock contents, used for checking if a lock has been already placed
	lockStatus = lock;

	//opening a file
	fd = open(filename,O_RDWR);

	//checking file lock status
	fcntl(fd,F_GETLK,&lockStatus);

	if(lockStatus.l_type == F_WRLCK)printf("File already locked for writing");
	else if(lockStatus.l_type == F_RDLCK)printf("File already has reaad lock");
	else{
	 fcntl(fd,F_SETLK,&lock);
	printf("File now locked for writing");

	}
  }
}
