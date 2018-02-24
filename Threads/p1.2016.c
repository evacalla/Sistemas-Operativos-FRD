#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void *hilo1(void*);
void *hilo2(void*);

char letraminus = 'z';
char letramayus = 'B';

int main(int argc, char **argv){

	pthread_t thA, thB;

	pthread_create(&thA, NULL, hilo1, NULL);
	pthread_create(&thB, NULL, hilo2, NULL);

	pthread_join(thA, NULL);
	pthread_join(thB, NULL);

	return 0;
}

void *hilo1( void *p){
	while(letraminus <= 'z'){
		printf("%c\n", letraminus);
		letraminus += 2;
	}
}

void *hilo2( void *p){
	while(letramayus <= 'Z'){
		printf("%c\n", letramayus );
		letramayus += 2;
	}
}
