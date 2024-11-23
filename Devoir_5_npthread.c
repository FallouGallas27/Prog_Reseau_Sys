#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#define NTHREADS 6
sem_t sem1,sem2,sem3,sem4,sem5,sem6;
void *thread1(void * param) {
    while(1){
    sem_wait(&sem1);
    printf("Thread1\n");
    sem_post(&sem2);
    }
    pthread_exit(NULL);
}
void *thread2(void * param) {
    while(1){
    sem_wait(&sem2);
    printf("Thread2\n");
    sem_post(&sem3);
    }
    pthread_exit(NULL);
}
void *thread3(void * param) {
    while(1){
    sem_wait(&sem3);
    printf("Thread3\n");
    sem_post(&sem4);
    }
    pthread_exit(NULL);
}
void *thread4(void * param) {
    while(1){
    sem_wait(&sem4);
    printf("Thread4\n");
    sem_post(&sem5);
    }
    pthread_exit(NULL);
}
void *thread5(void * param) {
    while(1){
    sem_wait(&sem5);
    printf("Thread5\n");
    sem_post(&sem6);
    }
    pthread_exit(NULL);
}
void *thread6(void * param) {
    while(1){
    sem_wait(&sem6);
    printf("Thread6\n\n");
    sem_post(&sem1);
    }
    pthread_exit(NULL);
}
int main (int argc, char *argv[]) {
 pthread_t thread[NTHREADS];
 void * (* func[])(void *)={thread1,thread2,thread3,thread4,thread5,thread6};
 int err;
 err=sem_init(&sem1, 0,1);
 if (err != 0)
 printf("\nErreur sem_init :[%d]", err);
 err=sem_init(&sem2, 0,0);
 if (err != 0)
 printf("\nErreur sem_init :[%d]", err);
err=sem_init(&sem3, 0,0);
 if (err != 0)
 printf("\nErreur sem_init :[%d]", err);
err=sem_init(&sem4, 0,0);
 if (err != 0)
 printf("\nErreur sem_init :[%d]", err);

err=sem_init(&sem5, 0,0);
 if (err != 0)
 printf("\nErreur sem_init :[%d]", err);
err=sem_init(&sem6, 0,0);
 if (err != 0)
 printf("\nErreur sem_init :[%d]", err);

 for(int i=0;i<NTHREADS;i++) {
 err=pthread_create(&(thread[i]),NULL,func[i],NULL);
 if (err != 0) {
 printf("\nErreur de création du thread :[%d]", err);
 }
 }
for(int i=0;i<NTHREADS;i++) {
 err=pthread_join(thread[i],NULL);
 if(err!=0)
{
 printf("\nErreur pthread_join :[%d]", err);
 }
 }
 err=sem_destroy(&sem1);
 if(err!=0) {
 printf("\nErreur sem_destroy :[%d]", err);
 }
 err=sem_destroy(&sem2);
 if(err!=0) {
 printf("\nErreur sem_destroy :[%d]", err);
 }
err=sem_destroy(&sem3);
 if(err!=0) {
 printf("\nErreur sem_destroy :[%d]", err);
 }
 err=sem_destroy(&sem4);
 if(err!=0) {
 printf("\nErreur sem_destroy :[%d]", err);
 }
 err=sem_destroy(&sem5);
 if(err!=0) {
 printf("\nErreur sem_destroy :[%d]", err);
 }
err=sem_destroy(&sem6);
 if(err!=0) {
 printf("\nErreur sem_destroy :[%d]", err);
 }

 return(EXIT_SUCCESS);
}
