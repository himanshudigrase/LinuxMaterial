//Name: Himanshu Shankar Digrase
// ID: MT2022155


/* Question : Write a program to print the following information about a given file - 
    1. Inode 
    2. Number of hard links 
    3. UID 
    4. GID 
    5. Size 
    6. Block size 
    7. Number of blocks 
    8. Time of last access 
    9. Time of last modification 
    10. Time of last change
*/


#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<time.h>

void main(int argc, char *argv[]){

 char *filename;
 int status;

 struct stat fileStat;
 if(argc!=2) printf("FIle name not mentioned");
 else{

  filename = argv[1];
  status=stat(filename,&fileStat);

  if(status == -1) perror("Error while executing");
  else{
      
     printf("Inode -> %ld\n",fileStat.st_ino);
     printf("Number of hardlinks -> %ld\n",fileStat.st_nlink);
     printf("UID -> %d\n",fileStat.st_uid);
     printf("GID ->%d\n",fileStat.st_gid);
     printf("Size -> %ld\n",fileStat.st_size);
     printf("Block SIze -> %ld\n",fileStat.st_blksize);
     printf("Number of Blocks -> %ld\n",fileStat.st_blocks);
     printf("Last Access time -> %s",ctime(&fileStat.st_atim.tv_sec));
     printf("Time of last modification -> %s",ctime(&fileStat.st_mtim.tv_sec));
     printf("Time of last change -> %s", ctime(&fileStat.st_ctim.tv_sec)); 


  }
 }
}
