#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct mensaje{
    long tipo;
    char texto[512];
}


int main(int argc, int argv){

    int msgid = msgget(0xA, IPC_CREAT | IPC_EXCL | 0600);
    pid_t pid = fork();

    if(pid > 0){
        struct mensaje envio;
        envio.tipo = 1L;
        do{
            get(envio.mensaje)
            msgsnd(msgid, &envio, 512, 0);
        }while(1);
    }else{
        struct mensaje recivo;
        recivo.tipo = 1L;
        do{
            msgrcv(msgid, &recivo, 512, 1L, 0);
            printf("%ld<%s\n",recibo.tipo,recibo.texto);
        }while(1);
    }
    return 0;
}