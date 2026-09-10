#include <stdio.h>
#include <conio2.h>
#include <windows.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TF 5

struct contato{
	char nome[30], ende[50], tel[15];
};
	
void registro(contato agenda[TF],int &TL);
char menu(void);
void executar(void);
void abrir(contato agenda[TF],int &TL);

int main(void){
	executar();
};

void registro(contato agenda[TF],int &TL){
	int conti = 1;
	char nome[30], ende[50], tel[15];
	clrscr();
	if(TL==TF){
		textcolor(12);
		printf("\n Agenda Telefonica Cheia! ");
		getche();
	}
	else{
		while(TL < TF && conti != 0){
			textcolor(10);
			printf("\n*** Cadastro de Pessoa ***");
			textcolor(9);
			printf("\nQual o nome da pessoa?: ");
			textcolor(15);
			fflush(stdin);
			gets(nome);
			textcolor(9);
			printf("\nQual o endereco da pessoa?: ");
			textcolor(15);
			fflush(stdin);
			gets(ende);
			textcolor(9);
			printf("\nQual o telefone da pesso(So numeros): ");
			textcolor(15);
			fflush(stdin);
			gets(tel);
			strcpy(agenda[TL].nome, nome);
			strcpy(agenda[TL].ende, ende);
			strcpy(agenda[TL].tel, tel);
			TL++;
			textcolor(9);
			printf("\nDeseja continuar a adicionar contatos?");
			textcolor(10);
			printf("\n[1] Sim");
			textcolor(12);
			printf("\n[0] Nao\n");
			textcolor(15);
			scanf("%d", &conti);
			clrscr();
		}
	}
};
void abrir(contato agenda[TF],int &TL){
	clrscr();
	int i;
	printf("\n*** Agenda Telefonica ***");
	for(i=0; i < TL; i++){
		printf("\n Contato Numero [%d]:",i);
		printf("\n Nome: "); puts(agenda[i].nome);
		printf(" Endereco: "); puts(agenda[i].ende);
		printf(" Telefone: "); puts(agenda[i].tel);
	}
	getche();
}
char menu(void){
	clrscr();
	textcolor(11);
	printf("\n*** Menu ***");
	textcolor(15);
	printf("\n[A] Adicionar Contato na Agenda Telefonica");
	printf("\n[B] Mostrar Agenda Telefonica");
	printf("\n[C] Ordernar Agenda Telefonica");
	printf("\n[D] ");
	printf("\n[E] ");
	printf("\n[F] ");
	printf("\n[G] ");
	printf("\n[H] ");
	printf("\n[I] ");
	printf("\n[J] ");
	printf("\n[K] ");
	printf("\n[L] ");
	printf("\n[M] ");
	printf("\n[N] ");
	printf("\n[ESC] SAIR\n");
	return toupper(getche());	
};
void executar(void){
	char op;
	contato agenda[TF];
	int TL=0;
	do{
		op = menu();
		switch(op){
			case 'A':
				registro(agenda,TL);
				break;
			case'B':
				abrir(agenda,TL);
				break;
			case'C':
				
				break;
			case 'D':
				
				break;
			case 'F':
				
				break;
			case 'G':
				
				break;
			case 'I':
				
				break;
			case 'J':
				
				break;
		}
	}while(op != 27);
};
