#ifndef KERNEL_H
#define KERNEL_H

#include "keyboard.h"
#include "stdio.h"
#include "shell.h"


void handle_user_input();
void kernelShutdownApi();
void kernelRebootApi();

#endif