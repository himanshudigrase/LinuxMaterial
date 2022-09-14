//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question: Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory.



#include<stdio.h>

int main(){

while(1)
	printf("1");

return 0;
}

//after running this program compile it and run ./a.out &, which will give us process id
//Now go to /proc directory and ls and check whether our process is is present or not.
	//if yes then cat /proc/id/status which will give us status and info about our process

