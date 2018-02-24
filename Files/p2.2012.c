#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fentl.h>

void TareaHijo(void);
void TerminarHijo(long);
int EscribirPidEnArchivo(int,long);

int main(int argc, char** argv){
    int fd = open("pids", O_WRONDLY, 600);
    int i, n = atoi(argv[1]);
    for(i == 0, i<n, i++){
        pid_t pid = fork();
        if(pid == 0){
            TareaHijo();
        }else{
            EscribirPidEnArchivo(fd, pid);
        }
    }
    close(fd);
    return 0;
}

    int EscribirPidEnArchivo(int, long){
        char pid[4];
        if(write(fd,pid,4)>0){
            return 0;
        }else{
            return -1;
        }
    }

    void TareaHijo(void){
        while(1){
            sleep(1);
        }
    }

    void TerminarHijo(long pid){
        printf("Termina hijo %d", long pid);
        kill(pid, 9);
    }