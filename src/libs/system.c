#include "system.h"

extern uint8 system_inportb(uint16 _port);
extern void system_outportb(uint16 _port, uint8 _data);

uint8 inportb(uint16 port){
    return system_inportb(port);
}

void outportb(uint16 port, uint8 data){
    system_outportb(port, data);
}

int32 write(int fd, const char *buf, uint32 count){
    if (fd != 1) {
        return -1;
    }

    uint32 bytes_written = 0;

    for(uint32 i = 0; i < count; i++){
        printc(buf[i]);
        bytes_written++;
    }

    return bytes_written;
}

void sleep(unsigned int delay) {
    unsigned int i = 0;
    while (1)
    {
        if(i < delay){
            i++;
            continue;
        }
        break;
    }
    
}