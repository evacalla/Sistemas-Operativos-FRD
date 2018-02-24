#include <pthread.h>
#include <unistd.h>  // funciones unix (sleep,read(), write(), etc)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *hilo1(void*);
void *hilo2(void*);
void *hilo3(void*);

int variableGlobal = 0;

sem_t s1;

int main(int argc, char** argv){

    sem_init(&s1, 0, 1);

    pthread_t thr1, thr2, thr3;

    pthread_create(&thr1, NULL, hilo1, NULL);
    pthread_create(&thr2, NULL, hilo2, NULL):
    pthread_create(&thr3, NULL, hilo3, NULL);

    pthread_join(thr1, NULL);
    pthread_join(thr2, NULL);
    pthread_join(thr3, NULL);

    sem_destroy(&s1);
    return 0;
}

void *hilo1(void *p){
    int i;
    while(1){
        sem_wait(&s1);
        variableGlobal += 1;
        printf("hilo1, variableGlobal %d\n", variableGlobal);
        sleep(1);
        sem_post(&s1);
    }
}

void *hilo2( void *p){
    int i;
    while(1){
        sem_wait(&s1);
        variableGlobal +=1;
        printf("hilo2, variableGlobal %d\n", variableGlobal);
        sleep(1);
        sem_post(&s1);
    }
}

void *hilo3( void *p){
    int i;
    while(1){
        sem_wait(&s1);
        variableGlobal +=1
        printf("hilo3, variableGlobal %d\n", variableGlobal);
        sleep(1);
        sem_post(&s1);
    }
}