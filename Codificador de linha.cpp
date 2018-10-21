#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main(){
    
	int i = 0; // Contador referente ao tamanho da palavra ou frase
	int j = 0; // Contador referente ao tamanho de cada letra em bin�rio (8)
	int size; // Tamanho da palavra
	int aux[999]; // Auxiliar utilizado para armazenar informa��es tempor�rias 
	char palavra[99]; // Palavra digitada pelo usu�rio
	char letra; // Separa a palavra em letras e armazena para fazer a convers�o para bin�rio
	int binario; // Armazena o n�mero bin�rio ap�s a convers�o
	int decimal = 0; // Recebe tempor�riamente o n�mero decimal ap�s a convers�o 
	int codific[99]; // Armazena os valores decimais em um vetor int e apresenta em forma de char

	printf("\n\nCODIFICADOR DE LINHA\n\n");
	printf("Digite uma palavra: ");
	fgets(palavra,100,stdin); // Armazena a palavra digitada
	size = strlen(palavra); // Verifica a quantidade de caract�res da palavra digitada e armazena na vari�vel size
    
	printf("\nPalavra decodificada em binario: ");
	for(i=0; i<size-1;i++){ // Loop para percorrer toda a palavra
		
// Convers�o Caractere -> Bin�rio

		letra = palavra[i]; // Divide o vetor da palavra, separando letra por letra 
    	for(j=0; j<=7; j++){ // Repete o processo 8 vezes, j� que cada letra cont�m 8 n�meros bin�rios
        	if(letra % 2 == 0){ // Processo matem�tico de convers�o decimal->bin�rio (Apesar da vari�vel letra ser do tipo char, pode-se utiliza-la como seu n�mero de acordo com a tabela ASCII)
            	aux[j] = 0;
            	letra = letra/2;
        	} else {
            	aux[j] = 1;
            	letra = letra/2;
        	}
    	}
    	for(j=7; j>=0; j--){ //Imrpimir o resultado em bin�rio
        	printf("%d", aux[j]); 
		}
		printf(" ");
			


// Convers�o Bin�rio -> Decimal 
			for(j=7; j>=0; j--){ // Loop para percorrer o n�mero bin�rio
			if(aux[j] == 1){  // Processo matem�tico de convers�o bin�rio->decimal
				decimal = decimal + (pow(2, j));
			} else if (aux[j] == 0){
				decimal += 0;
			}			
		}
		codific[i] = decimal; // O vetor codific[i] armazena o n�mero decimal resultante antes da vari�vel decimal ser zerada e sobrescrita no pr�ximo loop
		decimal = 0; // Zera a vari�vel decimal para fazer a pr�xima convers�o
	}    

// Apresenta��o da onda
	printf("\n\nOnda: ");
	for(i=0;i<size-1;i++){  //Loop para percorrer todas as letras
		for(j=7; j>=0; j--){ //Loop para percorrer todos os 8 n�meros bin�rios de cada letra
			if(aux[j] == 1){ //Condi��es para desenhar a onda
				printf("%c",196); // 196 corresponde ao caract�re "Upperline" na tabela ASCII
			} else {
				printf("_");
			}
		}
	}

// Convers�o Decimal -> Caractere
	printf("\n\nPalavra codificada novamente: ");
	
	for(i=0; i<size-1;i++){ // Loop para imprimir a palavra em seu tamanho original
		printf("%c", codific[i]); // Ao imprimir um valor int em %c, ser� mostrado seu valor em char de acordo com a tabela ASCII
	}
	printf("\n\n\n");
	return 0;
}
