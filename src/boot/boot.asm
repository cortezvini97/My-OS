bits 32
section .text
    align 4
    dd 0x1BADB002
    dd 0x00
    dd - (0x1BADB002+0x00)

    global start
    extern _start_kernel

start:
    cli
    call _start_kernel
    hlt