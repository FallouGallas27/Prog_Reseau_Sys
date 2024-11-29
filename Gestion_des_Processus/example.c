#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

sem_t semaphore1; // Semaphore pour contrôler l'exécution de thread_1
sem_t semaphore2; // Semaphore pour contrôler l'exécution de thread_2
int n = 20, i = 0;
pthread_mutex_t mutex;

void *thread_1(void *param) {
    for (int j = 0; j < n; j++) {
        sem_wait(&semaphore1); // Attendre que thread_2 termine
        pthread_mutex_lock(&mutex);
        printf("thread_1: %d\n", i++);
        pthread_mutex_unlock(&mutex);
        sem_post(&semaphore2); // Signaler que thread_1 est terminé
    }
    return NULL;
}

void *thread_2(void *param) {
    for (int j = 0; j < n; j++) {
        sem_wait(&semaphore2); // Attendre que thread_1 termine
        pthread_mutex_lock(&mutex);
        printf("thread_2: %d\n", i--);
        pthread_mutex_unlock(&mutex);
        sem_post(&semaphore1); // Signaler que thread_2 est terminé
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    printf("Utilisation des threads \n");

    // Initialisation des sémaphores
    int err = sem_init(&semaphore1, 0, 1); // semaphore1 commence avec 1 pour que thread_1 commence d'abord
    if (err != 0) {
        printf("\nErreur sem_init :[%d]", err);
        exit(EXIT_FAILURE);
    }

    err = sem_init(&semaphore2, 0, 0); // semaphore2 commence avec 0 pour que thread_2 attende
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

    sem_destroy(&semaphore1);
    sem_destroy(&semaphore2);
    pthread_mutex_destroy(&mutex);

    return EXIT_SUCCESS;
}
