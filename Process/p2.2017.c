#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (int argc, char** argv[]) { 
    int n, i, status = 0;
    n = 5;
    for(i=0; i<n-1; i++){
        pid_t pid = fork();
        if(pid>0)break;
    }
    while(wait(&status)!=1);
    printf("PID=%d, PPID=%d Status=%d\n ", getpid(), getppid(), status/256);
    return 0;
}

/* PID | PPID | i
    97      96  0  
    96      95  0
    95      94  0
    94      93  0
    93      92  0
*/

