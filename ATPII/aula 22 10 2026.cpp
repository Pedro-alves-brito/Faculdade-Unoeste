#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
void VerificarArquivo(char NomeArq[80]){
	FILE *PtrArq = fopen(NomeArq,"rb"); // leitura de arquivo em Binario
	if(PtrArq == NULL){// confere se eiste o arquivo e se não existir faz isso:
		printf("\nErrro de abertura!\n-Arquivo nao encontrado-\nDeseja cria-lo (S/N)");
		if(toupper(getch())=='S'){
			PtrArq = fopen(NomeArq,"wb");
			fclose(PtrArq);
			printf("\nO arquivo foi criado com sucesso!");
		}
	}
	else{
		printf("\nO arquivo foi encontrado com sucesso!");
		fclose(PtrArq);
	}
	getch();
}

int main(void){
	char Arquivo[80];
	printf("\nDigite o caminho do arquivo complet: ");
	fflush(stdin);
	gets(Arquivo);
	VerificarArquivo(Arquivo);
}
