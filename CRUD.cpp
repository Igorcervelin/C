#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


//Fun寤es

void Cadastro();
void Clientes();
void Excluir();
void Dados();
void Alterar();
void Menu();
void Logo();

//Estruturas

struct dados{
	char nome[100];
	char sexo[20];
	char data[100];
	char cpf[100];
	char telefone[100];
	char email[100];
	int cod;
	int flag;
};

//Variaveis Globais

int i, n=1, cont=0; // Conts
int id, op; // Login e Menu
struct dados d [50];


main(){
	
	//Fullscreen
	
	keybd_event(VK_MENU  , 0x36, 0, 0);
	keybd_event(VK_RETURN, 0x1C, 0, 0);
	keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU  , 0x38, KEYEVENTF_KEYUP, 0);
	
	//Login
	
	login:
	
	for(;;){
		
		id = 0;
		
		system("cls");
		system("color 0e");
		Logo();
	
	printf("\t\t\t\t\t\t\t\t SISTEMA DE CADASTRO E CONTROLE DE CLIENTES\n\n");
	printf("\n\n\t\t\t\t\t\t Para sair pressione Alt + F4 ");
	printf("\n\n\t\t\t\t\t\t ID: ");

	scanf("%i", &id);
		
		if(id == 1 || id == 2){
			system("cls");
			system ("color 0a");
			Logo();
			printf("\n\n\t\t\t\t\t\t\t\t\t\tACESSO PERMITIDO!");
			Sleep(950);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t    Bem vindo!");
			Sleep(950);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t    Iniciando\n");
			Sleep(500);
			Beep(760,100);
			printf("\t\t\t\t\t\t\t\t\t\t\t.");
			Sleep(500);
			Beep(1070,100);
			printf("\n\t\t\t\t\t\t\t\t\t\t\t.");
			Sleep(500);
			Beep(1300,100);
			printf("\n\t\t\t\t\t\t\t\t\t\t\t.");
			Sleep(900);		

for(;;){		
		//Menu
		system("color 0a");
		system ("cls"); // limpa a tela
		Menu();
	
	
		if(op == 1){
			Cadastro();			
		}else if (op == 2){
			Excluir();
		}else if (op == 3){
			printf("\n");
			Clientes();
			printf("\n");
		}else if (op == 4){
			Dados();	
		}else if (op == 5){
			Alterar();	
		}
		else if (op == 6){
			system("color 08");
			printf("\n\n\t\t\t\t\t\t\t\t\t\tSaindo");
			Sleep(500);
			Beep(1300,100);
			printf(".");
			Sleep(500);
			Beep(1070,100);
			printf(".");
			Sleep(500);
			Beep(760,100);
			printf(".");
			Sleep(500);
			break;		
		}else{
			printf("\nOpcao invalida!\n\n");
			system("pause");
		}		
}

	} else {
				system("color 0c");
			printf("\n\t\t\t\t\tID invalido!\n");
			printf("\n\n\t\t\t\t\tDigite 1 para tentar novamente");
			printf("\n\n\t\t\t\t\tDigite qualquer outra tecla para sair\n");
			printf("\n\n\t\t\t\t\tOpcao: ");
			scanf("%i", &id);
				if (id == 1){
					goto login;
				} else {
			system("color 08");
			printf("\n\n\t\t\t\t\t\t\t\t\t\tFinalizando");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			break;
				}		
			}
		
	}

	return 0;
}


void Cadastro(){ 
		
	system("cls");
	Logo();
	system ("color 0e");
	printf("\n\t\t\t\t\t\t\t\t\tSISTEMA DE CADASTRO DO CLIENTE\n");
	
	printf("\n\tNome completo: ");
	scanf(" %[^\n]s", &d[n].nome);
					
	sexo:
		
	system ("color 0e");
	system("cls");
	Logo();
	printf("\n\t\t\t\t\t\t\t\t\t\tSISTEMA DE CADASTRO DO CLIENTE\n");
		
	printf("\n\tNome completo: %s ", d[n].nome);
	printf("\n\n\tSexo (F = Feminino / M = Masculino): ");
	scanf("%s", &d[n].sexo);
		if(strcmp(d[n].sexo, "F")){
			if(strcmp(d[n].sexo, "f")){
				if(strcmp(d[n].sexo, "M")) {
					if (strcmp(d[n].sexo, "m")){
						system ("color 0c");
					printf("\tComando invalido!\n");
				system("pause");
				goto sexo;
					}
				}
			}
		}
		
		 if(!strcmp(d[n].sexo, "f")){
			strcpy(d[n].sexo, "Feminino");
		}
		
		 if(!strcmp(d[n].sexo, "F")){
			strcpy(d[n].sexo, "Feminino");
		}
		 if(!strcmp(d[n].sexo, "m")){
			strcpy(d[n].sexo, "Masculino");
		} 
		
		if(!strcmp(d[n].sexo, "M")){
			strcpy(d[n].sexo, "Masculino");
		}
	
			printf("\n\tDigite a data de nascimento (dd/mm/aaaa): ");
			scanf(" %[^\n]s", &d[n].data);
			
			printf("\n\tDigite o CPF (xxx.xxx.xxx-xx): ");
			scanf(" %[^\n]s", &d[n].cpf);
			
			printf("\n\tDigite o telefone ((xx)xxxxx-xxxx): ");
			scanf(" %[^\n]s", &d[n].telefone);
			
			printf("\n\tDigite o e-mail: ");
			scanf(" %[^\n]s", &d[n].email);
			
		
			cont+=1;
			d[n].cod = n;
			d[n].flag == 0;
				n++;
			
			system("color 0a");
			printf("\n\tCadastro concluido com sucesso!\n");
			system("pause");
		
}
		
void Clientes(){

	
	printf("\nCLINTES ATIVOS:\n ");
	
	if(cont == 0){
		system("color 06");
		printf("\nNenhum cliente cadastrado!\n\n");
		system("pause");
	} else {
		
		for(i=1; i<n; i++){
		
			if(d[i].flag == 0){		
				printf("\nCodigo: %i",d[i].cod);
				printf("\n Nome completo: %s ",d[i].nome);
				printf("\n Sexo: %s",d[i].sexo);
				printf("\n Data de nascimento: %s",d[i].data);
				printf("\n CPF: %s",d[i].cpf);
				printf("\n Telefone: %s",d[i].telefone);
				printf("\n E-mail: %s",d[i].email);
				printf("\n\n");
				system ("pause");
		
			}
			if(d[n].flag == 1){
			printf("\nConta desativada!\n");
			system("pause");
			} 
		}
	}
}
	
	
void Excluir(){
	
	int x,k;
	
		printf("Voce quer mesmo excluir?\n (1 = sim)\n");
		scanf("%i", &k);
		
		if(k == 1){
		system("color 0C");
		printf("\nQual o codigo do cliente a ser removido?\n ");
		scanf("%i", &x);	
		
			if(x < n){
				printf("\nNome do cliente: %s", d[x].nome);	
				Beep(760,100);
				Sleep(500);
				Beep(760,100);
				Sleep(500);
				Beep(760,900);
				printf("\nDesativando...\n");
				Sleep(1000);
				d[x].flag = 1;
				system("pause");
				} else {
					printf("\nCodigo inexistente!\n\n");
					system("pause");
				}
		} else {
			system("color 0a");
			printf("Retornando...");
			Sleep(1800);
		}
	}
		
void Alterar(){
	
	int aux;
	int cod;
	
	char novonome[100];
	char novosexo[20];
	char novadata[100];
	char novocpf[100];
	char novotelefone[100];
	char novoemail[100];
	
	system ("color 0f");
	int cd;
	int oq;
	
	printf("\nInsira o codigo do cliente para alterar: ");
	scanf("%i", &cod);
	
	if(cod >= n){
		printf("\nCodigo invalido!\n");
		system("pause");
		
	} else if (cod<n){
	
		printf("\n\nAlterar: \n");
		printf("\nNome (1) ");
		printf("\nSexo (2) ");
		printf("\nData de nascimento (3) ");
		printf("\nCPF (4) ");
		printf("\nTelefone (5) ");
		printf("\nEmail (6)\n ");
		printf("Opcao: ");
		scanf("%i", &oq);
	
	if(oq == 1){
		printf("\nNovo nome: ");
		scanf(" %[^\n]s", &d[cod].nome);
		printf("\nNome alterado para %s\n", d[cod].nome);
		system("pause");	
			
	}
	
	if(oq == 2){
		printf("\nNovo sexo: ");
		scanf("%s", &d[n].sexo);
		if(strcmp(d[n].sexo, "F")){
			if(strcmp(d[n].sexo, "f")){
				if(strcmp(d[n].sexo, "M")) {
					if (strcmp(d[n].sexo, "m")){
						system ("color 0c");
					printf("\tComando invalido!\n");
				system("pause");
					}
				}
			}
		}
		
		 if(!strcmp(d[n].sexo, "f")){
			strcpy(d[n].sexo, "Feminino");
		}
		
		 if(!strcmp(d[n].sexo, "F")){
			strcpy(d[n].sexo, "Feminino");
		}
		 if(!strcmp(d[n].sexo, "m")){
			strcpy(d[n].sexo, "Masculino");
		} 
		
		if(!strcmp(d[n].sexo, "M")){
			strcpy(d[n].sexo, "Masculino");
		}
	}
	system("pause");

	if(oq == 3){
		printf("\nNova data de nascimento: ");	
		scanf(" %[^\n]s", &d[cod].data);
		printf("\nNome alterado para %s\n", d[cod].data);
		system("pause");
			
	}

	if(oq == 4){
		printf("\nNovo CPF: ");
		scanf(" %[^\n]s", &d[cod].cpf);
		printf("\nNome alterado para %s\n", d[cod].cpf);
		system("pause");
	}

	if(oq == 5){
		printf("\nNovo telefone: ");
		scanf(" %[^\n]s", &d[cod].telefone);
		printf("\nNome alterado para %s\n", d[cod].telefone);
		system("pause");
	}

	if(oq == 6){
		printf("\nNovo email: ");
		scanf(" %[^\n]s", &d[cod].email);
		printf("\nNome alterado para %s\n", d[cod].email);
		system("pause");	
	}
		 else if (op > 6) {
		system("color 0c");
		printf ("Comando invalido!");
		system("pause");
		}
		
	}

}

void Dados(){
	
	char x[50];
	int y,z,aux;
	int flag2 = 0;
	
	system("color 0e");
	printf("\nPesquisar por codigo (1) ou por nome (2): ");
	scanf("%i", &z);
	
	if(z == 1){
		printf("\nDigite o codigo: ");
		scanf("%i", &y);
		if((y <= cont) && (d[y].flag == 0)){
			printf("\nCodigo: %i",d[y].cod);
			printf("\n Nome completo: %s ",d[y].nome);
			printf("\n Sexo: %s",d[y].sexo);
			printf("\n Data de nascimento: %s",d[y].data);
			printf("\n CPF: %s",d[y].cpf);
			printf("\n Telefone: %s",d[y].telefone);
			printf("\n E-mail: %s",d[y].email);
			printf("\n\n");
			system ("pause");
		} else {
			printf("\nCodigo invalido ou inativo!\n");
			system("pause");
		}
	}
		
	 if(z == 2){
	 		printf("\nDigite o nome: ");
			scanf("%s", &x);
	 		for(y=0;y<n;y++){
				if(!strcmp(x, d[y].nome) && (d[y].flag == 0)){
					printf("\nCodigo: %i",d[y].cod);
					printf("\n Nome completo: %s ",d[y].nome);
					printf("\n Sexo: %s",d[y].sexo);
					printf("\n Data de nascimento: %s",d[y].data);
					printf("\n CPF: %s",d[y].cpf);
					printf("\n Telefone: %s",d[y].telefone);
					printf("\n E-mail: %s",d[y].email);
					printf("\n\n");
					system ("pause");
					flag2++;
				} else {
					printf("\nNome invalido ou inativo!\n");
					system("pause");
				}
			}
	
			if(flag2 == 0){
				printf("\nNome nao encontrado!\n");
				system ("pause");
			}
	}
	
	if(z > 2){
		printf("\nComando invalido!\n");
		system("pause");
	}
}



void Menu(){
	
	Logo();
	

	printf("\n\tEscolha uma opcao:\n\t1 - Cadastrar novo cliente \n\t2 - Exclusao de clientes \n\t3 - Clientes cadastrados \n\t4 - Dados do cliente \n\t5 - Alterar dados \n\t6 - Sair\n\n\tOpcao: ");
	scanf("%i", &op);
	
}


void Logo(){
	
	printf("\n\n\t\t\t\t\t\t같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같�");
	printf("\n\t\t\t\t\t\t같 o    o   o     ooooooo  oooooo   ooooooo   oooooo   ooooooo   ooooooo  ooooooo  같\n");
	printf("\t\t\t\t\t\t같 o    o   o        o     o    o   o     o   o        o     o   o	     o     같\n");
	printf("\t\t\t\t\t\t같 o    o   o	     o     o ooo    ooooooo   oooooo   o     o   oooo	     o     같\n");
	printf("\t\t\t\t\t\t같 o    o   o	     o     o   o    o     o        o   o     o   o	     o     같\n");
	printf("\t\t\t\t\t\t같 oooooo   ooooo    o     o    o   o     o   oooooo   ooooooo   o           o     같\n");
	printf("\t\t\t\t\t\t같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같�\n\n\n\n");
	
}
