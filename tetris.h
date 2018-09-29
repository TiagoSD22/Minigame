#ifndef __tetris_h
#define __tetris_h

#include"tela.h"
#include<stdlib.h>

typedef struct b{
	short x1,x2,x3,x4,y1,y2,y3,y4,orientacao,tipo;
}bloco;

extern volatile bloco bloco_atual;

void Tetris_LOGO(void);
void Tetris_Splash_Screen(void);
void Gerar_Peca(void);
void Gerar_Quadrado(void);
void Gerar_Reta(void);
void Gerar_Z_esq(void);
void Gerar_Z_dir(void);
void Gerar_T(void);
void Gerar_L_esq(void);
void Gerar_L_dir(void);
void Fixar_Blocos(void);
short Pode_Deslocar_Baixo(void);
void Deslocar_Baixo(void);
short Pode_Deslocar_Esquerda(void);
void Deslocar_Esquerda(void);
short Pode_Deslocar_Direita(void);
void Deslocar_Direita(void);
int Pode_Rotacionar(void);
int Pode_Rotacionar_R(void);
int Pode_Rotacionar_Z_esq(void);
int Pode_Rotacionar_Z_dir(void);
int Pode_Rotacionar_T(void);
int Pode_Rotacionar_L_esq(void);
int Pode_Rotacionar_L_dir(void);
void Rotacionar(void);
void Rotacionar_R(void);
void Rotacionar_Z_esq(void);
void Rotacionar_Z_dir(void);
void Rotacionar_T(void);
void Rotacionar_L_esq(void);
void Rotacionar_L_dir(void);
short Tela_Estourou(void);
short Existe_Linha_Completa(void);
void Limpar_Linhas(short);
void Tetris_Game(void);

#endif