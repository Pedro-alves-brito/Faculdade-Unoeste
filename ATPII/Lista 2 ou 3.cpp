#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#define TF 100

char Menu(void);
void Frequencia(int Vet[TF], int TL, int &MaFr, int &QtdVz){
	int i,j,x;
	for(i=0; i < TL; i++){
	x = 0;
	for(j=0; j < TL; j++){
		if(Vet[i] == Vet[j]){
			x++;
		}
	}
	if( x > QtdVz){
		if(Vet[i] != MaFr){
			MaFr = Vet[i];
			QtdVz = x;
		}
	}
}
}

void InserirVetor(int Vet[TF], int &TL){
	int i;
		clrscr();
		printf("\nDe um numero (numero negativo para parar): ");
		scanf("%d", &i);
	while(i >=0){
		Vet[TL] = i;
		TL++;
		clrscr();
		printf("\nDe um numero (numero negativo para parar): ");
		scanf("%d", &i);
	}
}

void ExibirVetor(int Vet[TF], int TL){
	int i;
	for(i = 0; i < TL; i++){
		printf("\nValor posissao [%d]: [%d]", i+1, Vet[i]);
	}
}

void Executar(void){
	char op;
	int VetA[TF], TLA=0, MaFr=0, QtdVz=0, VetB[TF], TLB=0;
	do{
		op = Menu();
		switch(op){
			case 'A':
				InserirVetor(VetA,TLA);
				break;
			case 'B':
				ExibirVetor(VetA, TLA);
				break;
			case 'C':
				InserirVetor(VetB,TLB);
				break;
			case 'D':
				ExibirVetor(VetB, TLB);
				break;
			case 'E':
				if(TLA == 0)
					printf("\nNão ha elementos no Vetor A!!!");
				else{
					Frequencia(VetA, TLA, MaFr, QtdVz);
					printf("\nElemento de maior frequencia = [%d] que aparece [%d] vezes",MaFr, QtdVz);
					getch();
				}
				getch();
				break;
			case 'F':
				
				break;
			case 'G':
				
				break;
		}
	}while(op != 27);
}

char Menu(void){
	clrscr();
	printf("\n***Exercicios com Vetor***");
	printf("\n[A] Inserir no Vetor A");
	printf("\n[B] Exibir Vetor A");
	printf("\n[C] Inserir no Vetor B");
	printf("\n[D] Exibir Vetor B");
	printf("\n[E] Elemento com Maior Frequencia");
	printf("\n[F]");
	printf("\n[G]");
	printf("\n[ESC] Sair");
	return toupper(getche());
}

int main(){
	Executar();
}
