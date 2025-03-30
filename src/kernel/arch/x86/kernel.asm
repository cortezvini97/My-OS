section .text
    global _start_kernel
    extern main_kernel
    extern system_inportb
    extern system_outportb

_start_kernel:
    call main_kernel
    hlt

system_inportb:
    push ebp
    mov ebp, esp
    mov dx, word [ebp+8]
    in al, dx
    pop ebp
    ret

system_outportb:
    mov dx, word [esp + 4]   
    mov al, byte [esp + 8] 
    out dx, al      
    ret                   
