#include "video.h"

void main_kernel(){
    printc('H', 0x04);  // Vermelho
    printc('e', 0x02);  // Verde
    printc('l', 0x06);  // Amarelo
    printc('l', 0x01);  // Azul
    printc('o', 0x05);  // Roxo
    printc(' ', 0x07);  // Cinza claro (espaço)
    printc('W', 0x03);  // Ciano
    printc('o', 0x0A);  // Verde claro
    printc('r', 0x0C);  // Vermelho claro
    printc('l', 0x0E);  // Amarelo claro
    printc('d', 0x0F);  // Branco brilhante
    clearScreen();
    printc('H', 0x0F);
    printc('e', 0x0F); 
    printc('l', 0x0F);
    printc('l', 0x0F);
    printc('o', 0x0F);  
}