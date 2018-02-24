#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv){
    pid_t pid = fork();
    if( pid == 0){
        pid = fork();
        if(pid == 0){
            pid = fork();
        }
    }else{
        pid = fork()
    }
    printf("PID = %d, PPID = %d\n", getpid(), getppid());
    wait(NULL);
    wait(NULL);
    return 0;
}