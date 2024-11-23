#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include<stdlib.h>
#define NTHREADS 2
sem_t semaphore; int n;
void *thread_1(void * param) {
 for(int j=10;j>=0;j--)
    printf("%d \n",j);
 sem_post(&semaphore);
 return(NULL);
}
void *thread_2(void * param) {
 sem_wait(&semaphore);
  for(int j=1;j<=10;j++)
    printf("%d \n",j);
 return(NULL);
}
int main (int argc, char *argv[]) {
        printf("Utilisation des thread \n");
 pthread_t thread[NTHREADS];
 void * (* func[])(void *)={thread_1, thread_2};
 int err;
 err=sem_init(&semaphore, 0,0);
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
 if(err!=0) {
 printf("\nErreur pthread_join :[%d]", err);
 }
 }
 err=sem_destroy(&semaphore);
 if(err!=0) {
 printf("\nErreur sem_destroy :[%d]", err);
 }
 return(EXIT_SUCCESS);
}

