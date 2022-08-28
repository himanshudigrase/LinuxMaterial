//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.

#include<stdio.h>
#include<fcntl.h>
int main(){


FILE *file = fopen("neww","r");

 if(!file){
 printf("\n Unable to open file ");
 return -1;
}
 char line[500];
 
 while(fgets(line,sizeof(line),file)) printf("%s",line);

fclose(file);
return 0;
}
