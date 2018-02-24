#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv){
    char frase[24] = "Hola Querido Mundo 2018";
    int i;
    for(i = 0, i<23; i++){
        pid_t pid = fork();
        if(pid == 0){
            break;
        }
    }
    wait(NULL);
    if( i != 0){
        printf("%d = %c\n", getpid(), frase[23 - i ]);
    }
    return 0;
}