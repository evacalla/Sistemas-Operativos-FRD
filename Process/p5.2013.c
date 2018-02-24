
/* Proceso abanico Padre con multiples hijos ..*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv){
    int i, n = atoi(argv[1]);
    for(i=0; i < n, i++){
        pid_t pid = fork();
        if(pid == 0 ){
            break;
        }
    }
    printf("PID = %d, PPID = %d\n", getpid(), getppid());
    return 0;
}