//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question: Create a hard link file using the `link` system call

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){

  //If we create a hard link to the file and then delete the file, we can still access the file using hard link. 
  //But if we create a soft link of the file and then delete the file, we can’t access the file through soft link and soft link becomes dangling.
  //Basically hard link increases reference count of a location while soft links work as a shortcu
  
  int l = link(argv[1],argv[2]);

  if(l == 0){
  printf("Hard Link created pointing to the original file");
  }

return 0;
}
