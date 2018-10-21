#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main(){
    
	int i = 0; // Contador referente ao tamanho da palavra ou frase
	int j = 0; // Contador referente ao tamanho de cada letra em binário (8)
	int size; // Tamanho da palavra
	int aux[999]; // Auxiliar utilizado para armazenar informações temporárias 
	char palavra[99]; // Palavra digitada pelo usuário
	char letra; // Separa a palavra em letras e armazena para fazer a conversão para binário
	int binario; // Armazena o número binário após a conversão
	int decimal = 0; // Recebe temporáriamente o número decimal após a conversão 
	int codific[99]; // Armazena os valores decimais em um vetor int e apresenta em forma de char

	printf("\n\nCODIFICADOR DE LINHA\n\n");
	printf("Digite uma palavra: ");
	fgets(palavra,100,stdin); // Armazena a palavra digitada
	size = strlen(palavra); // Verifica a quantidade de caractéres da palavra digitada e armazena na variável size
    
	printf("\nPalavra decodificada em binario: ");
	for(i=0; i<size-1;i++){ // Loop para percorrer toda a palavra
		
// Conversão Caractere -> Binário

		letra = palavra[i]; // Divide o vetor da palavra, separando letra por letra 
    	for(j=0; j<=7; j++){ // Repete o processo 8 vezes, já que cada letra contém 8 números binários
        	if(letra % 2 == 0){ // Processo matemático de conversão decimal->binário (Apesar da variável letra ser do tipo char, pode-se utiliza-la como seu número de acordo com a tabela ASCII)
            	aux[j] = 0;
            	letra = letra/2;
        	} else {
            	aux[j] = 1;
            	letra = letra/2;
        	}
    	}
    	for(j=7; j>=0; j--){ //Imrpimir o resultado em binário
        	printf("%d", aux[j]); 
		}
		printf(" ");
			


// Conversão Binário -> Decimal 
			for(j=7; j>=0; j--){ // Loop para percorrer o número binário
			if(aux[j] == 1){  // Processo matemático de conversão binário->decimal
				decimal = decimal + (pow(2, j));
			} else if (aux[j] == 0){
				decimal += 0;
			}			
		}
		codific[i] = decimal; // O vetor codific[i] armazena o número decimal resultante antes da variável decimal ser zerada e sobrescrita no próximo loop
		decimal = 0; // Zera a variável decimal para fazer a próxima conversão
	}    

// Apresentação da onda
	printf("\n\nOnda: ");
	for(i=0;i<size-1;i++){  //Loop para percorrer todas as letras
		for(j=7; j>=0; j--){ //Loop para percorrer todos os 8 números binários de cada letra
			if(aux[j] == 1){ //Condições para desenhar a onda
				printf("%c",196); // 196 corresponde ao caractére "Upperline" na tabela ASCII
			} else {
				printf("_");
			}
		}
	}

// Conversão Decimal -> Caractere
	printf("\n\nPalavra codificada novamente: ");
	
	for(i=0; i<size-1;i++){ // Loop para imprimir a palavra em seu tamanho original
		printf("%c", codific[i]); // Ao imprimir um valor int em %c, será mostrado seu valor em char de acordo com a tabela ASCII
	}
	printf("\n\n\n");
	return 0;
}
