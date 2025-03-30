bits 32
section .text
    align 4
    dd 0x1BADB002
    dd 0x00
    dd - (0x1BADB002+0x00)

    global start

start:
    cli
    mov word [0xB8000],   0x0748
    hlt