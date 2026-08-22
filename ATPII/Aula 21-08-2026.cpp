#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

// Constantes
#define TF 20

//Protótipos das Funções
char Menu(void);
int LeValor(void);
void ExibirValor(int N);

//Implementação das Funções
int main(void)
{
	char op;
	int A,B;
	do
	{
		op = Menu();
		
		switch(op)
		{
			case 'A':
				printf("\n\n\ Conhecer o valor de A");
				A = LeValor();
				getch();
				break;
			case 'B':
				printf("\n\n\ Conhecer o valor de B");
				B = LeValor();
				getch();
				break;
			case 'C':
				printf("\n\n Exibir o valor de A");
				ExibirValor(A);
				getch();
				break;
			case 'D':
				printf("\n\n Exibir o valor de B");
				ExibirValor(B);
				getch();
				break;
			
		}
		
	}while(op != 27);
	
	return 0;
}

char Menu(void)
{
	system("cls");
	printf("\n *** MENU ***");
	printf("\n[A] Conhecer o valor de A");
	printf("\n[B] Conhecer o valor de B");
	printf("\n[C] Exibir o valor de A");
	printf("\n[D] Exibir o valor de B");
	printf("\n[ESC] sair \n");
	printf("\nOpcao desejada: ");
	return toupper(getch());
}
int LeValor(void)
{
	int valor;
	do{
		printf("\n Digite um valor igual ou maior a 0 sendo um numero inteiro: ");
		scanf("%d", &valor);
	}while(valor < 0);
	return(valor);
}
void ExibirValor(int N)
{
	printf("/n O valor é de: %d", N);
	getch();
}
