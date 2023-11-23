#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int file_descriptor;
    off_t current_offset;
    struct stat file_info;
    struct dirent *dir_entry;
    DIR *directory;

    // Open a file
    file_descriptor = open("example.txt", O_RDWR | O_CREAT, 0666);
    if (file_descriptor == -1) {
        perror("Error opening/creating the file");
        exit(EXIT_FAILURE);
    }

    // Get current offset in the file
    current_offset = lseek(file_descriptor, 0, SEEK_CUR);
    if (current_offset == -1) {
        perror("Error getting file offset");
        close(file_descriptor);
        exit(EXIT_FAILURE);
    }
    printf("Current offset in the file: %ld\n", (long)current_offset);

    // Get file information
    if (fstat(file_descriptor, &file_info) == -1) {
        perror("Error getting file information");
        close(file_descriptor);
        exit(EXIT_FAILURE);
    }
    printf("File size: %ld bytes\n", (long)file_info.st_size);

    // Close the file
    if (close(file_descriptor) == -1) {
        perror("Error closing the file");
        exit(EXIT_FAILURE);
    }

    // Open a directory
    directory = opendir(".");
    if (directory == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    printf("Files in the current directory:\n");

    // Read directory entries
    while ((dir_entry = readdir(directory)) != NULL) {
        printf("%s\n", dir_entry->d_name);
    }

    // Close the directory
    if (closedir(directory) == -1) {
        perror("Error closing directory");
        exit(EXIT_FAILURE);
    }

    return 0;
}

