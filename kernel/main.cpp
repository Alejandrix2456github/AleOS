#include "kernel/kernel.h"
#include "kernel/memory.h"
#include "kernel/process.h"

int main() {
    // Initialize kernel
    kernel_init();

    // Create a new process
    process_t* process = process_create("kernel", 0, 1024);

    // Run the process
    process_run(process);

    // Wait for the process to exit
    process_wait(process);

    // Exit the kernel
    kernel_exit();

    return 0;
}