#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (int argc, char** argv[]) { 
    int n, i;
    n = 5;
    for(i=0; i<n-1; i++){
        pid_t pid = fork();
        if(pid>0)break;
    }
    while(wait(0)!=-1);
    printf("PID=%d, PPID=%d i=%d\n ", getpid(), getppid(), i);
    return 0;
}

/* PID | PPID | i
    97      96  4  
    96      95  3
    95      94  2
    94      93  1
    93      92  0
*/

