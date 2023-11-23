#include <stdio.h>
#include <stdint.h>

#define BLOCK_SIZE 8192 // 8 KB in bytes
#define POINTER_SIZE 4   // Size of a pointer to a disk block in bytes

// Inode structure definition
struct Inode {
    uint64_t direct_blocks[12];
    uint64_t single_indirect_block;
    uint64_t double_indirect_block;
    uint64_t triple_indirect_block;
};

// Function to calculate maximum file size
uint64_t calculateMaxFileSize() {
    // Calculate direct, single indirect, double indirect, and triple indirect block sizes
    uint64_t direct_block_size = 12 * BLOCK_SIZE; // 12 direct blocks
    uint64_t single_indirect_size = BLOCK_SIZE / POINTER_SIZE * BLOCK_SIZE; // Single indirect block size
    uint64_t double_indirect_size = BLOCK_SIZE / POINTER_SIZE * single_indirect_size; // Double indirect block size
    uint64_t triple_indirect_size = BLOCK_SIZE / POINTER_SIZE * double_indirect_size; // Triple indirect block size

    // Calculate total size
    uint64_t total_size = direct_block_size +
                          single_indirect_size +
                          double_indirect_size +
                          triple_indirect_size;

    return total_size;
}

int main() {
    uint64_t max_file_size = calculateMaxFileSize();
    printf("Maximum size of a file that can be stored in the file system: %llu bytes\n", max_file_size);

    return 0;
}

