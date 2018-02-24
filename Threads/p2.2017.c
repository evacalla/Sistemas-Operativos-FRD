#include <pthread.h>
#include <unistd.h>  // funciones unix (sleep,read(), write(), etc)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *hilo1(void*);
void *hilo2(void*);
/* hilo2- hilo1 */
sem_t s1;
sem_t s2;

int variableGlobal = 0;

int main(int argc, char** argv){

    sem_init(&s1, 0 , 0);
    sem_init(&s2, 0 , 1);

    pthread_t thr1, thr2;

    pthread_create(&thr1, NULL, hilo1, NULL);
    pthread_create(&thr2, NULL, hilo2, NULL);

    pthread_join(thr1, NULL);
    pthread_join(thr2, NULL);

    sem_destroy(&s1);
    sem_destroy(&s2);

    return 0;
}

void *hilo1( void *p){
    while(1){
        sem_wait(&s1);
        if( variableGlobal == 20){
            sem_post(&s2);
            break;
        }
        variableGlobal += 1;
        printf("hilo1, variableGlobal %d\n", variableGlobal);
        sleep(1);
        sem_post(&s2);
    }
}

void *hilo2( void *p){
    while(1){
        sem_wait(&s2);
        if( variableGlobal == 20){
            sem_post(&s1);
            break;
        }
        variableGlobal += 1;
        printf("hilo2, variableGlobal%d\n", variableGlobal);
        sleep(1);
        sem_post(&s1);
    }
}