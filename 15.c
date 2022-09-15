//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question : Write a program to display the environmental variable of the user (use environ).

#include<stdio.h>  // import for NULL, environ


//The variable environ points to an array of pointers to strings
//called the "environment" containing strings such as USER, HOME, PATH, LANG 
extern char **environ;

int isUser(char *var){
 return var[0] == 'U' && var[1] == 'S' && var[4] == '=';
}

void main(){
 int iter = -1;
 while(environ[++iter]!=NULL)
   if(isUser(environ[iter])) printf("%s\n", environ[iter]);
}
