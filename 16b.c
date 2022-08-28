//Name: Himanshu Shankar Digrase
// ID: MT2022155

/*
Question: Write a program to perform mandatory locking. 
    - Implement read lock 
*/

#include<unistd.h> // import for fcntl 
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
void main(int argc, char* argv[]){

  char *filename;
  struct flock lock,lockStatus;
  int fd;

  if(argc!=2)printf("Filename not passed");
  else{
	filename = argv[1];
	lock.l_type = F_RDLCK;
	lock.l_type = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();

	lockStatus  = lock;

	fd = open(filename,O_RDONLY);
	fcntl(fd,F_GETLK,&lockStatus);

	if(lockStatus.l_type == F_WRLCK)printf("File already locked for writing");
	else if(lockStatus.l_type == F_RDLCK)printf("File alrady locked for reading");
	else{
		fcntl(fd,F_SETLK,&lock);
		printf("File now locked for reading");

	}
  }
}
