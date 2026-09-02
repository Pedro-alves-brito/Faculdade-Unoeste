#include <stdio.h>
#include <conio2.h> // A mesma coisa que o conio, mas com mais coisas
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF,int Temp){
	int i;
	textcolor(CorT); // 0....15 ou BLACK.....WHITE
	textbackground(CorF);
	gotoxy(CI,LI); printf("%c", 201);
	for(i = CI+1; i<CF; i++){
		gotoxy(i,LI); printf("%c", 205);
		Sleep(Temp);
	}
	gotoxy(CF,LI); printf("%c", 187);
	
	for(i = LI+1; i<LF; i++){
		gotoxy(CI,i); printf("%c", 186);
		Sleep(Temp);
		gotoxy(CF,i); printf("%c", 186);
	}
	gotoxy(CI,LF); printf("%c", 200);
	for(i = CI+1; i<CF; i++){
		gotoxy(i,LF); printf("%c", 205);
		Sleep(Temp);
	}
	gotoxy(CF,LF); printf("%c", 188);
	textcolor(7);
	textbackground(0);
}

char Menu(void)
{
	 system("cls");
	 Moldura(1,1,80,25,2,15,1);
	 Moldura(15,5,65,20,7,0,1);
	 gotoxy(20,8);printf("*** MENU Exercicio sobre Funcoes ***");
	 gotoxy(20,10);printf("[A] Exercicio 3 - Decimal para Binario");
	 gotoxy(20,11);printf("[B] Exercicio 4 - Binario para Decimal");
	 gotoxy(20,12);printf("[C] Exercicio 5 - Numero Perfeito");
	 gotoxy(20,13);printf("[D] Exercicio 6");
	 gotoxy(20,14);printf("[E] Exercicio 7");
	 gotoxy(20,15);printf("[F] Tabela ASCII");
	 gotoxy(20,17);printf("[ESC] Sair");
	 return toupper(getche());
}

int LeValor(void)
{
	int valor;
	printf("\nDigite o Valor: ");
	scanf("%d",&valor);
	return valor;
}

void ExibeValor(char texto[100], int N)
{
	printf("\nResultado:\n %s = %d\n",texto,N);
	getch();
}

int DecimalBinario(int Decimal)
{
	 int Binario=0, mult=1;
	 while(Decimal>1)
	 {
		  Binario = Binario + Decimal%2 * mult;
		  Decimal = Decimal/2;
		  mult = mult*10;
	 }
	 Binario = Binario + Decimal*mult;
	 
	 return Binario;
}

int retornarbinario(int numero){
	
	int valor=0, i;
	
	for(i=0; numero>1 ;i++){		
		valor += pow(10,i)* (float)(numero%2); 
		numero /= 2;	
	}
	valor += pow(10,i);
		
	return valor ;	
}

int BinarioDecimal(int Binario)
{
	int Decimal=0,num, expoente = 0, ultdig;
	num = Binario;
	while(num > 1)
	{
		 
		Decimal += num %10 * pow(2, expoente);
		num = num / 10;
		expoente++;
	}
	Decimal += pow(2, expoente);
	
	return Decimal;
}

int Perfeito(int Numero)
{
	int Soma=0, divisor;
	for(divisor=1; divisor<=Numero/2; divisor++)
		if (Numero%divisor == 0)
			Soma = Soma + divisor;
	
	if (Soma == Numero)
		return 1;
	else
		return 0;
}

void TabelaASCII(void)
{
	int i;
	for(i=0; i<256; i++)
		printf("%d - %c - %o - %x\n",i,i,i,i);
		
	getch();
}

int main(void)
{
	
	 int opcao;
	 do
	 {
		  opcao = Menu();
		  switch(opcao)
		  {
		   case 'A':   system("cls");
		   			   ExibeValor((char *)"Decimal para Binario",DecimalBinario(LeValor()));
				       ExibeValor((char *)"Decimal para Binario",retornarbinario(LeValor()));
				       getch();
				       break;
				       
		   case 'B': 	system("cls");
		   			    ExibeValor((char *)"Binario para Decimal",BinarioDecimal(LeValor()));
		   			    
		   				break;
		   
		   case 'C': system("cls");
		   			 printf("*** Verifica se Perfeito ***\n");
		   			 if (Perfeito(LeValor()) == 1)
		   			 	printf("\nNumero eh Perfeito!");
		   			 else
		   			 	printf("\nNumero NAO eh Perfeito!");
		   			 
		   			 getch();
		   			 break;
		   
		   case 'D': break;
		   
		   case 'E': break;
		   
		   case 'F': system("cls");
		   			 printf("\n*** Tabela da ASCII ***\n");
					 TabelaASCII();
		   			 break;
	  }
	 }while(opcao != 27);
	 
	 return 0;
}
