#include "keyboard.h"
#include "stdio.h"
#include "shell.h"

void main_kernel(){
    printf("Bem-vindo ao Lyric OS");
    for(int i = 0; i < 4; i++){
        sleep(100000000);
        printf(".");
    }
    clearScreen();

    launch_shell(0, "LYRICOS");

    
}

void handle_user_input(){
    clearScreen();

    printf("Precione Enter para iniciar o Shell\n");
    printf("Precione 'a' para Desligar\n");
    printf("Precione 'b' para reiniciar\n");

    while (1)
    {
        if(inportb(0x64) & 0x1){
            switch (inportb(0x60))
            {
                case 28:
                    clearScreen();
                    launch_shell(0, "LYRICOS");
                    break;
                
                case 30:
                    clearScreen();
                    kernelShutdownApi();
                    break;
                case 48:
                clearScreen();
                    
                    break;
                break; 
            }
        }
    }
}

void kernelShutdownApi(){
    printf("Desligando o Sistema");
    for(int i = 0; i < 4; i++){
        sleep(100000000);
        printf(".");
    }
    shutdown();
}

void kernelRebootApi(){
    printf("Reiniciando o Sistema");
    for(int i = 0; i < 4; i++){
        sleep(100000000);
        printf(".");
    }
    reboot();
}