#include "stdio.h"
#include "video.h"

void main_kernel(){
    printf("Bem-vindo ao Lyric OS");
    for(int i = 0; i < 4; i++){
        sleep(100000000);
        printf(".");
    }
    clearScreen();
    int a = 20;
    int b = 40;
    int result = a + b;
    printf("Resultado: %d", result);
}