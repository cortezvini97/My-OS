section .text
    global _start_kernel
    extern main_kernel

_start_kernel:
    call main_kernel
    hlt