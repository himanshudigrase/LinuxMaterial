//Name: Himanshu Shankar Digrase
// ID: MT2022155

/* Question : 26. Write a program to execute an executable program. 
    1. Use some executable program 
    2. Pass some input to an executable program. (for example execute an executable of `$./a.out name`) */

#include<unistd.h>

//The exec family of functions replaces the current running process with a new process. 
//It can be used to run a C program by using another C program


void main(){
    char *filepath = "/bin/ls";
    char *arg = "/home/hims";
 
    //takes the path of the executable binary file (i.e. /bin/ls) as the first and second argument.
    execl(filepath,filepath,arg,NULL);
}
