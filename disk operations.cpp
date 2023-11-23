#include <stdio.h>

#define TOTAL_BLOCKS 100

// Function to calculate disk I/O operations for contiguous allocation
int contiguousAllocation(int position) {
    // For contiguous allocation, only one disk I/O operation is needed to update the file allocation table (FAT)
    return 1;
}

// Function to calculate disk I/O operations for linked allocation
int linkedAllocation(int position) {
    // For linked allocation, we need to traverse the linked list till the desired position
    // For each block, one disk I/O operation is needed to read the block address from the FAT
    return position;
}

// Function to calculate disk I/O operations for indexed (single-level) allocation
int indexedAllocation(int position) {
    // For indexed allocation, one disk I/O operation is needed to read the index block from the FAT
    // Then, one additional disk I/O operation is needed to read the block address from the index block
    return 2;
}

int main() {
    int position_beginning = 0;   // Block added at the beginning
    int position_middle = 50;     // Block added in the middle
    int position_end = TOTAL_BLOCKS;  // Block added at the end

    printf("Contiguous Allocation:\n");
    printf("Beginning: %d disk I/O operations\n", contiguousAllocation(position_beginning));
    printf("Middle: %d disk I/O operations\n", contiguousAllocation(position_middle));
    printf("End: %d disk I/O operations\n\n", contiguousAllocation(position_end));

    printf("Linked Allocation:\n");
    printf("Beginning: %d disk I/O operations\n", linkedAllocation(position_beginning));
    printf("Middle: %d disk I/O operations\n", linkedAllocation(position_middle));
    printf("End: %d disk I/O operations\n\n", linkedAllocation(position_end));

    printf("Indexed Allocation (Single-level):\n");
    printf("Beginning: %d disk I/O operations\n", indexedAllocation(position_beginning));
    printf("Middle: %d disk I/O operations\n", indexedAllocation(position_middle));
    printf("End: %d disk I/O operations\n\n", indexedAllocation(position_end));

    return 0;
}

