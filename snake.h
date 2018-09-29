#ifndef __snake_h
#define __snake_h

#include"tela.h"
#include<stdlib.h>

extern volatile short snake_velocidade,cabecax,cabecay,direcao,tamanho,frutax,frutay,game_over_snake;

typedef struct c{
	short valor,x,y;
}celula;

#pragma udata CORPO
extern celula corpo[128];
#pragma udata

void Snake_LOGO(void);
void Snake_MENU(short);
void Desenhar_Numero1(void);
void Desenhar_Numero2(void);
void Desenhar_Numero3(void);
void Retornar_Coordenadas(short,short*,short*);
void Deslocar_Corpo(short, short);
void Deslocar(void);
void Gerar_Fruta(void);
short Existe_Fruta(void);
void Remover_Frutas_Duplicadas(void);
void Crescer_Cobra();
void Snake_Game(short);

#endif