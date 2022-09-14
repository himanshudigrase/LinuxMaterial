//Name: Himanshu Shankar Digrase
// ID: MT2022155


// Question: Write a program to copy file1 into file2 ($cp file1 file2).


#include<stdio.h>

void main(int argc, char **argv){
 FILE *fp1,*fp2;
 char ch;
 int pos;

 if((fp1 = fopen(argv[1],"r")) == NULL){
  printf("\n File can't be opened");
  return;
 }
 else printf("\n File opened for copy");

 fp2 = fopen(argv[2],"w");
 
 //fseek() function sets the file position indicator for the
 // stream pointed to by stream
 
 // In the below command pointer is pointing to eof and moving 0 dist from it.
 
 fseek(fp1,0L,SEEK_END);
 
 //ftell() function obtains the current value of the file
      // position indicator for the stream pointed to by stream
 
 pos = ftell(fp1);
 fseek(fp1,0L,SEEK_SET);
 // seek_set points to start of file

 while(pos--){
  ch = fgetc(fp1);
  fputc(ch,fp2);
}
 fclose(fp1);
 fclose(fp2);
}
