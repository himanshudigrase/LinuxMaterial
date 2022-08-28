//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question: Create a hard link file using the `link` system call

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){

  int l = link(argv[1],argv[2]);

  if(l == 0){
  printf("Hard Link created pointing to the original file");
  }

return 0;
}
