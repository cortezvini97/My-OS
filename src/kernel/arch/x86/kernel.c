#include "keyboard.h"
#include "stdio.h"

void main_kernel(){
    printf("Bem-vindo ao Lyric OS");
    for(int i = 0; i < 4; i++){
        sleep(100000000);
        printf(".");
    }
    clearScreen();

    string ch = (string) malloc(200);
    int isReboot = 0;
    do {
        ch = keyboardcall();
        printf("\n%s\n", ch);
        if(strEql(ch, "clear")){
            clearScreen();
        }else if(strEql(ch, "shutdown")){
            break;
        }else if(strEql(ch, "reboot")){
            isReboot = 1;
            break;
        }
    }while(1);

    clearScreen();

    if(isReboot){
        printf("Reiniciando o Sistema");
        for(int i = 0; i < 4; i++){
            sleep(100000000);
            printf(".");
        }
        reboot();
    }else {
        printf("Desligando o Sistema");
        for(int i = 0; i < 4; i++){
            sleep(100000000);
            printf(".");
        }
        shutdown();
    }

}