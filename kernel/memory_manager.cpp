#include "kernel/kernel.h"
#include "kernel/memory.h"

void kernel_init() {
    // Initialize memory manager
    memory_manager_init();

    // Allocate memory for the kernel
    kernel_memory = memory_allocate(1024);

    // Initialize process table
    process_table = (process_t**)kernel_memory;
}

void kernel_exit() {
    // Deallocate kernel memory
    memory_deallocate(kernel_memory);

    // Deallocate process table
    process_table = NULL;
}