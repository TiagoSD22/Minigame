#include"tela.h"

short tela[18][8];

void Atrasar(void){
	short i;
	for(i = 0;i < 140; i++){}
}   

void Zerar_Tela(void){
	int i,j;
	for(i = 0;i < 18; i++){
		for(j = 0;j < 8; j++){
			tela[i][j] = 0;
		}
	}
}

void Setar_Tela(void){
	int i,j;
	for(i = 0;i < 18; i++){
		for(j = 0;j < 8; j++){
			tela[i][j] = 1;
		}
	}
}

void Mostrar_Tela(void){
	short linhas, colunas;
	short coluna[8] = {254,253,251,247,239,223,191,127};
	for(colunas = 0; colunas < 8; colunas++){
		LATA = coluna[colunas];
		LATCbits.LATC0 = tela[17][colunas] && 1;
		LATCbits.LATC1 = tela[16][colunas] && 1;
		LATCbits.LATC2 = tela[15][colunas] && 1;
		LATCbits.LATC3 = tela[14][colunas] && 1; 
		LATCbits.LATC4 = tela[13][colunas] && 1;
		LATCbits.LATC5 = tela[12][colunas] && 1;
		LATEbits.LATE0 = tela[11][colunas] && 1;
		LATEbits.LATE1 = tela[10][colunas] && 1;
		LATDbits.LATD0 = tela[9][colunas] && 1;
		LATDbits.LATD1 = tela[8][colunas] && 1;
		LATDbits.LATD2 = tela[7][colunas] && 1;
		LATDbits.LATD3 = tela[6][colunas] && 1;
		LATDbits.LATD4 = tela[5][colunas] && 1;
		LATDbits.LATD5 = tela[4][colunas] && 1;
		LATDbits.LATD6 = tela[3][colunas] && 1;
		LATDbits.LATD7 = tela[2][colunas] && 1;
		Atrasar();
		LATA = 0b11111111;
		LATCbits.LATC0 = 0;
		LATCbits.LATC1 = 0;
		LATCbits.LATC2 = 0;
		LATCbits.LATC3 = 0;
		LATCbits.LATC4 = 0;
		LATCbits.LATC5 = 0;
		LATEbits.LATE0 = 0;
		LATEbits.LATE1 = 0;
		LATD = 0b00000000;
	}
}

void Piscar_Tela(void){
	int q;
	Zerar_Tela();
	for(q = 0; q < 25; q++){
		Mostrar_Tela();
	}
	Setar_Tela();
	for(q = 0; q < 25; q++){
		Mostrar_Tela();
	}
}

int Game_Over(){
	int i,j,q;
	Zerar_Tela();
	Mostrar_Tela();
	for(i = 17; i >= 2; i--){
		if(i%2== 1){
			for(j = 0; j < 8; j++){
				tela[i][j] = 1;
				Mostrar_Tela();
			}
		}
		else{
			for(j = 7; j >= 0; j--){
				tela[i][j] = 1;
				Mostrar_Tela();
			}
		}
	}
	for(q = 0; q < 4; q++){Piscar_Tela();}
	Zerar_Tela();
	return 0;
}