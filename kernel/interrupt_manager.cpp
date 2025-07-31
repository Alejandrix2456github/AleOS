#include "kernel/kernel.h"
#include "kernel/interrupt.h"

void kernel_init() {
    // Initialize interrupt manager
    interrupt_manager_init();

    // Initialize interrupt handlers
    interrupt_handlers = (interrupt_handler_t**)kernel_memory;
}

void kernel_exit() {
    // Deallocate interrupt handlers
    interrupt_handlers = NULL;
}