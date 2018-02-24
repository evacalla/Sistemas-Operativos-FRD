#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void *hiloA(void*);
void *hiloB(void*);

int numero = 1;
int numero2 = 50;

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char **argv){

	pthread_t thA, thB;

	pthread_mutex_lock(&m2);

	pthread_create(&thA, NULL, hiloA, NULL);
	pthread_create(&thB, NULL, hiloB, NULL);

	pthread_join(thA, NULL);
	pthread_join(thB, NULL);

	return 0;
}

void *hiloA(void *p){
	while(numero <= 49){
		pthread_mutex_lock(&m1);
		printf("%d\n", numero );
		sleep(1);
		numero+=1;
		pthread_mutex_unlock(&m2);
	}
}

void *hiloB(void *p){
	while( numero2 <= 100){
		pthread_mutex_lock(&m2);
		printf("%d\n", numero2);
		sleep(1);
		numero2+=1;
		pthread_mutex_unlock(&m1);
	}
}
