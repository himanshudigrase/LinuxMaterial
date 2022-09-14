//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question: Create a FIFO file using the `mkfifo` library function or `mknod` system call

#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     

void main()
{
    char *mkfifoName = "./mymkfifo";    // File name of FIFO file created using `mkfifo`
    char *mknodName = "./mymknod-fifo"; // File name of FIFO file created using `mknod`

    int mkfifo_status, mknod_status; // 0 -> Success, -1 -> Error
    
    // creates a new fifo / pipe file
    mkfifo_status = mkfifo(mkfifoName, S_IRWXU);

    if (mkfifo_status == -1)
        perror("Error while creating FIFO file!");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");
    
    //You can make a named pipe with it
    //mknod() function creates a new file named by the path name pointed to by path. 
    mkfifo_status = mknod(mknodName, __S_IFIFO | S_IRWXU, 0);

    if (mknod_status == -1)
        perror("Error while creating FIFO file!");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");
}
