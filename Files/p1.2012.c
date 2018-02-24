#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fentl.h>

int main(int argc, char** argv){
    int fd = open("nombreArchivo", O_WRONLY, 600);
    pid_t pid = fork();
    if( pid == 0){
        char letra;
        letra = 'A';
        while(letra <= 'Z'){
            write(fd,&letra,1);
            letra+=2;
        }else{
            wait(NULL);
        }
    }else{
        pid = fork();
        if( pid == 0){
            char letra;
            letra = 'a';
            while(letra <= 'z'){
                write(fd,&letra,1);
                letra+=2;
            }
        }else{
            wait(NULL);
            close(fd);
        }
    }
    return 0;
}