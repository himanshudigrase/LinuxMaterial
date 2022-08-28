//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question: Create a soft link file using the `symlink` system call


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){

  int sl = symlink(argv[1],argv[2]);

  if(sl == 0){
  printf("Soft Link created pointing to the original file");
  }

return 0;
}
