#include "keyboard.h"

uint8 keyboardcall() {
    char buff;
    string buffstr = (string) malloc(200);
    uint8 i = 0;
    uint8 reading = 1;
    while(reading){
        if(inportb(0x64) & 0x1){
            switch(inportb(KEYBOARD_PORT)){
                case 2:
                    printc('1');
                    buffstr[i] = '1';
                    i++;
                    break;
                case 3:
                    printc('2');
                    buffstr[i] = '2';
                    i++;
                    break;
                case 4:
                    printc('3');
                    buffstr[i] = '3';
                    i++;
                    break;
                case 5:
                    printc('4');
                    buffstr[i] = '4';
                    i++;
                    break;
                case 6:
                    printc('5');
                    buffstr[i] = '5';
                    i++;
                    break;
                case 7:
                    printc('6');
                    buffstr[i] = '6';
                    i++;
                    break;
                case 8:
                    printc('7');
                    buffstr[i] = '7';
                    i++;
                        break;
                case 9:
                    printc('8');
                    buffstr[i] = '8';
                    i++;
                    break;
                case 10:
                    printc('9');
                    buffstr[i] = '9';
                    i++;
                    break;
                case 11:
                    printc('0');
                    buffstr[i] = '0';
                    i++;
                    break;
                case 12:
                    printc('-');
                    buffstr[i] = '-';
                    i++;
                    break;
                case 13:
                    printc('=');
                    buffstr[i] = '=';
                    i++;
                    break;
                case 14:
                    printc('\b');
                    i--;
                    if(i<0)
                    {
                        i = 0;
                    }
                    buffstr[i+1] = 0;
                    buffstr[i] = 0;
                    break;
                /* case 15:
                    printc('\t');          Tab button
                    buffstr[i] = '\t';
                    i++;
                    break;*/
                case 16:
                    printc('q');
                    buffstr[i] = 'q';
                    i++;
                    break;
                case 17:
                    printc('w');
                    buffstr[i] = 'w';
                    i++;
                    break;
                case 18:
                    printc('e');
                    buffstr[i] = 'e';
                    i++;
                    break;
                case 19:
                    printc('r');
                    buffstr[i] = 'r';
                    i++;
                    break;
                case 20:
                    printc('t');
                    buffstr[i] = 't';
                    i++;
                    break;
                case 21:
                    printc('y');
                    buffstr[i] = 'y';
                    i++;
                    break;
                case 22:
                    printc('u');
                    buffstr[i] = 'u';
                    i++;
                    break;
                case 23:
                    printc('i');
                    buffstr[i] = 'i';
                    i++;
                    break;
                case 24:
                    printc('o');
                    buffstr[i] = 'o';
                    i++;
                    break;
                case 25:
                    printc('p');
                    buffstr[i] = 'p';
                    i++;
                    break;
                case 26:
                    printc('[');
                    buffstr[i] = '[';
                    i++;
                    break;
                case 27:
                    printc(']');
                    buffstr[i] = ']';
                    i++;
                    break;
                case 28:
                    //printc('\n');
                    //buffstr[i] = '\n';
                    i++;
                    reading = 0;
                    break;
            /*  case 29:
                        printc('q');           Left Control
                        buffstr[i] = 'q';
                        i++;
                        break;*/
                case 30:
                    printc('a');
                    buffstr[i] = 'a';
                    i++;
                    break;
                case 31:
                    printc('s');
                    buffstr[i] = 's';
                    i++;
                    break;
                case 32:
                    printc('d');
                    buffstr[i] = 'd';
                    i++;
                    break;
                case 33:
                    printc('f');
                    buffstr[i] = 'f';
                    i++;
                    break;
                case 34:
                    printc('g');
                    buffstr[i] = 'g';
                    i++;
                    break;
                case 35:
                    printc('h');
                    buffstr[i] = 'h';
                    i++;
                    break;
                case 36:
                    printc('j');
                    buffstr[i] = 'j';
                    i++;
                    break;
                case 37:
                    printc('k');
                    buffstr[i] = 'k';
                    i++;
                    break;
                case 38:
                    printc('l');
                    buffstr[i] = 'l';
                    i++;
                    break;
                case 39:
                    printc(';');
                    buffstr[i] = ';';
                    i++;
                    break;
                case 40:
                    printc((char)44);               //   Single quote (')
                    buffstr[i] = (char)44;
                    i++;
                    break;
                case 41:
                    printc((char)44);               // Back tick (`)
                    buffstr[i] = (char)44;
                    i++;
                    break;
            /* case 42:                                 Left shift 
                    printc('q');
                    buffstr[i] = 'q';
                    i++;
                    break;
                case 43:                                 \ (< for somekeyboards)   
                    printc((char)92);
                    buffstr[i] = 'q';
                    i++;
                    break;*/
                case 44:
                    printc('z');
                    buffstr[i] = 'z';
                    i++;
                    break;
                case 45:
                    printc('x');
                    buffstr[i] = 'x';
                    i++;
                    break;
                case 46:
                    printc('c');
                    buffstr[i] = 'c';
                    i++;
                    break;
                case 47:
                    printc('v');
                    buffstr[i] = 'v';
                    i++;
                    break;                
                case 48:
                    printc('b');
                    buffstr[i] = 'b';
                    i++;
                    break;               
                case 49:
                    printc('n');
                    buffstr[i] = 'n';
                    i++;
                    break;                
                case 50:
                    printc('m');
                    buffstr[i] = 'm';
                    i++;
                    break;               
                case 51:
                    printc(',');
                    buffstr[i] = ',';
                    i++;
                    break;                
                case 52:
                    printc('.');
                    buffstr[i] = '.';
                    i++;
                    break;            
                case 53:
                    printc('/');
                    buffstr[i] = '/';
                    i++;
                    break;            
                case 54:
                    printc('.');
                    buffstr[i] = '.';
                    i++;
                    break;            
                case 55:
                    printc('/');
                    buffstr[i] = '/';
                    i++;
                    break;            
                /*case 56:
                        printc(' ');           Right shift
                        buffstr[i] = ' ';
                        i++;
                        break;*/           
                case 57:
                    printc(' ');
                    buffstr[i] = ' ';
                    i++;
                    break;
            }
        }
    }
    buffstr[i-1] = 0;                
    return buffstr;
}