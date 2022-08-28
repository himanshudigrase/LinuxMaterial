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
 fseek(fp1,0L,SEEK_END);
 pos = ftell(fp1);
 fseek(fp1,0L,SEEK_SET);

 while(pos--){
  ch = fgetc(fp1);
  fputc(ch,fp2);
}
 fclose(fp1);
 fclose(fp2);
}
