#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main() {
	int p1 = 0;
	int p2 = 0;
	int bolas[16];
	int cont1 = 0;
	int cont2 = 0;
	int i = 0;
	int jogada = 0;
	int jogador = 1;
	int primeirabola = 0;
	int bolajog1 = 2;
	int bolajog2 = 2; 
	int bola8;
	int bola;
	char bolasjogador1[10];
	char bolasjogador2[10];
	
	for(i=0;i<=15;i++){
		bolas[i] = 0;
	}
	
	strcpy(bolasjogador1, "A definir");
	strcpy(bolasjogador2, "A definir");	

	while(cont1<8||cont2<8){
		x:
		system("cls");
		printf("SINUCA LEGENDS!\n\n");
		printf("Jogador 1 (%s): %d\n",bolasjogador1,p1);
		printf("Jogador 2 (%s): %d\n\n",bolasjogador2,p2);
		for(i=1;i<16;i++){
			printf("Bola %d: %d \n",i, bolas[i]);
		}	
		printf("\nVez do jogador %d!\n",jogador);
		system("pause");
		
		bola8 = rand() % 20;
		if(p2 == 7 && jogador == 2){
			if(bola8>=7){
				printf("\nParabens voce errou!\n");
				system("pause");
				jogador = 1;
				goto x;
			}
			else if(bola8<7){
				printf("\nJogador 2 GANHOU AEE!!!\n");
				break;
			}
		}
		
		if(p1 == 7 && jogador == 1){
			if(bola8>=7){
				printf("\nParabens voce errou!\n");
				system("pause");
				jogador=2;
				goto x;
				
			}
			else if(bola8<7){
				printf("\nJogador 1 GANHOU AEE!!!\n");
				break;
			}	
		}
		
		
		jogada = rand() % 30;
		if(jogada>15){
			printf("\nParabens voce nao derrubou nenhuma bola!\n");
			system("pause");
			if(jogador == 1){
				jogador = 2;
			} else if(jogador == 2){
				jogador = 1;
			}
			goto x;
		}else if(primeirabola == 0 && jogada <= 15){
			bola = rand() % (15)+1;
			if(bola > 8){
				printf("\nJogador %d derrubou a bola %d, uma bola maior!\n",jogador ,bola);
				printf("Jogador %d esta jogando com as maiores!\n", jogador);
				system("pause");
				primeirabola++;
				bolas[bola] = 1;
				if(jogador == 1){
					bolajog1 = 1;
					bolajog2 = 0;
					p1++;
					strcpy(bolasjogador1, "Maiores");
					strcpy(bolasjogador2, "Menores");
				}else{
					bolajog2 = 1;
					bolajog1 = 0;
					strcpy(bolasjogador2, "Maiores");
					strcpy(bolasjogador1, "Menores");
					p2++;
				}
			}else if (bola < 8){	
				printf("\nVoce derrubou a bola %d, uma bola menor!\n",bola);
				printf("Jogador %d esta jogando com as menores!\n", jogador);
				system("pause");
				primeirabola++;
				bolas[bola] = 1;
				if(jogador == 1){
					bolajog1 = 0;
					bolajog2 = 1;
					p1++;
					strcpy(bolasjogador2, "Maiores");
					strcpy(bolasjogador1, "Menores");
				}else{
					bolajog1 = 1;
					bolajog2 = 0;
					p2++;
					strcpy(bolasjogador1, "Maiores");
					strcpy(bolasjogador2, "Menores");
				}
			}
		}else if(primeirabola == 1 && jogada <=15){
			r:
			bola = rand() % (15)+1;
			if(bolas[bola] == 0 && bola != 8) {
				printf("\nVoce derrubou a bola %d\n",bola);
				bolas[bola] = 1;
				system("pause");
			}else if(bolas[bola] == 1 && bola != 8){
				goto r;
			}
			if(bolajog1 == 1 && jogador == 1){
				if(bola > 8){
					printf("A bola %d era sua!\n", bola);
					system("pause");
					p1++;								
				}else if(bola < 8){
					printf("A bola %d era do adversario!\n", bola);
					system("pause");
					p2++;
					if(jogador == 1){
						jogador = 2;
					} else if(jogador == 2){
						jogador = 1;
					}
					goto x;
				}
			}
			
			if(bolajog1 == 0 && jogador == 1){
				if(bola < 8){
					printf("A bola %d era sua!\n", bola);
					system("pause");
					p1++;								
				}else if(bola > 8){
					printf("A bola %d era do adversario!\n", bola);
					system("pause");
					p2++;
					if(jogador == 1){
						jogador = 2;
					} else if(jogador == 2){
						jogador = 1;
					}
					goto x;
				}
			}
			
			else if(bolajog2 == 1 && jogador == 2){
				if(bola > 8){
					printf("A bola %d era sua!\n", bola);
					system("pause");
					p2++;								
				}else if(bola < 8){
					printf("A bola %d era do adversario!\n", bola);
					system("pause");
					p1++;
					if(jogador == 1){
						jogador = 2;
					} else if(jogador == 2){
						jogador = 1;
					}
					goto x;
				}
			}
			
			 if(bolajog2 == 0 && jogador == 2){
				if(bola > 8){
					printf("A bola %d era sua!\n", bola);
					system("pause");
					p2++;								
				}else if(bola < 8){
					printf("A bola %d era do adversario!\n", bola);
					system("pause");
					p1++;
					if(jogador == 1){
						jogador = 2;
					} else if(jogador == 2){
						jogador = 1;
					}
					goto x;
				}
			}
		}
	}
}				
