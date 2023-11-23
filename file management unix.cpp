#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int file_descriptor;
    char buffer[100];
    ssize_t bytes_read, bytes_written;

    // Create a file or open it if it already exists
    file_descriptor = open("example.txt", O_CREAT | O_RDWR, 0666);
    if (file_descriptor == -1) {
        perror("Error creating/opening the file");
        exit(EXIT_FAILURE);
    }

    // Write content to the file
    char *content = "This is a demonstration of UNIX system calls for file management.";
    bytes_written = write(file_descriptor, content, strlen(content));
    if (bytes_written == -1) {
        perror("Error writing to the file");
        close(file_descriptor);
        exit(EXIT_FAILURE);
    }

    // Move the file cursor to the beginning
    lseek(file_descriptor, 0, SEEK_SET);

    // Read content from the file
    bytes_read = read(file_descriptor, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("Error reading from the file");
        close(file_descriptor);
        exit(EXIT_FAILURE);
    }

    // Null-terminate the buffer to display the content as a string
    buffer[bytes_read] = '\0';
    printf("Content read from the file:\n%s\n", buffer);

    // Close the file
    if (close(file_descriptor) == -1) {
        perror("Error closing the file");
        exit(EXIT_FAILURE);
    }

    // Remove the file
    if (remove("example.txt") == -1) {
        perror("Error removing the file");
        exit(EXIT_FAILURE);
    }

    return 0;
}

