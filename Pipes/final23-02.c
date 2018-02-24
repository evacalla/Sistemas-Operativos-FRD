/*Proceso padre escribe el abecedario en un pipe y 
/*el proceso hijo lee el pipe y 
/*escribe en un archivo llamado abc
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fentl.h>
#include <sys/wait.h>

char letra = 'a';

int main(int argc,char argv[]){
    int fd = OPEN("abc", O_WRONLY, 600);
    int ls[2];
    int pipe(ls);
    pid_t pid = fork();
    if(pid > 0){
        close(pipe[0]);
        while(letra < 'z'){
            write(ls[1], &letra, 1);
            letra += 1;
        }
        wait(0);
    }else{
        close(pipe[1]);
        while(read(ls[0], &letra, 1) != 0){
            write(fd, &letra, 1);
        }
        close(fd);
    }
    return 0;
}