//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls


#include<stdio.h>
#include<unistd.h>

int main(){

int count;
char buffer[20];

 count = read(0,buffer,10);
 write(1,buffer,count);

return 0;

}
