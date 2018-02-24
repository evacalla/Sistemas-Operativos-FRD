#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char** argv){
    int fd[2];
    pipe(fd);
    char letra = 'A';
    while( read(fd[0], &letra, 1) != 0){
        printf("letra [%c]\n", letra);
    }
    while( letra <= 'Z'){
        write(fd[1], &letra, 1);
        letra++;
    }
    return 0;
}

