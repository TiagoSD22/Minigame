#include<delays.h>
#include<math.h>
#include<usart.h>
#include"snake.h"
#include"tetris.h"

#pragma config OSC      = IRCIO67
#pragma config WDT      = OFF, MCLRE = OFF         
#pragma config DEBUG    = ON, LVP = OFF, PWRT = OFF  
#pragma config PBADEN   = OFF   

#pragma udata MATRIZ
short pausado;
volatile short tela_atual;
#pragma udata

void Atualizar_Tela(void){
	if(tela_atual == 0){
		Snake_LOGO();
	}
	if(tela_atual == 1){
		Tetris_LOGO();
	}
	if(tela_atual == 2 || tela_atual == 3 || tela_atual == 4){
		Snake_MENU(tela_atual - 1);
	}
}

void Funcoes_Baixa_Prioridade(void);
void Ler_Bluetooth(void);

#pragma code baixa = 0x18

void baixa(void)
{
	_asm GOTO Funcoes_Baixa_Prioridade _endasm
}
#pragma code

#pragma code alta = 0x08

void alta(void){
	_asm GOTO Ler_Bluetooth _endasm
}

#pragma code

void Rearmar_Timer0(short velocidade){
	if(velocidade == 1){
		TMR0L = 0x96;
		TMR0H = 0xE7;
	}
	if(velocidade == 2){
		TMR0L = 0xCB;
		TMR0H = 0xF3;
	}
	if(velocidade == 3){
		TMR0L = 0xE6;
		TMR0H = 0xF9;
	}
} 

#pragma interrupt Funcoes_Baixa_Prioridade

void Funcoes_Baixa_Prioridade(void)
{
	if (PIR1bits.TMR1IF==1)
	{ 				
		TMR1L=0x66; //valor de recarga para 17ms 60Hz
		TMR1H=0xEF;
		PIR1bits.TMR1IF=0;
		Mostrar_Tela();
	}
	if(INTCONbits.TMR0IF == 1){
		INTCONbits.TMR0IF = 0;
		if(tela_atual == 5){
			Rearmar_Timer0(snake_velocidade);
			if(!pausado){
				Deslocar();
				if(game_over_snake){
					Game_Over();
					Snake_Game(snake_velocidade);
				}
			}
		}
		else{
			if(tela_atual == 6){
				if(!pausado){
					if(Pode_Deslocar_Baixo()){
						Deslocar_Baixo();
						TMR0L = 0x58;
						TMR0H = 0x9E;
					}
					else{
						if(Tela_Estourou()){
							Game_Over();
							Tetris_Game();
						}
						else{
							Fixar_Blocos();
							Gerar_Peca();
							TMR0L = 0x58;
							TMR0H = 0x9E;
						}
					}
				}
			}
		}
	}
}

#pragma interrupt Ler_Bluetooth

void Ler_Bluetooth(void){
	char c;
	if (PIR1bits.RCIF == 1){
		PIR1bits.RCIF = 0;
		c = getcUSART();
		switch(c){
			INTCONbits.TMR0IE = 0;	
			PIE1bits.TMR1IE = 0;
			case 'p':
				pausado = !pausado;
				break;
			case 'b':
				tela_atual = 0;
				Atualizar_Tela();
				break;
			case 'd':
				if(!pausado){
					switch(tela_atual){
						case 0:
							tela_atual = 1;
							break;
						case 1:
							break;
						case 2:
							tela_atual++;
							break;	
						case 3:
							tela_atual++;
							break;
						case 4:
							break;
						case 5:
							if(direcao == 0 || direcao == 1){
								direcao = 2;
								Deslocar();
								Rearmar_Timer0(snake_velocidade);
							}
							break;
						case 6:
							if(Pode_Deslocar_Direita()){
								Deslocar_Direita();
							}
							else{
								if(Tela_Estourou()){
									Game_Over();
									Tetris_Game();
								}
							}
							break;
						default:
							break;
					}
				}
				break;
			case 'a':
				if(!pausado){
					switch(tela_atual){
						case 0:
							break;
						case 1:
							tela_atual--;
							break;
						case 2:
							break;
						case 3:
							tela_atual--;
							break;
						case 4:
							tela_atual--;
							break;
						case 5:
							if(direcao == 0 || direcao == 1){
								direcao = 3;
								Deslocar();
								Rearmar_Timer0(snake_velocidade);
							}
							break;
						case 6:
							if(Pode_Deslocar_Esquerda()){
								Deslocar_Esquerda();
							}
							else{
								if(Tela_Estourou()){
									Game_Over();
									Tetris_Game();
								}
							}
							break;
						default:
							break;
					}
				}
				break;
			case 'w':
				if(!pausado){
					switch(tela_atual){
						case 0:
							tela_atual = 2;
							break;
						case 1:
							Tetris_Splash_Screen();
							Tetris_Game();
							tela_atual = 6;
							TMR0L = 0x58;
							TMR0H = 0x9E;
							break;
						case 2:
							Snake_Game(tela_atual - 1);
							Rearmar_Timer0(snake_velocidade);
							tela_atual = 5;
							break;
						case 3:
							Snake_Game(tela_atual - 1);
							Rearmar_Timer0(snake_velocidade);
							tela_atual = 5;
							break;
						case 4:
							Snake_Game(tela_atual - 1);
							Rearmar_Timer0(snake_velocidade);
							tela_atual = 5;
							break;
						case 5:
							if(direcao == 2 || direcao == 3){
								direcao = 0;
								Deslocar();
								Rearmar_Timer0(snake_velocidade);
							}
							break;
						case 6:
							if(Pode_Rotacionar()){
								Rotacionar();
							}
							break;
						default:
							break;
					}
				}
				break;
			case 's':
				if(!pausado){
					switch(tela_atual){
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							if(direcao == 2 || direcao == 3){
								direcao = 1;
								Deslocar();
								Rearmar_Timer0(snake_velocidade);
							}
							break;
						case 6:
							if(Pode_Deslocar_Baixo()){
								Deslocar_Baixo();
							}
							else{
								if(Tela_Estourou()){
									Game_Over();
									Tetris_Game();
								}
							}
							break;
						default:
							break;
					}
				}
				break;
			default:
				break;
		}
		INTCONbits.TMR0IE = 1;	
		PIE1bits.TMR1IE = 1;
		Atualizar_Tela();
	}
}

void Configurar_PIC(void){
	OSCCON = 0x70;
	ADCON1 = 0x0F;
	TRISB = 0b11000000;
	TRISC = 0b10000000;
	TRISD = 0b00000000;
	TRISA = 0b00000000;
	TRISEbits.TRISE0 = 0;
	TRISEbits.TRISE1 = 0;
	TRISEbits.TRISE2 = 0;
	
	INTCON2bits.TMR0IP=0;
	INTCONbits.TMR0IF=0;
	INTCONbits.TMR0IE=1;	
	T0CON = 0b10000101;				
	
	IPR1bits.TMR1IP = 0;
	PIR1bits.TMR1IF = 0;
	PIE1bits.TMR1IE = 1;
	T1CON = 0b00110001;

	TMR1L=0x66;
	TMR1H=0xEF;

	IPR1bits.RCIP = 1;
	PIR1bits.RCIF = 0;

	RCONbits.IPEN=1;	
	INTCONbits.GIE=1;		
	INTCONbits.GIEL=1;
	INTCONbits.GIEH=1;

	OpenUSART(USART_TX_INT_OFF
			 &USART_RX_INT_ON
			 &USART_ASYNCH_MODE
			 &USART_EIGHT_BIT
			 &USART_BRGH_HIGH,51);//FOSC/(16 * baud) - 1
	
	LATA = 0b11111111;
	LATC = 0b00000000;
	LATD = 0b00000000;

}

void main(void){
	Configurar_PIC();
	tela_atual = 0;
	pausado = 0;
	Atualizar_Tela();
	while(1);
}