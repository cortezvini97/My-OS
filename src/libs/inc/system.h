#ifndef SYSTEM_H
#define SYSTEM_H

#include "types.h"
#include "video.h"

uint8 inportb (uint16 _port);
void outportb (uint16 _port, uint8 _data);
int32 write(int fd, const char *buf, uint32 count);
void sleep(unsigned int delay);

#endif