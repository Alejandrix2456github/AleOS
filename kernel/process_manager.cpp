#include "kernel/kernel.h"
#include "kernel/process.h"

process_t* process_create(char* name, int priority, int stack_size) {
    // Allocate memory for the process
    process = (process_t*)memory_allocate(stack_size);

    // Initialize process structure
    process->name = name;
    process->priority = priority;
    process->stack_size = stack_size;

    // Add process to process table
    process_table[process_table_size++] = process;

    return process;
}

void process_run(process_t* process) {
    // Start executing the process
    process->pc = process->entry_point;

    // Set process state to running
    process->state = RUNNING;
}

void process_wait(process_t* process) {
    // Wait for the process to exit
    while (process->state != EXITED) {
        // Check if process is running
        if (process->state == RUNNING) {
            // Yield to other processes
            yield();
        }
    }
}