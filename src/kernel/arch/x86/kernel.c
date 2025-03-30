#include "types.h"

void main_kernel(){
    string vidmen = (string)0xB8000;
    vidmen[0] = 'H';
    vidmen[1] = 0x07;
    vidmen[2] = 'e';
    vidmen[3] = 0x07;
    vidmen[4] = 'l';
    vidmen[5] = 0x07;
    vidmen[6] = 'l';
    vidmen[7] = 0x07;
    vidmen[8] = 'o';
    vidmen[9] = 0x07;
    vidmen[10] = ' ';
    vidmen[11] = 0x07;
    vidmen[12] = 'W';
    vidmen[13] = 0x07;
    vidmen[14] = 'o';
    vidmen[15] = 0x07;
    vidmen[16] = 'r';
    vidmen[17] = 0x07;
    vidmen[18] = 'l';
    vidmen[19] = 0x07;
    vidmen[20] = 'd';
    vidmen[21] = 0x07;
}