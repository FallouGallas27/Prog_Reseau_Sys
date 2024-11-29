#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

sem_t sem1,sem2;
int n = 20, i = 0;
pthread_mutex_t mutex;

void *thread_1(void *param) {
    while(1){
        sem_wait(&sem1);
        while(i<=n){
            printf("%d         NaN\n", i++);}
         sem_post(&sem2);

    }
   pthread_exit(NULL);
}

void *thread_2(void *param) {
    while(1){
        sem_wait(&sem2);
        while(i>0){
        printf("NaN         %d\n", --i);}
        sem_post(&sem1);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    printf("Utilisation des threads \n");
    pthread_t th1,th2;
    int err = sem_init(&sem1, 0, 1);
    if (err != 0) {
        printf("\nErreur sem_init :", err);
        exit(EXIT_FAILURE);
    }
     err = sem_init(&sem2, 0, 0);
    if (err != 0) {
        printf("\nErreur sem_init :", err);
        exit(EXIT_FAILURE);
    }
    err=pthread_create(&th1,NULL,thread_1,(void*)NULL);
    if(err==-1){
        perror("Erreur de lancement \n");
        return 0;
    }
     err=pthread_create(&th1,NULL,thread_2,(void*)NULL);
    if(err==-1){
        perror("Erreur de lancement \n");
        return 0;
    }
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
}
