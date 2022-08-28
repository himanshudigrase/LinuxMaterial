//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question : Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argv, char* argc[]){
    int fd;
    char* filename = "./parentchild.txt";
    fd = open(filename,O_RDWR|O_APPEND|O_CREAT);
    if(fd!=-1){
        if(fork())
        write(fd,"This is child\n",13);
        else{
            write(fd,"This is parent\n",14);
        }
    }
     return 0;
}