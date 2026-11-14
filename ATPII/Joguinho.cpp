#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>

#define X1 20
#define X2 60
#define Y1 5
#define Y2 20

struct TpCenario
{
	int x,y,cor,pontos;
	char Elemento;
};

struct TpPlayer
{
	char Nome[30], Player, Arma, Direcao;
	int x,y, Score, xtiro,ytiro, Vidas;
};

struct TpRanking
{
	char NomeJog[30];
	int TotPontos;
}

void InicializarPlayer(TpPlayer &P)
{
	textcolor(15);
	print("\n***INICIALIZANDO PLAYER***");
	print("\nNome do Player: ");
	fflush(stdin);
	gets(P.Nome);
	
	P.Arma='.'; // tipo de bala F1: . F2: * F3: #
	P.Player=184;
	P.Score=0;
	P.Vidas=3;
	P.x=(X1+X2)/2;
	P.y=(Y1+Y2)/2;
	P.Direcao='C'; //D,E,C,B
};

void Moldura(int CI, int LI, int CF, int LF, int CorT, inst CorF)

{
	int i;
	textcolor(CorT);  // BLACK 0..15 WHITE
	textbackground(CorF);
	gotoxy(CI,LI);   printf("%c",201);
	gotoxy(CF,LI);	 printf("%c",187);
	gotoxy(CI,LF);	 printf("%c",200);
	gotoxy(CF,LF);	 printf("%c",188);
	for(i=CI+1; i<CF; i++)
	{
		gotoxy(i,LI);	printf("%c",205);
		Sleep(10);
		gotoxy(i,LF);	printf("%c",205);
	}
	for(i=LI+1; i<LF; i++)
	{
		gotoxy(CI,i);	printf("%c",186);
		Sleep(10);
		gotoxy(CF,i);	printf("%c",186);
	}
	textcolor(7);
	textbackground(0);
}



void GerarCenario(void)
{
	int cont;
	TpCenario RCena;
	
	FILE *PtrCena=fopen("Cenario.dat","wb");
	Moldura(X1,Y1,X2,Y2,6);
	
	for(cont=1; cont<=100; cont++)
	{
		RCena.cor = rand()%16; // 0 ... 15
		RCena.Elemento = rand()%26; // 0 ... 25
		RCena.pontos = (rand()%3+1)*10;//10,20,30
		RCena.x = rand()%(X2-X1-1) + 1 + X1;// 20 ... 60 0 ... 39
		Rcena.y = rand()%(Y2-Y1-1) + 1 + Y1;// 5 ... 15 15-5 8...0 -> 9...1 -> z+5 6...14
		fwrite(&RCena,sizeof(TpCenario),1,PtrCena);
		
		gotoxy(RCena.x,Rcena.y);
		textcolo(RCena.cor);
		printf("%C",RCena.Elemento);
	}
	fclose(PtrCena)
}

void GerarCenario2(void)
{
	FILE*PtrCena=fopen("Cenario.dat","rb");
	TpCenario Rcena;
	
	if(PtrCena==NULL)
	{
		printf("\nERRO AO ABRIR O ARQUIVO");
		getch();
	}
	else
	{
		Moldura(X1,Y1,X2,Y2,15,10);
		fread(&RCena,sizeof(TpCenario),1,PtrCena);
		
		while(!feof(PtrCena))
		{
			gotoxy(RCena.x,Rcena.y);
			txtcolo(RCena.cor);
			printtf("%c",RCena.Elemento);
			
			fread(&Rcena,sizeof(TpCenario),1,PtrCna);
		}
		
		fclose(PtrCena)	
	}
}

void Jogo(vod){
	
	char tecla;
	TpPlayer Player;
	
	InicializarPlayer(Player);
	MostrarCenario();
	do{
		textcolor(15);
		gotoxy(Player.x,Player.y);
		printf("%c",Player.Player);
		tecla = getch();
		gotoxy(Player.x,Player.y);
		printf(" ");
		switch(toupper(tecla))
		{
			case'A':
				if(Player.x==X1+1)
					Player.x=X2-1;
				else
				{
					Player.x--;
					Player.Direcao='E';
				}
				break;
			case'S':
				if(Player.y==Y2-1)
					Player.y=Y1+1;
				else
				{
					Player.y++;
					Player.Direcao='B';
				}
				break;
			case'D':
				if(Player.x==X2-1)
					Player.x=X1+1;
				else
				{
					Player.x--;
					Player.Direcao='D';
				}
			case'W':
				Player.y--;
				Player.Direcao='C';
				if(Player.y==Y1+1)
					Player.y=Y2-1;
				else
				{
					Player.y--;
					Player.Direcao='C';
				}
				break;
			
		}
		
	}while(tecla!=27 && Player.VIdas>0);
	
	printf("\n***Player: %s \tTotal de Pontos: %d\n",Player.Player,Player.Score);
	
	getch();
}

char Menu(void)
{
	 system("cls");
	 Moldura(1,1,80,25,10,7);
	 Moldura(15,5,65,20,1,8);
	 gotoxy(20,7);	printf("*** MENU Exercicio sobre Funcoes ***");
	 gotoxy(20,9);	printf("[A] Cadastrar Player");
	 gotoxy(20,10);	printf("[B] Gerar Cenario");
	 gotoxy(20,11);	printf("[C] Jogar");
	 gotoxy(20,12);	printf("[D] Mostrar Cenario");
	 gotoxy(20,13);	printf("[E] Mostrar Ranking");
	 gotoxy(20,14);	printf("[F] Tabela ASCII");
	 gotoxy(20,15);	printf("[ESC] Sair");
	 gotoxy(20,17); printf("Opcao desejada: ");
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
	 srand(time(NULL));	//Toda vez que chama o rand coloca o clock atual da maquina, o s vem de seed e o rand de randomize
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
		   
		   case 'D': 
					system("cls")
					Jogo();
					break;
		   
		   case 'E': break;
		   
		   case 'F': system("cls");
		   			 printf("\n*** Tabela da ASCII ***\n");
					 TabelaASCII();
		   			 break;
	  }
	 }while(opcao != 27);
	 
	 return 0;
}
