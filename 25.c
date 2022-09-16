//Name: Himanshu Shankar Digrase
// ID: MT2022155

// Question 25: Write a program to create three child processes. The parent should wait for a particular child (use `waitpid` system call).


#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>

void main(){
    
    //pid_t data type is a signed integer type which is capable of representing a process ID
    pid_t child1, child2, child3, terminatedChild;
    int waitStatus;

    if(child1 = fork()){
        if(child2 = fork()){
            if(child3 = fork()){
                
                //The waitpid() system call suspends execution of the current process until a child specified by pid argument has changed state.
                terminatedChild = waitpid(child3,&waitStatus,0);

                if(terminatedChild == child3){
                    if(waitStatus == 0)printf("Child3 has been terminated with exit status =0 \n");
                    else printf("Child has exited with exit status : %d \n",waitStatus);
                }
            }
            else{
                printf("Child 3 created.. \n");
                printf("Putting child 3 to sleep for 15 secs\n");
                sleep(15);
                printf("Child 3 is now awake!\n");
                _exit(0);
            }
        }
        else{
            printf("Child 2 created .. \n");
            printf("Putting child 2 to sleep for 10 sec\n");
            sleep(10);
            printf("Child 2 is now awake!\n");
            _exit(0);
        }
    }
    else{
        printf("Child 1 created .. \n");
        printf("Putting child 1 to sleep for 5 sec\n");
        sleep(5);
        printf("Child 1 is now awake!\n");
        _exit(0);
    }
}
