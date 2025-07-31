#include "kernel/kernel.h"
#include "kernel/io_device.h"

void kernel_init() {
    // Initialize I/O manager
    io_manager_init();

    // Initialize console I/O
    console_io_init();
}

void kernel_exit() {
    // Deallocate console I/O resources
    console_io_exit();
}