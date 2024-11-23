#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

sem_t semaphore;
int n = 20, i = 0;
pthread_mutex_t mutex;

void *thread_1(void *param) {
    for (int j = 0; j < n; j++) {
        pthread_mutex_lock(&mutex);
        printf(": %d\n", i++);
        pthread_mutex_unlock(&mutex);
    }
         sem_post(&semaphore);
   return NULL;
}

void *thread_2(void *param) {
         sem_wait(&semaphore);
    for (int j = 0; j < n; j++) {
        pthread_mutex_lock(&mutex);
        printf(": %d\n", i--);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    printf("Utilisation des threads \n");

    int err = sem_init(&semaphore, 0, 0);
    if (err != 0) {
        printf("\nErreur sem_init :[%d]", err);
        exit(EXIT_FAILURE);
    }

    pthread_mutex_init(&mutex, NULL);

    pthread_t thread[2];
    void *(*func[])(void *) = {thread_1, thread_2};

    for (int i = 0; i < 2; i++) {
        err = pthread_create(&(thread[i]), NULL, func[i], NULL);
        if (err != 0) {
            printf("\nErreur de création du thread :[%d]", err);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 2; i++) {
        err = pthread_join(thread[i], NULL);
        if (err != 0) {
            printf("\nErreur pthread_join :[%d]", err);
            exit(EXIT_FAILURE);
        }
    }

    sem_destroy(&semaphore);
    pthread_mutex_destroy(&mutex);

    return EXIT_SUCCESS;
}

