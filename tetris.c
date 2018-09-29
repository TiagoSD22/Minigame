#include"tetris.h"

volatile bloco bloco_atual;

void Tetris_LOGO(void){
	int q;
	Zerar_Tela(); 
	//faz o T
	tela[2][1] = 1;
	tela[2][2] = 1;
	tela[2][3] = 1;
	tela[3][2] = 1;
	tela[4][2] = 1;
	tela[5][2] = 1;
	tela[6][2] = 1;
	//faz o E
	tela[2][4] = 1;
	tela[2][5] = 1;
	tela[2][6] = 1;
	tela[3][4] = 1;
	tela[4][4] = 1;
	tela[4][5] = 1;
	tela[4][6] = 1;
	tela[5][4] = 1;
	tela[6][4] = 1;
	tela[6][5] = 1;
	tela[6][6] = 1;
	//faz o T
	tela[7][1] = 1;
	tela[7][2] = 1;
	tela[7][3] = 1;
	tela[8][2] = 1;
	tela[9][2] = 1;
	tela[10][2] = 1;
	tela[11][2] = 1;
	//faz o R
	tela[7][4] = 1;
	tela[7][5] = 1;
	tela[8][4] = 1;
	tela[9][4] = 1;
	tela[10][4] = 1;
	tela[11][4] = 1;
	tela[8][6] = 1;
	tela[9][6] = 1;
	tela[10][5] = 1;
	tela[11][6] = 1;
	//faz o I
	tela[12][1] = 1;
	tela[12][2] = 1;
	tela[12][3] = 1;
	tela[13][2] = 1;
	for(q = 14; q < 17; q++){
		tela[q][2] = 1;
	}
	tela[16][1] = 1;
	tela[16][3] = 1;
	//faz o S
	for(q = 4; q <= 6; q++){
		tela[12][q] = 1;
		tela[16][q] = 1;
	}
	tela[13][4] = 1;
	for(q = 4; q < 7; q++){
		tela[14][q] = 1;
	}
	tela[15][6] = 1;
}

void Tetris_Splash_Screen(void){
	int q,tempo;
	tempo = 40;
	Zerar_Tela();
	//faz o T
	tela[2][1] = 1;
	tela[2][2] = 1;
	tela[2][3] = 1;
	tela[3][2] = 1;
	tela[4][2] = 1;
	tela[5][2] = 1;
	tela[6][2] = 1;
	for(q = 0; q < tempo; q++){
		Mostrar_Tela();
	}
	//faz o E
	tela[2][4] = 1;
	tela[2][5] = 1;
	tela[2][6] = 1;
	tela[3][4] = 1;
	tela[4][4] = 1;
	tela[4][5] = 1;
	tela[4][6] = 1;
	tela[5][4] = 1;
	tela[6][4] = 1;
	tela[6][5] = 1;
	tela[6][6] = 1;
	for(q = 0; q < tempo; q++){
		Mostrar_Tela();
	}
	//faz o T
	tela[7][1] = 1;
	tela[7][2] = 1;
	tela[7][3] = 1;
	tela[8][2] = 1;
	tela[9][2] = 1;
	tela[10][2] = 1;
	tela[11][2] = 1;
	for(q = 0; q < tempo; q++){
		Mostrar_Tela();
	}
	//faz o R
	tela[7][4] = 1;
	tela[7][5] = 1;
	tela[8][4] = 1;
	tela[9][4] = 1;
	tela[10][4] = 1;
	tela[11][4] = 1;
	tela[8][6] = 1;
	tela[9][6] = 1;
	tela[10][5] = 1;
	tela[11][6] = 1;
	for(q = 0; q < tempo; q++){
		Mostrar_Tela();
	}
	//faz o I
	tela[12][1] = 1;
	tela[12][2] = 1;
	tela[12][3] = 1;
	tela[13][2] = 1;
	for(q = 14; q < 17; q++){
		tela[q][2] = 1;
	}
	tela[16][1] = 1;
	tela[16][3] = 1;
	for(q = 0; q < tempo; q++){
		Mostrar_Tela();
	}
	//faz o S
	tela[12][4] = 1;
	tela[12][5] = 1;
	tela[12][6] = 1;
	tela[13][4] = 1;
	for(q = 4; q < 7; q++){
		tela[14][q] = 1;
	}
	tela[15][6] = 1;
	for(q = 4; q < 7; q++){
		tela[16][q] = 1;
	}
	for(q = 0; q < tempo; q++){
		Mostrar_Tela();
	}
	//apaga o S
	tela[12][4] = 0;
	tela[12][5] = 0;
	tela[12][6] = 0;
	tela[13][4] = 0;
	for(q = 4; q < 7; q++){
		tela[14][q] = 0;
	}
	tela[15][6] = 0;
	for(q = 4; q < 7; q++){
		tela[16][q] = 0;
	}
	for(q = 0; q < tempo; q++){
		Mostrar_Tela();
	}
	//apaga o I
	tela[12][1] = 0;
	tela[12][2] = 0;
	tela[12][3] = 0;
	tela[13][2] = 0;
	for(q = 14; q < 17; q++){
		tela[q][2] = 0;
	}
	tela[16][1] = 0;
	tela[16][3] = 0;
	for(q = 0; q < tempo; q++){
		Mostrar_Tela();
	}
	//apaga o R
	tela[7][4] = 0;
	tela[7][5] = 0;
	tela[8][4] = 0;
	tela[9][4] = 0;
	tela[10][4] = 0;
	tela[11][4] = 0;
	tela[8][6] = 0;
	tela[9][6] = 0;
	tela[10][5] = 0;
	tela[11][6] = 0;
	for(q = 0; q < tempo; q++){
		Mostrar_Tela();
	}
	//apaga o T
	tela[7][1] = 0;
	tela[7][2] = 0;
	tela[7][3] = 0;
	tela[8][2] = 0;
	tela[9][2] = 0;
	tela[10][2] = 0;
	tela[11][2] = 0;
	for(q = 0; q < tempo; q++){
		Mostrar_Tela();
	}
	//apaga o E
	tela[2][4] = 0;
	tela[2][5] = 0;
	tela[2][6] = 0;
	tela[3][4] = 0;
	tela[4][4] = 0;
	tela[4][5] = 0;
	tela[4][6] = 0;
	tela[5][4] = 0;
	tela[6][4] = 0;
	tela[6][5] = 0;
	tela[6][6] = 0;
	for(q = 0; q < tempo; q++){
		Mostrar_Tela();
	}
	//apaga o T
	tela[2][1] = 0;
	tela[2][2] = 0;
	tela[2][3] = 0;
	tela[3][2] = 0;
	tela[4][2] = 0;
	tela[5][2] = 0;
	tela[6][2] = 0;
	for(q = 0; q < tempo; q++){
		Mostrar_Tela();
	}
	Zerar_Tela();
}

void Gerar_Peca(void){
	int semente = TMR0H * 100 + TMR0L;
	srand(semente);
	bloco_atual.tipo = (short)rand()%7 + 1;
	switch(bloco_atual.tipo){
		case 1:
			Gerar_Quadrado();
			break;
		case 2:
			Gerar_Reta();
			break;
		case 3:
			Gerar_Z_esq();
			break;
		case 4:
			Gerar_Z_dir();
			break;
		case 5:
			Gerar_T();
			break;
		case 6:
			Gerar_L_esq();
			break;
		case 7:
			Gerar_L_dir();
			break;
		default:
			break;
	}
}

void Gerar_Quadrado(void){
	tela[1][4] = 1;
	tela[1][5] = 1;
	tela[0][4] = 1;
	tela[0][5] = 1;
	bloco_atual.x1 = 0;
	bloco_atual.y1 = 4;
	bloco_atual.x2 = 0;
	bloco_atual.y2 = 5;
	bloco_atual.x3 = 1;
	bloco_atual.y3 = 4;
	bloco_atual.x4 = 1;
	bloco_atual.y4 = 5;
	bloco_atual.orientacao = 0;
}

void Gerar_Reta(void){
	tela[1][0] = 2;
	tela[1][1] = 2;
	tela[1][2] = 2;
	tela[1][3] = 2;
	bloco_atual.x1 = 1;
	bloco_atual.y1 = 0;
	bloco_atual.x2 = 1;
	bloco_atual.y2 = 1;
	bloco_atual.x3 = 1;
	bloco_atual.y3 = 2;
	bloco_atual.x4 = 1;
	bloco_atual.y4 = 3;
	bloco_atual.orientacao = 0;
}

void Gerar_Z_esq(void){
	tela[0][1] = 3;
	tela[0][2] = 3;
	tela[1][2] = 3;
	tela[1][3] = 3;
	bloco_atual.x1 = 0;
	bloco_atual.y1 = 1;
	bloco_atual.x2 = 0;
	bloco_atual.y2 = 2;
	bloco_atual.x3 = 1;
	bloco_atual.y3 = 2;
	bloco_atual.x4 = 1;
	bloco_atual.y4 = 3;
	bloco_atual.orientacao = 0;
}

void Gerar_Z_dir(void){
	tela[0][7] = 4;
	tela[0][6] = 4;
	tela[1][6] = 4;
	tela[1][5] = 4;
	bloco_atual.x1 = 0;
	bloco_atual.y1 = 7;
	bloco_atual.x2 = 0;
	bloco_atual.y2 = 6;
	bloco_atual.x3 = 1;
	bloco_atual.y3 = 6;
	bloco_atual.x4 = 1;
	bloco_atual.y4 = 5;
	bloco_atual.orientacao = 0;
}

void Gerar_T(void){
	tela[0][6] = 5;
	tela[1][5] = 5;
	tela[1][6] = 5;
	tela[1][7] = 5;
	bloco_atual.x1 = 0;
	bloco_atual.y1 = 6;
	bloco_atual.x2 = 1;
	bloco_atual.y2 = 5;
	bloco_atual.x3 = 1;
	bloco_atual.y3 = 6;
	bloco_atual.x4 = 1;
	bloco_atual.y4 = 7;
	bloco_atual.orientacao = 0;
}

void Gerar_L_esq(void){
	tela[0][1] = 6;
	tela[1][1] = 6;
	tela[1][2] = 6;
	tela[1][3] = 6;
	bloco_atual.x1 = 0;
	bloco_atual.y1 = 1;
	bloco_atual.x2 = 1;
	bloco_atual.y2 = 1;
	bloco_atual.x3 = 1;
	bloco_atual.y3 = 2;
	bloco_atual.x4 = 1;
	bloco_atual.y4 = 3;
	bloco_atual.orientacao = 0;
	bloco_atual.tipo = 6;
}

void Gerar_L_dir(void){
	tela[0][7] = 7;
	tela[1][7] = 7;
	tela[1][6] = 7;
	tela[1][5] = 7;
	bloco_atual.x1 = 0;
	bloco_atual.y1 = 7;
	bloco_atual.x2 = 1;
	bloco_atual.y2 = 7;
	bloco_atual.x3 = 1;
	bloco_atual.y3 = 6;
	bloco_atual.x4 = 1;
	bloco_atual.y4 = 5;
	bloco_atual.orientacao = 0;
}

short Pode_Deslocar_Baixo(void){
	short x1,x2,x3,x4,y1,y2,y3,y4;
	x1 = bloco_atual.x1;
	x2 = bloco_atual.x2;
	x3 = bloco_atual.x3;
	x4 = bloco_atual.x4;
	y1 = bloco_atual.y1;
	y2 = bloco_atual.y2;
	y3 = bloco_atual.y3;
	y4 = bloco_atual.y4;
	if(x1 < 17 && x2 < 17 && x3 < 17 && x4 < 17){
		if((tela[x1 + 1][y1] == 0 || tela[x1 + 1][y1] == bloco_atual.tipo) && (tela[x2 + 1][y2] == 0 || tela[x2 + 1][y2] == bloco_atual.tipo) &&
		   (tela[x3 + 1][y3] == 0 || tela[x3 + 1][y3] == bloco_atual.tipo) && (tela[x4 + 1][y4] == 0 || tela[x4 + 1][y4] == bloco_atual.tipo)){
			return 1;
		}
	}
	return 0;
}

void Deslocar_Baixo(void){
	tela[bloco_atual.x1][bloco_atual.y1] = 0;
	tela[bloco_atual.x2][bloco_atual.y2] = 0;
	tela[bloco_atual.x3][bloco_atual.y3] = 0;
	tela[bloco_atual.x4][bloco_atual.y4] = 0;
	bloco_atual.x1++;
	bloco_atual.x2++;
	bloco_atual.x3++;
	bloco_atual.x4++;
	tela[bloco_atual.x1][bloco_atual.y1] = bloco_atual.tipo;
	tela[bloco_atual.x2][bloco_atual.y2] = bloco_atual.tipo;
	tela[bloco_atual.x3][bloco_atual.y3] = bloco_atual.tipo;
	tela[bloco_atual.x4][bloco_atual.y4] = bloco_atual.tipo;
}

short Pode_Deslocar_Esquerda(void){
	short x1,x2,x3,x4,y1,y2,y3,y4;
	x1 = bloco_atual.x1;
	x2 = bloco_atual.x2;
	x3 = bloco_atual.x3;
	x4 = bloco_atual.x4;
	y1 = bloco_atual.y1;
	y2 = bloco_atual.y2;
	y3 = bloco_atual.y3;
	y4 = bloco_atual.y4;
	if(y1 > 0 && y2 > 0 && y3 > 0 && y4 > 0){
		if((tela[x1][y1 - 1] == 0 || tela[x1][y1 - 1] == bloco_atual.tipo) && (tela[x2][y2 - 1] == 0 || tela[x2][y2 - 1] == bloco_atual.tipo) &&
		   (tela[x3][y3 - 1] == 0 || tela[x3][y3 - 1] == bloco_atual.tipo) && (tela[x4][y4 - 1] == 0 || tela[x4][y4 - 1] == bloco_atual.tipo)){
			return 1;
		}
	}
	return 0;
}

void Deslocar_Esquerda(void){
	tela[bloco_atual.x1][bloco_atual.y1] = 0;
	tela[bloco_atual.x2][bloco_atual.y2] = 0;
	tela[bloco_atual.x3][bloco_atual.y3] = 0;
	tela[bloco_atual.x4][bloco_atual.y4] = 0;
	bloco_atual.y1--;
	bloco_atual.y2--;
	bloco_atual.y3--;
	bloco_atual.y4--;
	tela[bloco_atual.x1][bloco_atual.y1] = bloco_atual.tipo;
	tela[bloco_atual.x2][bloco_atual.y2] = bloco_atual.tipo;
	tela[bloco_atual.x3][bloco_atual.y3] = bloco_atual.tipo;
	tela[bloco_atual.x4][bloco_atual.y4] = bloco_atual.tipo;
}

short Pode_Deslocar_Direita(void){
	short x1,x2,x3,x4,y1,y2,y3,y4;
	x1 = bloco_atual.x1;
	x2 = bloco_atual.x2;
	x3 = bloco_atual.x3;
	x4 = bloco_atual.x4;
	y1 = bloco_atual.y1;
	y2 = bloco_atual.y2;
	y3 = bloco_atual.y3;
	y4 = bloco_atual.y4;
	if(y1 < 7 && y2 < 7 && y3 < 7 && y4 < 7){
		if((tela[x1][y1 + 1] == 0 || tela[x1][y1 + 1] == bloco_atual.tipo) && (tela[x2][y2 + 1] == 0 || tela[x2][y2 + 1] == bloco_atual.tipo) &&
		   (tela[x3][y3 + 1] == 0 || tela[x3][y3 + 1] == bloco_atual.tipo) && (tela[x4][y4 + 1] == 0 || tela[x4][y4 + 1] == bloco_atual.tipo)){
			return 1;
		}
	}
	return 0;
}

void Deslocar_Direita(void){
	tela[bloco_atual.x1][bloco_atual.y1] = 0;
	tela[bloco_atual.x2][bloco_atual.y2] = 0;
	tela[bloco_atual.x3][bloco_atual.y3] = 0;
	tela[bloco_atual.x4][bloco_atual.y4] = 0;
	bloco_atual.y1++;
	bloco_atual.y2++;
	bloco_atual.y3++;
	bloco_atual.y4++;
	tela[bloco_atual.x1][bloco_atual.y1] = bloco_atual.tipo;
	tela[bloco_atual.x2][bloco_atual.y2] = bloco_atual.tipo;
	tela[bloco_atual.x3][bloco_atual.y3] = bloco_atual.tipo;
	tela[bloco_atual.x4][bloco_atual.y4] = bloco_atual.tipo;
}

int Pode_Rotacionar(void){
	switch(bloco_atual.tipo){
		case 2:
			return Pode_Rotacionar_R();
			break;
		case 3:
			return Pode_Rotacionar_Z_esq();
			break;
		case 4:
			return Pode_Rotacionar_Z_dir();
			break;
		case 5:
			return Pode_Rotacionar_T();
			break;
		case 6:	
			return Pode_Rotacionar_L_esq();
			break;
		case 7:
			return Pode_Rotacionar_L_dir();
			break;
		default:
			break;
	}
	return 0;
}

void Rotacionar(void){
	switch(bloco_atual.tipo){
		case 1:
			break;
		case 2:
			Rotacionar_R();
			break;
		case 3:
			Rotacionar_Z_esq();
			break;
		case 4:
			Rotacionar_Z_dir();
			break;
		case 5:
			Rotacionar_T();
			break;
		case 6:	
			Rotacionar_L_esq();
			break;
		case 7:
			Rotacionar_L_dir();
			break;
		default:
			break;
	}
}

int Pode_Rotacionar_R(void){
	if(bloco_atual.orientacao == 0){
		if(bloco_atual.x1 > 2  && bloco_atual.x4 < 16){
			if(tela[bloco_atual.x2 - 1][bloco_atual.y2] == 0 && tela[bloco_atual.x2 + 1][bloco_atual.y2] == 0 && tela[bloco_atual.x2 + 2][bloco_atual.y2] == 0){
				return 1;
			}
		}
	}
	else{
		if(bloco_atual.y1 > 0 && bloco_atual.y4 < 6){
			if(tela[bloco_atual.x1 + 1][bloco_atual.y1 - 1] == 0 && tela[bloco_atual.x3 - 1][bloco_atual.y3 + 1] == 0 && tela[bloco_atual.x4 - 2][bloco_atual.y4 + 2] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Rotacionar_R(void){
	tela[bloco_atual.x1][bloco_atual.y1] = 0;
	tela[bloco_atual.x2][bloco_atual.y2] = 0;
	tela[bloco_atual.x3][bloco_atual.y3] = 0;
	tela[bloco_atual.x4][bloco_atual.y4] = 0;
	if(bloco_atual.orientacao == 0){
		bloco_atual.x1--;
		bloco_atual.y1++;
		bloco_atual.x3++;
		bloco_atual.y3--;
		bloco_atual.x4 += 2;
		bloco_atual.y4 -= 2; 
		bloco_atual.orientacao = 1;	
	}
	else{
		bloco_atual.x1++;
		bloco_atual.y1--;
		bloco_atual.x3--;
		bloco_atual.y3++;
		bloco_atual.x4 -= 2;
		bloco_atual.y4 +=2;
		bloco_atual.orientacao = 0;
	}
	tela[bloco_atual.x1][bloco_atual.y1] = 2;
	tela[bloco_atual.x2][bloco_atual.y2] = 2;
	tela[bloco_atual.x3][bloco_atual.y3] = 2;
	tela[bloco_atual.x4][bloco_atual.y4] = 2;
}

int Pode_Rotacionar_Z_esq(void){
	if(bloco_atual.orientacao == 0){
		if(bloco_atual.x1 > 2 && bloco_atual.x4 < 19){
			if(tela[bloco_atual.x3 + 1][bloco_atual.y3] == 0 && tela[bloco_atual.x2][bloco_atual.y2 + 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(bloco_atual.y3 > 0){
			if(tela[bloco_atual.x3 - 1][bloco_atual.y3 - 1] == 0 && tela[bloco_atual.x3 - 1][bloco_atual.y3] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Rotacionar_Z_esq(void){
	tela[bloco_atual.x1][bloco_atual.y1] = 0;
	tela[bloco_atual.x2][bloco_atual.y2] = 0;
	tela[bloco_atual.x3][bloco_atual.y3] = 0;
	tela[bloco_atual.x4][bloco_atual.y4] = 0;
	if(bloco_atual.orientacao == 0){
		bloco_atual.y1 += 2;
		bloco_atual.x2++;
		bloco_atual.y2++;
		bloco_atual.x4++;
		bloco_atual.y4--; 
		bloco_atual.orientacao = 1;	
	}
	else{
		bloco_atual.y1 -= 2;
		bloco_atual.x2--;
		bloco_atual.y2--;
		bloco_atual.x4--;
		bloco_atual.y4++; 
		bloco_atual.orientacao = 0;
	}
	tela[bloco_atual.x1][bloco_atual.y1] = 3;
	tela[bloco_atual.x2][bloco_atual.y2] = 3;
	tela[bloco_atual.x3][bloco_atual.y3] = 3;
	tela[bloco_atual.x4][bloco_atual.y4] = 3;
}

int Pode_Rotacionar_Z_dir(void){
	if(bloco_atual.orientacao == 0){
		if(bloco_atual.x1 > 2 && bloco_atual.x4 < 17){
			if(tela[bloco_atual.x3 - 1][bloco_atual.y3 - 1] == 0 && tela[bloco_atual.x3 + 1][bloco_atual.y3] == 0){
				return 1;
			}
		}
	}
	else{
		if(bloco_atual.y3 < 7){
			if(tela[bloco_atual.x3 - 1][bloco_atual.y3 + 1] == 0 && tela[bloco_atual.x3 - 1][bloco_atual.y3] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Rotacionar_Z_dir(void){
	tela[bloco_atual.x1][bloco_atual.y1] = 0;
	tela[bloco_atual.x2][bloco_atual.y2] = 0;
	tela[bloco_atual.x3][bloco_atual.y3] = 0;
	tela[bloco_atual.x4][bloco_atual.y4] = 0;
	if(bloco_atual.orientacao == 0){
		bloco_atual.y1 -= 2;
		bloco_atual.x2++;
		bloco_atual.y2--;
		bloco_atual.x4++;
		bloco_atual.y4++; 
		bloco_atual.orientacao = 1;	
	}
	else{
		bloco_atual.y1 += 2;
		bloco_atual.x2--;
		bloco_atual.y2++;
		bloco_atual.x4--;
		bloco_atual.y4--; 
		bloco_atual.orientacao = 0;
	}
	tela[bloco_atual.x1][bloco_atual.y1] = 4;
	tela[bloco_atual.x2][bloco_atual.y2] = 4;
	tela[bloco_atual.x3][bloco_atual.y3] = 4;
	tela[bloco_atual.x4][bloco_atual.y4] = 4;
}

int Pode_Rotacionar_T(void){
	if(bloco_atual.orientacao == 0){
		if(bloco_atual.x3 < 17){
			if(tela[bloco_atual.x3 + 1][bloco_atual.y3] == 0){
				return 1;
			}
		}
	}
	else if(bloco_atual.orientacao == 1){
		if(bloco_atual.y3 > 0){
			if(tela[bloco_atual.x3][bloco_atual.y3 - 1] == 0){
				return 1;
			}
		}
	}
	else if(bloco_atual.orientacao == 2){
		if(bloco_atual.x3 > 2){
			if(tela[bloco_atual.x3 - 1][bloco_atual.y3] == 0){
				return 1;
			}
		}
	}
	else{
		if(bloco_atual.y3 < 7){
			if(tela[bloco_atual.x3][bloco_atual.y3 + 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Rotacionar_T(void){
	tela[bloco_atual.x1][bloco_atual.y1] = 0;
	tela[bloco_atual.x2][bloco_atual.y2] = 0;
	tela[bloco_atual.x3][bloco_atual.y3] = 0;
	tela[bloco_atual.x4][bloco_atual.y4] = 0;
	if(bloco_atual.orientacao == 0){
		bloco_atual.x1++;
		bloco_atual.y1++;
		bloco_atual.x2--;
		bloco_atual.y2++;
		bloco_atual.x4++;
		bloco_atual.y4--;
		bloco_atual.orientacao = 1;
	}
	else if(bloco_atual.orientacao == 1){
		bloco_atual.x1++;
		bloco_atual.y1--;
		bloco_atual.x2++;
		bloco_atual.y2++;
		bloco_atual.x4--;
		bloco_atual.y4--;
		bloco_atual.orientacao = 2;
	}
	else if(bloco_atual.orientacao == 2){
		bloco_atual.x1--;
		bloco_atual.y1--;
		bloco_atual.x2++;
		bloco_atual.y2--;
		bloco_atual.x4--;
		bloco_atual.y4++;
		bloco_atual.orientacao = 3;
	}
	else{
		bloco_atual.x1--;
		bloco_atual.y1++;
		bloco_atual.x2--;
		bloco_atual.y2--;
		bloco_atual.x4++;
		bloco_atual.y4++;
		bloco_atual.orientacao = 0;
	}
	tela[bloco_atual.x1][bloco_atual.y1] = 5;
	tela[bloco_atual.x2][bloco_atual.y2] = 5;
	tela[bloco_atual.x3][bloco_atual.y3] = 5;
	tela[bloco_atual.x4][bloco_atual.y4] = 5;
}

int Pode_Rotacionar_L_esq(void){
	if(bloco_atual.orientacao == 0){
		if(bloco_atual.x3 < 17){
			if(tela[bloco_atual.x3 + 1][bloco_atual.y3] == 0 && tela[bloco_atual.x3 - 1][bloco_atual.y3] == 0 && tela[bloco_atual.x3 - 1][bloco_atual.y3 + 1] == 0){
				return 1;
			}
		}
	}
	else if(bloco_atual.orientacao == 1){
		if(bloco_atual.y3 > 0){
			if(tela[bloco_atual.x3][bloco_atual.y3 - 1] == 0 && tela[bloco_atual.x3][bloco_atual.y3 + 1] == 0 && tela[bloco_atual.x3 + 1][bloco_atual.y3 + 1] == 0){
				return 1;
			}
		}
	}
	else if(bloco_atual.orientacao == 2){
		if(bloco_atual.x3 > 2){
			if(tela[bloco_atual.x3 + 1][bloco_atual.y3] == 0 && tela[bloco_atual.x3 + 1][bloco_atual.y3 - 1] == 0 && tela[bloco_atual.x3 - 1][bloco_atual.y3] == 0){
				return 1;
			}
		}
	}
	else{
		if(bloco_atual.y3 < 7){
			if(tela[bloco_atual.x3][bloco_atual.y3 - 1] == 0 && tela[bloco_atual.x3][bloco_atual.y3 + 1] == 0 && tela[bloco_atual.x3 - 1][bloco_atual.y3 - 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Rotacionar_L_esq(void){
	tela[bloco_atual.x1][bloco_atual.y1] = 0;
	tela[bloco_atual.x2][bloco_atual.y2] = 0;
	tela[bloco_atual.x3][bloco_atual.y3] = 0;
	tela[bloco_atual.x4][bloco_atual.y4] = 0;
	if(bloco_atual.orientacao == 0){
		bloco_atual.y1+=2;
		bloco_atual.x2--;
		bloco_atual.y2++;
		bloco_atual.x4++;
		bloco_atual.y4--;
		bloco_atual.orientacao = 1;
	}
	else if(bloco_atual.orientacao == 1){
		bloco_atual.x1+=2;
		bloco_atual.x2++;
		bloco_atual.y2++;
		bloco_atual.x4--;
		bloco_atual.y4--;
		bloco_atual.orientacao = 2;
	}
	else if(bloco_atual.orientacao == 2){
		bloco_atual.y1-=2;
		bloco_atual.x2++;
		bloco_atual.y2--;
		bloco_atual.x4--;
		bloco_atual.y4++;
		bloco_atual.orientacao = 3;
	}
	else{
		bloco_atual.x1-=2;
		bloco_atual.x2--;
		bloco_atual.y2--;
		bloco_atual.x4++;
		bloco_atual.y4++;
		bloco_atual.orientacao = 0;
	}
	tela[bloco_atual.x1][bloco_atual.y1] = 6;
	tela[bloco_atual.x2][bloco_atual.y2] = 6;
	tela[bloco_atual.x3][bloco_atual.y3] = 6;
	tela[bloco_atual.x4][bloco_atual.y4] = 6;
}

int Pode_Rotacionar_L_dir(void){
	if(bloco_atual.orientacao == 0){
		if(bloco_atual.x3 < 17){
			if(tela[bloco_atual.x3 + 1][bloco_atual.y3] == 0 && tela[bloco_atual.x3 + 1][bloco_atual.y3 + 1] == 0 && tela[bloco_atual.x3 - 1][bloco_atual.y3] == 0){
				return 1;
			}
		}
	}
	else if(bloco_atual.orientacao == 1){
		if(bloco_atual.y3 > 0){
			if(tela[bloco_atual.x3][bloco_atual.y3 - 1] == 0 && tela[bloco_atual.x3 + 1][bloco_atual.y3 - 1] == 0 && tela[bloco_atual.x3][bloco_atual.y3 + 1] == 0){
				return 1;
			}
		}
	}
	else if(bloco_atual.orientacao == 2){
		if(bloco_atual.x3 > 2){
			if(tela[bloco_atual.x3 - 1][bloco_atual.y3] == 0 && tela[bloco_atual.x3 + 1][bloco_atual.y3] == 0 && tela[bloco_atual.x3 - 1][bloco_atual.y3 - 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(bloco_atual.y3 < 7){
			if(tela[bloco_atual.x3][bloco_atual.y3 - 1] == 0 && tela[bloco_atual.x3][bloco_atual.y3 + 1] == 0 && tela[bloco_atual.x3 - 1][bloco_atual.y3 + 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Rotacionar_L_dir(void){
	tela[bloco_atual.x1][bloco_atual.y1] = 0;
	tela[bloco_atual.x2][bloco_atual.y2] = 0;
	tela[bloco_atual.x3][bloco_atual.y3] = 0;
	tela[bloco_atual.x4][bloco_atual.y4] = 0;
	if(bloco_atual.orientacao == 0){
		bloco_atual.x1+=2;
		bloco_atual.x2++;
		bloco_atual.y2--;
		bloco_atual.x4--;
		bloco_atual.y4++;
		bloco_atual.orientacao = 1;
	}
	else if(bloco_atual.orientacao == 1){
		bloco_atual.y1-=2;
		bloco_atual.x2--;
		bloco_atual.y2--;
		bloco_atual.x4++;
		bloco_atual.y4++;
		bloco_atual.orientacao = 2;
	}
	else if(bloco_atual.orientacao == 2){
		bloco_atual.x1-=2;
		bloco_atual.x2--;
		bloco_atual.y2++;
		bloco_atual.x4++;
		bloco_atual.y4--;
		bloco_atual.orientacao = 3;
	}
	else{
		bloco_atual.y1+=2;
		bloco_atual.x2++;
		bloco_atual.y2++;
		bloco_atual.x4--;
		bloco_atual.y4--;
		bloco_atual.orientacao = 0;
	}
	tela[bloco_atual.x1][bloco_atual.y1] = 7;
	tela[bloco_atual.x2][bloco_atual.y2] = 7;
	tela[bloco_atual.x3][bloco_atual.y3] = 7;
	tela[bloco_atual.x4][bloco_atual.y4] = 7;
}

void Fixar_Blocos(void){
	short i,j;
	for(i = 2;i < 18; i++){
		for(j = 0; j < 8; j++){
			if(tela[i][j] > 0 && tela[i][j] != 8){
				tela[i][j] = 8;
			}
		}
	}
	while(Existe_Linha_Completa() > 0){
		Limpar_Linhas(Existe_Linha_Completa());
	}
}

short Existe_Linha_Completa(void){
	short i,j,qt;
	for(i = 17; i > 1; i--){
		qt = 0;
		for(j = 0; j < 8; j++){
			if(tela[i][j] > 0){
				qt++;
			}
		}
		if(qt == 8){
			return i;
		}
	}
	return 0;
}

void Limpar_Linhas(short linha){
	short i,j;
	for(i = linha; i > 1; i--){
		for(j = 0; j < 8; j++){
			tela[i][j] = tela[i-1][j];
		}
	}
}

short Tela_Estourou(void){
	int i;
	for(i = 0; i < 8; i++){
		if(tela[1][i] > 0 && tela[2][i] == 8 && tela[3][i] == 8){
			return 1;
		}
	}
	return 0;
}

void Tetris_Game(void){
	Zerar_Tela();
	Gerar_Peca();
}