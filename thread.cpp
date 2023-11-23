#include <stdio.h>
#include <pthread.h>

#define MAX_COUNT 20 // Maximum number limit for printing even and odd numbers

// Function to print even numbers
void *printEven(void *arg) {
    printf("Even Numbers: ");
    for (int i = 0; i <= MAX_COUNT; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}

// Function to print odd numbers
void *printOdd(void *arg) {
    printf("Odd Numbers: ");
    for (int i = 1; i <= MAX_COUNT; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t tid1, tid2; // Thread IDs

    // Create thread for even numbers
    if (pthread_create(&tid1, NULL, printEven, NULL) != 0) {
        fprintf(stderr, "Failed to create thread for even numbers\n");
        return 1;
    }

    // Create thread for odd numbers
    if (pthread_create(&tid2, NULL, printOdd, NULL) != 0) {
        fprintf(stderr, "Failed to create thread for odd numbers\n");
        return 1;
    }

    // Wait for both threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}

