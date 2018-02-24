#include <pthread.h>
#include <unistd.h>  // funciones unix (sleep,read(), write(), etc)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *hilo1(void*);
void *hilo2(void*);
void *hilo3(void*);

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m4 = PHTREAD_MUTEX_INITIALIZER;

int main(int argc,char** argv){

	pthread_mutex_lock(&m3);
	pthread_mutex_lock(&m4);

	pthread_t thr1, thr2, thr3;

	pthread_create(&thr1, NULL, hilo1, NULL);
	pthread_create(&thr2, NULL, hilo2, NULL);
	pthread_create(&thr3, NULL, hilo3, NULL);

	pthread_join(thr1, NULL);
	pthread_join(thr2, NULL);
	pthread_join(thr3, NULL);

	return 0;
}

void *hilo1(void *p){
	while(1){
		pthread_mutex_lock(&m1);
		printf("hilo1\n");
		sleep(1);
		pthread_mutex_unlock(&m4);
	}
	
}

void *hilo2(void* p){
	while(1){
		pthread_mutex_lock(&m2);
		pthread_mutex_lock(&m4)
		printf("hilo2\n");
		sleep(1);
		pthread_mutex_unlock(&m1);
		pthread_mutex_unlock(&m3);
	}
}

void* hilo3(void *p){
	while(1){
		pthread_mutex_lock(&m3);
		pthread_mutex_lock(&m4);
		printf("hilo3\n");
		pthread_mutex_unlock(&m1);
		pthread_mutex_unlock(&m2);

	}
}