#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char** argv){
    int fd[2];
    pipe(fd);
    char letra = 'a';
    char letraOut;
    while(letra < 'z'){
        write(fd[1], &letra, 1);
        while(read(fd[0], &letraOut, 1) > 0);
        printf("[%c]", letraOut);
        letra++;
    }
    close(fd[0]);
    close(fd[1]);
    return 0;
}

