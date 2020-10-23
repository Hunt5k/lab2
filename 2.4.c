#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void childProcess(){
    char name[30];
    printf("Please Enter Your name : ");
    fgets(name ,30 , stdin);
    printf("Your Name is \n");
    printf("My child process => PPID=%d\n\n", getppid());
    exit(0);
}

void parentProcess(){
    printf("Parent process => PID==%d\n", getpid());
    printf("All child process is finnised!\n");
    printf("Job is done\n");
}

void waiting(){
      printf("waiting for child process to finnish…");
      wait(NULL);
      printf("child process finnished\n");
      printf("------------------------------------------------");
}

int main(void){
    for(int i = 1; i < 5; i++){
	    pid_t pid = fork();
	    if(pid == 0){
	        childProcess();
	    }else if(i == 4){
	        waiting();
	        parentProcess();
                }else waiting();
    }
    return EXIT_SUCCESS;
}
