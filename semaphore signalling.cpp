#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_INSTANCES 4
#define NUM_PROCESSES 4

sem_t semaphore;

void* process(void* arg) {
    int process_id = *(int*)arg;

    printf("Process P%d is waiting...\n", process_id);

    // Attempting to acquire the semaphore
    if (sem_wait(&semaphore) == 0) {
        printf("Process P%d acquired the semaphore.\n", process_id);
        sleep(2); // Simulating some work being done by the process
        sem_post(&semaphore); // Releasing the semaphore
        printf("Process P%d released the semaphore.\n", process_id);
    } else {
        printf("Process P%d failed to acquire the semaphore.\n", process_id);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_PROCESSES];
    int process_ids[NUM_PROCESSES] = {1, 2, 3, 4};

    // Initializing the semaphore
    sem_init(&semaphore, 0, NUM_INSTANCES);

    // Creating threads for each process
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        if (pthread_create(&threads[i], NULL, process, &process_ids[i]) != 0) {
            perror("Thread creation failed");
            return EXIT_FAILURE;
        }
    }

    // Waiting for the completion of all threads
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Simulating another process trying to access the resource
    printf("\nAnother process P5 wants the same resource:\n");
    if (sem_trywait(&semaphore) == 0) {
        printf("Process P5 acquired the semaphore.\n");
        sem_post(&semaphore);
        printf("Process P5 released the semaphore.\n");
    } else {
        printf("Process P5 failed to acquire the semaphore.\n");
    }

    // Destroying the semaphore
    sem_destroy(&semaphore);

    return EXIT_SUCCESS;
}

