#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

//ABAC....

void *hiloA(void*);
void *hiloB(void*);
void *hiloC(void*);

pthread_mutex_t mA = PTHREAD_MUTEX_INITIALIZER; // Sem = 1;
pthread_mutex_t mB = PTHREAD_MUTEX_INITIALIZER; // Sem = 1;
pthread_mutex_t mC = PTHREAD_MUTEX_INITIALIZER; // Sem = 1;
pthread_mutex_t mX = PTHREAD_MUTEX_INITIALIZER; // Sem = 1;

int main(int argc, char** argv){

	pthread_mutex_lock(&mC); // Sem = 0
	pthread_mutex_lock(&mX); // Sem = 0
	pthread_t thA, thB, thC;

	pthread_create(&thA, NULL, hiloA, NULL);
	pthread_create(&thB, NULL, hiloB, NULL);
	pthread_create(&thC, NULL, hiloC, NULL);

	pthread_join(thA, NULL);
	pthread_join(thB, NULL);
	pthread_join(thC, NULL);

	return 0;
}

void *hiloA(void *p){
	while(1){
		pthread_mutex_lock(&mA);
		printf("hiloA\n");
		sleep(1);
		pthread_mutex_unlock(&mX);
	}
}

void *hiloB(void *p){
	while(1){
		pthread_mutex_lock(&mB);
		pthread_mutex_lock(&mX);
		printf("hiloB\n");
		sleep(1);
		pthread_mutex_unlock(&mC);
		pthread_mutex_unlock(&mA);
	}
}

void *hiloC(void *p){
	while(1){
		pthread_mutex_lock(&mC);
		pthread_mutex_lock(&mX);
		printf("hiloC\n");
		sleep(1);
		pthread_mutex_unlock(&mB);
		pthread_mutex_unlock(&mA);
	}
}