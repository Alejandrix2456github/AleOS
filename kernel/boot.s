; kernel/boot.S
; This is the entry point from GRUB.

.section .multiboot_header
.align 4
.long 0x1BADB002         ; Multiboot magic number
.long 0x00000000         ; Flags (page align, memory info)
.long -(0x1BADB002 + 0x00000000) ; Checksum

.section .text
.global _start           ; The linker needs to know our entry point

_start:
    ; Disable interrupts (important for early kernel setup)
    cli

    ; Initialize stack pointer (usually pointing to some uninitialized memory)
    ; For now, we'll just set it to a temporary location.
    ; A proper kernel would set up a proper stack in a known memory region.
    mov $0x80000, %esp ; A temporary stack, way above kernel code

    ; Call the C++ kernel_main function
    call kernel_main

    ; If kernel_main ever returns (it shouldn't in a real OS),
    ; we'll just halt the CPU.
    hlt_loop:
        hlt
        jmp hlt_loop