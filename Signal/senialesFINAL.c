#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void enviar_senail(int signo);
void recibir_senail(int signo);

int main(int argc, char** argv){
	signal(SIGUSR1, enviar_senail);
	signal(SIGUSR2, recibir_senail);
	while(kill(getpid(), SIGUSR1) != -1){
		raise(SIGUSR1);
	}
	printf("termino\n");
	return 0;
}

void enviar_senail(int signo){
	printf("enviar SIGUSR1\n");
	raise(SIGUSR2);
}

void recibir_senail(int signo){
	printf("recibir SIGUSR2\n");
}