#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#define TF 100

char Menu(void);
void Frequencia(int Vet[TF], int TL, int &MaFr, int &QtdVz){
	int i,j,x;
	QtdVz=0;
	for(i=0; i < TL; i++){
		x = 0;
		for(j=i+1; j < TL; j++){
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

void SomaVet(int Vet[TF], int TL, int &Som){
	int i,soma=0;
	for(i=0; i<TL; i++){
		soma += Vet[i];
	}
	Som = soma;
}

void InserirVetor(int Vet[TF], int &TL){
	int i;
		clrscr();
		printf("\nDe um numero (0 para parar): ");
		scanf("%d", &i);
	while(i !=0){
		Vet[TL] = i;
		TL++;
		clrscr();
		printf("\nDe um numero (0 para parar): ");
		scanf("%d", &i);
	}
}

void ExibirVetor(int Vet[], int TL){
	int i;
	for(i = 0; i < TL; i++){
		printf("\nValor posissao [%d]: [%d]", i+1, Vet[i]);
	}
	getch();
}

int ContidoVet(int Vet[TF], int TL, int Comp){
	int i=0, Exist = 0;
	while(i < TL && Vet[i] != Comp)
		i ++;
	if(i < TL)
		Exist = 1;
	return Exist;
}

void DecBina(int Dec){
	int Bina[TF],TL=0, i = 1,deci;
	deci = Dec;
	
	while(deci > 0){
		Bina[TL] = (deci%2);
		deci /=2;
		TL++;
	}
	printf("\nValor do Decimal [%d] em Binario é de: ", Dec);
	for(i=TL-1; i >= 0; i--){
		printf("%d",Bina[i]);
	}
	getch();
}

void SubConj(int VetA[], int TLA, int VetB[], int TLB){
	int VetC[TF*2], TLC = 0, i, j,k;
	
	for(i=0; i < TLA; i++){
		if(ContidoVet(VetB, TLB, VetA[i]) == 0)
			if(ContidoVet(VetC, TLC, VetA[i]) == 0){
				VetC[TLC]=VetA[i];
				TLC ++;
			}
	}
	for(i=0; i < TLB; i++){
		if(ContidoVet(VetA, TLA, VetB[i]) == 0)
			if(ContidoVet(VetC, TLC, VetB[i]) == 0){
				VetC[TLC]=VetB[i];
				TLC ++;
			}
	}
	printf("\n*****Resultado da Subtração entre Verotes(A e B)*****");
	for(i=0; i < TLC; i++){
		printf("\nVetor C [%d]: %d", i+1, VetC[i]);
	}
	getch();
}

void MERGE(int VetA[], int TLA, int VetB[], int TLB){
	int VetC[TF*2], TLC = 0, i, j,k;
	
	for(i=0; i < TLA; i++){
		if(ContidoVet(VetB, TLB, VetA[i]) == 0)
			if(ContidoVet(VetC, TLC, VetA[i]) == 0){
				j = 0;
				while(j < TLC && VetC[j]<VetA[i])
					j++;
				if(j == TLC){
					VetC[TLC]=VetA[i];
					TLC ++;
				}
				else{
					for(k=TLC; k > j; k--){
						VetC[k]=VetC[k-1];
					}
					VetC[TLC]=VetA[i];
					TLC ++;
				}
			}
	}
	for(i=0; i < TLB; i++){
		if(ContidoVet(VetA, TLA, VetB[i]) == 0)
			if(ContidoVet(VetC, TLC, VetB[i]) == 0){
				j = 0;
				while(j < TLC && VetC[j]<VetB[i])
					j++;
				if(j == TLC){
					VetC[TLC]=VetB[i];
					TLC ++;
				}
				else{
					for(k=TLC; k > j; k--){
						VetC[k]=VetC[k-1];
					}
					VetC[j]=VetB[i];
					TLC ++;
				}
			}
	}
	
	printf("\n*****Resultado do MERGE entre Verotes(A e B)*****");
	for(i=0; i < TLC; i++){
		printf("\nVetor C [%d]: %d", i+1, VetC[i]);
	}
	getch();
}

void InteConj(int VetA[], int TLA, int VetB[], int TLB){
	int VetC[TF*2], TLC = 0, i, j,k;
	
	for(i=0; i < TLA; i++){
		if(ContidoVet(VetB, TLB, VetA[i]) == 1)
			if(ContidoVet(VetC, TLC, VetA[i]) == 0){
				VetC[TLC]=VetA[i];
				TLC ++;
			}
	}
	for(i=0; i < TLB; i++){
		if(ContidoVet(VetA, TLA, VetB[i]) == 1)
			if(ContidoVet(VetC, TLC, VetB[i]) == 0){
				VetC[TLC]=VetB[i];
				TLC ++;
			}
	}
	printf("\n*****Resultado da Intersecção entre Verotes(A e B)*****");
	for(i=0; i < TLC; i++){
		printf("\nVetor C [%d]: %d", i+1, VetC[i]);
	}
	getch();
}

void Executar(void){
	char op;
	int VetA[TF], TLA=0, MaFr=0, QtdVz, VetB[TF], TLB=0,SOMA, Dec,Comp;
	do{
		op = Menu();
		clrscr();
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
				if(TLB == 0)
					printf("\nNão ha elementos no Vetor B!!!");
				else{
					SomaVet(VetB, TLB, SOMA);
					printf("\nValor da soma de todos os Elementos é de [%d]",SOMA);
					getch();
				}
				getch();
				break;
			case 'G':
				
				printf("\nDe um Valor para Comparação: ");
				scanf("%d", &Comp);
				printf("\nO Numero [%d] no vetor. ([0] Não Existe, [1] Existe)",ContidoVet(VetA, TLA, Comp));
				getch();
				break;
			case 'H':
				printf("\nValor de um numero Decimal positivo inteiro: ");
				scanf("%d", &Dec);
				DecBina(Dec);
				break;
			case 'I':
				if(TLA>0 || TLB>0)
					SubConj(VetA, TLA, VetB, TLB);
				else{
					printf("\nNão é possivel realizar a operação!");
				}
				break;
			case 'J':
				if(TLA>0 || TLB>0)
					InteConj(VetA, TLA, VetB, TLB);
				else{
					printf("\nNão é possivel realizar a operação!");
				}
				break;
			case 'K':
				if(TLA>0 || TLB>0)
					MERGE(VetA, TLA, VetB, TLB);
				else{
					printf("\nNão é possivel realizar a operação!");
				}
				break;
			case 'L':
				
				break;
			case 'M':
				
				break;
			case 'N':
				
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
	printf("\n[F] Soma de todos os Elementos");
	printf("\n[G] Valor no está Contido no Vetor");
	printf("\n[H] Decimal para Binario");
	printf("\n[I] Soma Conjunto");
	printf("\n[J] Intersecção de Conjuntos");
	printf("\n[K] MERGE");
	printf("\n[L]");
	printf("\n[M]");
	printf("\n[N]");
	printf("\n[ESC] Sair");
	return toupper(getche());
}

int main(){
	Executar();
}
