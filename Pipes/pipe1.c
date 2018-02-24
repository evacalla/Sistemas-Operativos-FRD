#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char** argv){
    int fd[2];
    pipe(fd);
    if(fork() == 0){
        close(fd[1]);
        char letra;
        while(1){
            printef("Leo [%s], del pid [%d]", read(fd[0], &letra, 1), getpid());
        }
    }else{
        close(fd[0]);
        char letra;
        while(1){
            letra = 'a';
            if(letra <= 'z'){
                write(fd[1], &letra, 1);
                letra += 1;
            }
        }
    }
    return 0;
}