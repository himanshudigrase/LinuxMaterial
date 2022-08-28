//Name: Himanshu Shankar Digrase
// ID: MT2022155

/* Question : 26. Write a program to execute an executable program. 
    1. Use some executable program 
    2. Pass some input to an executable program. (for example execute an executable of `$./a.out name`) */

#include<unistd.h>

void main(){
    char *filepath = "/bin/ls";
    char *arg = "/home/hims";

    execl(filepath,filepath,arg,NULL);
}