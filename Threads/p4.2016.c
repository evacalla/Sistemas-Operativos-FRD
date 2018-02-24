#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>

void *hiloA(void*);
void *hiloB(void*);

sem_t mA; 
sem_t mB;

int i, n;

int main(int argc, char **argv){

	int i=0;
	int n=0;

	sem_init(&mA, 0, 1); // pthread_mutex_unblock(&mA)
	sem_init(&mB, 0, 0); // pthread_mutex_lock(&mB)

	pthread_t thA, thB;

	pthread_create(&thA, NULL, hiloA, NULL);
	pthread_create(&thB, NULL, hiloB, NULL);

	pthread_join(thA, NULL);
	pthread_join(thB, NULL);

	printf("Fin\n");
	
	return 0;
}
 
void *hiloA(void *p){
	while(i < 10){
		sem_wait(&mA); // pthread_mutex_lock(&mA)
		printf("Hola ");
		sleep(1);
		i+=1;
		sem_post(&mB); // pthread_mutex_unlock(&mB)
	}
}

void *hiloB(void *p){
	while(n < 10){
		sem_wait(&mB); // pthread_mutex_lock(&mB)
		printf("Mundo\n");
		sleep(1);
		n+=1;
		sem_post(&mA); // pthread_mutex_unlock(&mA)
	}
}