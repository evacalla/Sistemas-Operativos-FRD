
/* Proceso con profundidad & anchura ..*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (int argc, char**argv[]) { 
    int i, n; 
    int profundidad, anchura;
    profundidad= atoi(argv[1]); /*profundidad*/
    anchura= atoi(argv[2]); /*anchura*/
    for(i= 0; i < profundidad; i++){
        pid_t pid = fork();
        if(pid > 0){
            break;
        }
    }
    for(n= 0; n< anchura; n++){
        pid_t pid = fork();
        if(pid == 0){
            break;
        }
    }
    printf("Soy el proceso%d y mi padre es%d\n", getpid(), getppid()); 
    sleep (2); 
    return 0;
}