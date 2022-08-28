//Name: Himanshu Shankar Digrase
// ID: MT2022155


// Question : Write a program to simulate online ticket reservations. Implement a write lock.  Write a program to open a file, store a ticket number, and exit.  Write a separate program, to open the file,  implement write lock, read the ticket number, increment the number, and print the new ticket number then close the file


#include<unistd.h>	//for fcntl, write,lseek
#include<fcntl.h>	//for fcntl
#include<sys/types.h>	//for open, lseek
#include<sys/stat.h>	//for open
#include<stdio.h>	//for printf and perror

void main(int argc, char* argv[]){

  char *filename = "./ticket-file.txt";
  int fd, fcntlStatus;
  ssize_t readBytes, writeBytes;
  off_t lseekOffset;
  int buffer;
  struct flock ticketLock;

  fd = open(filename,O_CREAT | O_RDWR,S_IRWXU);
 if(fd == -1)perror("Error while opening");
  else{
	ticketLock.l_type = F_WRLCK;
	ticketLock.l_pid = getpid();
	ticketLock.l_whence = SEEK_SET;
	ticketLock.l_len = 0;
	ticketLock.l_start = 0;

	fcntlStatus = fcntl(fd,F_GETLK,&ticketLock);

	if(fcntlStatus == -1)perror("Error while getting lock status");
	else{
		switch(ticketLock.l_type)
		{
		case F_WRLCK:
			printf("File alrady locked for writing");break;
		case F_RDLCK:
			printf("File already locked for rading");break;
		default:
			ticketLock.l_type = F_WRLCK;
			fcntlStatus = fcntl(fd,F_SETLKW,&ticketLock);
			if(fcntlStatus == -1)perror("Error while locking ticket file");
			else{
			  readBytes = read(fd,&buffer,sizeof(int));
			  if(readBytes == -1)perror("Error while reading ticket!");
			  else if(readBytes == 0){
				buffer = 1;
				writeBytes = write(fd,&buffer,sizeof(int));
				if(writeBytes == -1)perror("Error while writing to ticket");
				else printf("Your ticket number is %d\n",buffer);

			  }
			  else{
				lseekOffset = lseek(fd,0,SEEK_SET);
				if(lseekOffset == -1)perror("Error while seeking");
				else{
				  buffer+=1;
				  writeBytes = write(fd,&buffer,sizeof(int));
				  printf("Your ticket number is %d\n",buffer);
				}
			  }
			  ticketLock.l_type = F_UNLCK;
			  fcntlStatus = fcntl(fd,F_SETLKW,&ticketLock);
			  if(fcntlStatus == -1)perror("Error releadsing lock");
			  else printf("Done\n");
			}

		}


	}

close(fd);

  } 



}
