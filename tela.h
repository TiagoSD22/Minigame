#ifndef __tela_h
#define __tela_h

#include<p18f4685.h>

#pragma udata MATRIZ
extern short tela[18][8];
#pragma udata

void Atrasar(void);
void Zerar_Tela(void);
void Setar_Tela(void);
void Mostrar_Tela(void);
void Piscar_Tela(void);
int Game_Over(void);

#endif