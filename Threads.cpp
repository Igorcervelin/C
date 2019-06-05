#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct processos{
	int id;
	int time;
	int end;
};

struct processos p[3];
int i;
int flag = 0;

main(){

	for(i=1; i<=4;i++){
		p[i].id=i;
		p[i].time=(rand()%19)+1;
	}
	i--;
	for(;;){
		
		if(i == 0){
			break;
		}else{
			printf("\nProcessos em espera %i\n",(i-1) );	
		}
				
		if(p[i].end == 0){
			printf("\nFila 1 --- Tempo de 3 segundos---Rodando processo de id %i / time: %i\n",p[i].id,p[i].time);
			
			Sleep(3000);	
			p[i].time = p[i].time-3;
			p[i].end = 1;
			flag=1;
		}else if(p[i].end == 1 && p[i].time > 0){
			printf("\nFila 2 --- Tempo de 7 segundos---Rodando processo de id %i / time: %i\n",p[i].id,p[i].time);

			Sleep(7000);
			p[i].time=p[i].time-7;
			p[i].end = 2;
			flag=1;
		}else if(p[i].end==2 && p[i].time > 0){
			printf("\nFila 3 --- Tempo de 10 segundos---Rodando processo de id %i / time: %i\n",p[i].id,p[i].time);
			
			Sleep(10000);
			p[i].time=p[i].time-10;
			p[i].end = 3;
			flag = 1;
		}
		
		system("cls");
		if(flag == 0){
			i--;
		}
		flag = 0;
	}

	printf("O processo 1 foi finalizado na fila %i\n",p[1].end);
	printf("O processo 2 foi finalizado na fila %i\n",p[2].end);
	printf("O processo 3 foi finalizado na fila %i\n",p[3].end);
	printf("O processo 4 foi finalizado na fila %i\n",p[4].end);	
}
