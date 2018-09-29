#include"snake.h"

volatile short snake_velocidade,cabecax,cabecay,direcao,tamanho,frutax,frutay,game_over_snake;
celula corpo[128];

void Snake_LOGO(void){
	int q;
	Zerar_Tela();
	for(q = 2; q < 6; q++){
		tela[2][q] = 1;
		tela[4][q] = 1;
		tela[6][q] = 1;
	}
	tela[3][2] = 1;
	tela[5][5] = 1;
	for(q = 8; q < 13; q++){
		tela[q][0] = 1;
		tela[q][3] = 1;
		tela[q][4] = 1;
		tela[q][7] = 1;
		tela[q + 5][0] = 1;
		tela[q + 5][5] = 1;
	}
	tela[9][1] = 1;
	tela[10][2] = 1;
	tela[8][5] = 1;
	tela[8][6] = 1;
	tela[10][5] = 1;
	tela[10][6] = 1;
	tela[13][3] = 1;
	tela[14][2] = 1;
	tela[15][1] = 1;
	for(q = 5; q < 8; q++){
		tela[13][q] = 1;
		tela[15][q] = 1;
		tela[17][q] = 1;
	}
	tela[16][2] = 1;
	tela[17][3] = 1;
}

void Desenhar_Numero1(void){
	short j;
	Zerar_Tela();
	for(j = 6; j < 13; j++){
			tela[j][4] = 1;
	}
	tela[7][3] = 1;
	tela[8][2] = 1;
}

void Desenhar_Numero2(void){
	short j;
	Zerar_Tela();
	for(j = 3; j < 6; j++){
		tela[6][j] = 1;
	}	
	tela[7][2] = 1;
	tela[7][6] = 1;
	tela[8][6] = 1;
	tela[9][5] = 1;
	j = 10;
	tela[j][4] = 1;
	j = 11;
	tela[j][3] = 1;
	for(j = 2; j < 7; j++){
		tela[12][j] = 1;
	}
}

void Desenhar_Numero3(void){
	short j;
	Zerar_Tela();
	for(j = 3; j < 6; j++){
		tela[6][j] = 1;
	}	
	tela[7][2] = 1;
	tela[7][6] = 1;
	tela[8][6] = 1;
	for(j = 3; j < 6; j++){
		tela[12][j] = 1;
	}	
	tela[11][2] = 1;
	tela[11][6] = 1;
	tela[10][6] = 1;
	j = 5;
	tela[9][j] = 1;
	j = 4;
	tela[9][j] = 1;
}

void Snake_MENU(short velocidade){
	if(velocidade == 1){
		Desenhar_Numero1();
	}
	else{
		if(velocidade == 2){
			Desenhar_Numero2();
		}
		else{
			Desenhar_Numero3();
		}
	}
}	

void Gerar_Fruta(){
	int i,j;
	srand(TMR0H * 100 + TMR0L);
	i = rand()%16 + 2;
	j = rand()%8;
	frutax = (short)i;
	frutay = (short)j;
	tela[frutax][frutay] = -1;
}

short Existe_Fruta(void){
	int i,j;
	for(i = 2;i < 18; i++){
		for(j = 0;j < 8; j++){
			if(tela[i][j] == -1){
				return  1;
			}	
		}	
	}
	return 0;
}

void Crescer_Cobra(){
	short l,c;
	l = corpo[tamanho - 1].x;
	c = corpo[tamanho - 1].y;
	if(direcao == 0){
		tela[l + 1 + 2][c] = tamanho + 1;
		corpo[tamanho].x = l + 1;
		corpo[tamanho].y = c;
	}
	if(direcao == 1){
		tela[l - 1 + 2][c] = tamanho + 1;
		corpo[tamanho].x = l - 1;
		corpo[tamanho].y = c;
	}
	if(direcao == 2){
		tela[l + 2][c - 1] = tamanho + 1;
		corpo[tamanho].x = l;
		corpo[tamanho].y = c - 1;
	}
	if(direcao == 3){
		tela[l + 2][c + 1] = tamanho + 1;
		corpo[tamanho].x = l;
		corpo[tamanho].y = c + 1;
	}
	tamanho++;
	corpo[tamanho - 1].valor = tamanho;
}

void Remover_Frutas_Duplicadas(void){
	short i,j;
	for(i = 2; i < 18; i++){
		for(j = 0; j < 8; j++){
			if(tela[i][j] == -1 && (i+2 != frutax && j != frutay)){
				tela[i][j] = 0;
			}
		}
	}
}

void Deslocar(){
	short i,cabecax_old,cabecay_old,comeu;
	short x = 2;
	cabecax_old = cabecax;
	cabecay_old = cabecay;
	tela[cabecax + 2][cabecay] = 0;
	comeu = 0;
	if(direcao == 0){
		cabecax--;
		if(cabecax < 0){
			cabecax = 15;
		}
	}
	else if(direcao == 1){
		cabecax++;
		if(cabecax > 15){
			cabecax = 0;
		}
	}
	else if(direcao == 2){
		cabecay++;
		if(cabecay > 7){
			cabecay = 0;
		}
	}
	else{
		cabecay--;
		if(cabecay < 0){
			cabecay = 7;
		}
	}
	if(tela[cabecax + 2][cabecay] > 0){
		game_over_snake = 1;
	}
	if(tela[cabecax + 2][cabecay] == -1){
		Gerar_Fruta();
		Crescer_Cobra();
		comeu = 1;
	}
	tela[cabecax + 2][cabecay] = 1;
	corpo[0].x = cabecax;
	corpo[0].y = cabecay;
	if(tamanho > 1){Deslocar_Corpo(cabecax_old,cabecay_old);}
	if(!Existe_Fruta() && !comeu){
		Gerar_Fruta();
		Remover_Frutas_Duplicadas();
	}
}

void Retornar_Coordenadas(short valor, short* linha, short* coluna){
	*linha = corpo[valor - 1].x;
	*coluna = corpo[valor - 1].y;
}

void Deslocar_Corpo(short cabecax_old, short cabecay_old){
	short i,l,c;	
	Retornar_Coordenadas(tamanho,&l,&c);
	tela[l + 2][c] = 0;
	for(i = tamanho; i > 2; i--){
		Retornar_Coordenadas(i - 1,&l,&c);
		tela[l + 2][c] = i;
		corpo[i - 1].x = corpo[i - 2].x;
		corpo[i - 1].y = corpo[i - 2].y;
	}
	tela[cabecax_old + 2][cabecay_old] = 2;
	corpo[1].x = cabecax_old;
	corpo[1].y = cabecay_old;
}

void Snake_Game(short v){
	Zerar_Tela();
	snake_velocidade = v;
	game_over_snake = 0;
	cabecax = 8;
	cabecay = 4;
	tela[cabecax + 2][cabecay] = 1;
	corpo[0].valor = 1;
	corpo[0].x = 8;
	corpo[0].y = 4;
	tamanho = 1;
	direcao = 0;
	Gerar_Fruta();
}