#include "video.h"

int cursorX = 0, cursorY = 0;
const uint8 sw = 80,sh = 30,sd = 2;

int defaultcolor = 0x0F;

void clearLine(uint8 from,uint8 to)
{
    uint16 i = sw * from * sd;
    char* vidmem=(char*)0xb8000;
    for(i;i<(sw*to*sd);i++)
    {
        vidmem[(i / 2)*2 + 1 ] = defaultcolor ;
        vidmem[(i / 2)*2 ] = 0;
    }
}

void clearScreen()
{
    clearLine(0,sh-1);
    cursorX = 0;
    cursorY = 0;
}

void printc(char c, int color){
    string vidmem = (string)0xB8000;

    switch(c)
    {
        case (0x08):
            if(cursorX > 0) 
            {
	            cursorX--;									
                vidmem[(cursorY * sw + cursorX)*sd]=0;	     //(0xF0 & color)                          
	        }
	        break;
        case ('\r'):
            cursorX = 0;
            break;
        case ('\n'):
            cursorX = 0;
            cursorY++;
            break;
        default:
            vidmem [((cursorY * sw + cursorX))*sd] = c;
            vidmem [((cursorY * sw + cursorX))*sd+1] = color;
            cursorX++; 
            break;
    }
}