#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Variaveis
int estado[10];
char alfabeto[10];
int pos = 0;
int posfita = 1;
int nEstados = 0;
int nAlfabeto = 0;
int numtrans = 0;
int op;
int flag = 0;
string fita;
int cont = 0;
int qEstado = 0; 
int q = 0;

struct transicao{ // Struct para fazer a transição
		int estOrigem;
		int estDestino;
		char ler;
		char escrever;
		int mov;
	};

struct transicao transicao[20];


int main(){
	
	system("color 06");
	
	// Contadores
	int i = 0;
	int j = 0;
	
	for(i = 0; i < 10; i++){ // Iniciar todos os estados zerados
		estado[i] = 0;
	}
	
	printf("Quantidade de estados: ");
	scanf(" %d", &nEstados);
	printf("Estados: ");
	for(i = 0; i < nEstados; i++){
		printf("Q%i ", q);
		q++;	
	}
	printf("\n\n");
	system("pause");
	for(i = 0; i < nEstados; i++){ // Definir como 1 todos os estados selecionados
		estado[i] = 1;
	}
	system("cls");
	printf("Tamanho do alfabeto: ");
	scanf(" %d", &nAlfabeto);
	
	for(i = 1; i <= nAlfabeto; i++){
		system("cls");
		printf("Digite a letra do alfabeto: ");
		scanf(" %c", &alfabeto[i]);
	}
	
	alfabeto[0] = 'V';  // Define vazio como V

	while(1){ // Loop para adicionar transições
	
		system("cls");
		printf("Adicionar transicao: \n1 - Sim \n2 - Nao");
		scanf(" %d", &op);
		
		if(op == 1){
			system("cls");
			printf("Estado de origem: ");
			scanf(" %d", &transicao[numtrans].estOrigem);
			
			system("cls");
			printf("Estado de destino: ");
			scanf(" %d", &transicao[numtrans].estDestino);
			
			system("cls");
			x:
			printf("Leitura: ");
			scanf(" %c", &transicao[numtrans].ler);
			for(j=0;j<nAlfabeto;j++){ // percorre o alfabeto p ver se a letra esta nele
				if(transicao[numtrans].ler == alfabeto[j]){
					break;
				}else if (transicao[numtrans].ler != alfabeto[j] && alfabeto[j] == (nAlfabeto-1)){
					printf("A letra nao esta no alfabeto\n");
					goto x;
				}
			}
			
			system("cls");
			y:
			printf("Escrita: ");
			scanf(" %c", &transicao[numtrans].escrever);
			for(j = 0; j < nAlfabeto; j++){ // percorre o alfabeto p ver se a letra esta nele
				if(transicao[numtrans].escrever == alfabeto[j]){
					break;
				}else if (transicao[numtrans].escrever != alfabeto[j] && alfabeto[j] == (nAlfabeto-1)){
					printf("A letra nao esta no alfabeto\n");
					goto y;
				}
			}
			
			system("cls");
			printf("Movimentacao: \n1 - Esquerda \n2- Direita \n3 - Parado");
			scanf(" %d", &transicao[numtrans].mov);
			
			numtrans++;
			
		}else{
			system("cls");
			break;
		}	
	}
	
	z:
	
	pos = 0;
	posfita = 1; 

	cout << "Insira a fita inicial: \n";
	cin >> fita; 
	
	fita = "V"+fita+"V";
	system("cls");
	cout << "Fita inicial: " << fita << "\n";
	
	while(1){
		cont++;	
		if(pos != (nEstados - 1)){	
		flag = 0;		
			for(i=0; i < numtrans; i++){				
				if(transicao[i].estOrigem == pos && transicao[i].ler == fita[posfita]){ // Verificação se a palavra será aceita ou rejeitada
					flag=1;
					fita[posfita] = transicao[i].escrever; // Escreve o novo caractere
					if(transicao[i].mov == 1){ // move p esquerda
						posfita--;
					}else if(transicao[i].mov == 2){
						posfita++; // move p direiaa
				    }
					pos = transicao[i].estDestino; // Vai para o estado de origem
					break;
				}
			}
			if(flag == 0){
				cout << "palavra rejeitada\n";
				cout << "Fita final: " << fita << "\n";
				break;
			}
		}else{
			cout << "Palavra aceita\n";
			cout << "Fita final: " << fita << "\n";
			break;
		}
		
		if(cont == 500){ // break de emergencia
			cout << "Palavra rejeitada\n";
			cout << "Fita final: " << fita << "\n";
			break;	
		}
	}
	
	cout << "Testar outra fita: \n1 - Sim \n2 - Nao";
	cin >> op; 
	
	if(op == 1){
		goto z;
	}
	
	return 0;
}
