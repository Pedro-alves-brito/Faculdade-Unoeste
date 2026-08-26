#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

// Declaração de Protótipos das Funções
char Menu(void);
int DecBin(int Dec);

int main(void)
{
	int val;
	char opcao;
	do{
		opcao = Menu();
		switch(opcao)
		{
			case 'A':
				printf("\nValor do numero em decimal: ");
				scanf("%d",&val);
				printf("%d",DecBin(val));
				getch();
				break;
			case 'B': 
				printf("\nB"); 
				break;
			case 'C': 
				printf("\nC"); 
				break;
			case 'D': 
				printf("\nD"); 
				break;
			case 'E': 
				printf("\nE"); 
				break;
			case 'F	': 
				printf("\nF"); 
				break;
			
		}
	}while( opcao != 27);
	return 0;
}

// Protótipos das Funções
char Menu(void){
	system("cls");
	printf("*** Menu de Exercicios sobre funcoes ***");
	printf("\n\t[A] Exercicio 3");
	printf("\n\t[B] Exercicio 4");
	printf("\n\t[C] Exercicio 5");
	printf("\n\t[D] Exercicio 6");
	printf("\n\t[E] Exercicio 7");
	printf("\n\t[F] Exercicio 8");
	printf("\n\t[ESC] Finalizar");
	printf("\nOpicao desejada:");
	return toupper(getch());
}

int DecBin(int Dec)
{
	int Bina = 0, i = 0,deci;
	deci = Dec;
	
	while(deci > 1){
		Bina += (deci%2)*pow(10,i);
		deci = deci/2;
		i++;
	}
	Bina += pow(10,i);
	return Bina;
}
