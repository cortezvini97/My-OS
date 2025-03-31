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

    do {
        ch = keyboardcall();
        printf("\n%s\n", ch);
        if(strEql(ch, "clear")){
            clearScreen();
        }
    }while(1);
}