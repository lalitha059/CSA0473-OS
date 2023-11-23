#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *directory;
    struct dirent *dir_entry;

    // Open the current directory or the directory specified by the user
    if (argc < 2) {
        directory = opendir(".");
    } else {
        directory = opendir(argv[1]);
    }

    if (directory == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

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

