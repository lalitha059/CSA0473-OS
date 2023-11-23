#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate Fibonacci series
void generateFibonacci(int n) {
    int a = 0, b = 1, nextTerm;
    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; ++i) {
        printf("%d, ", a);
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    printf("\n");
}

int main() {
    pid_t pid;
    int n = 10; // Number of Fibonacci series terms to generate

    

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) { // Child process
        generateFibonacci(n);
    } else { // Parent process
        wait(NULL); // Wait for child process to complete
        
        printf("Prime Numbers: ");
        for (int i = 2; i <= n; ++i) {
            if (isPrime(i)) {
                printf("%d, ", i);
            }
        }
        printf("\n");
    }

    return 0;
}

