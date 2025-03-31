#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "types.h"
#include "system.h"  // Importa a definição de callinportb

#define KEYBOARD_PORT 0x60  // Porta do teclado

uint8 keyboardcall();  // Declaração da função que lê o teclado

#endif // KEYBOARD_H