#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct TpProduto{
	// 32 bytes
	int CodProd,Estoque;
	char Descr[20];
	float Preco;
};

void CADProd(void){
	TpProduto RegProd;
	FILE *PtrProd = fopen("Produtos.dat","ab+");
	clrscr();
	printf("*** CADASTRO DE PRODUTOS ***");
	printf("\n\nCodigo: "); scanf("%d", &RegProd.CodProd);
	while(RegProd.CodProd>0)
	{
		printf("Descricao: "); fflush(stdin);
		gets(RegProd.Descr);
		printf("Estoque: "); scanf("%d", &RegProd.Estoque);
		printf("Preco: "); scanf("%f", &RegProd.Preco);
		fwrite(&RegProd,sizeof(TpProduto),1,PtrProd);
		// 1° é onde vai guardar, 2° o tamanho, 3° o quanto vai gravar, 4° quem é o buffer
		
		clrscr();
		printf("*** CADASTRO DE PRODUTOS ***");
		printf("\n\nCodigo: "); scanf("%d", &RegProd.CodProd);
	}
	fclose(PtrProd);
}

void RELProd(void){
	TpProduto RP;
	FILE *Ptr = fopen("Produtos.dat","rb");
	if(Ptr==NULL)
		printf("\nEroo de abertura!\n");
	else{
		fread(&RP,sizeof(TpProduto),1,Ptr);
		while(!feof(Ptr)){
			printf("%d - %s - %d - $2.f\n",RP.CodProd,RP.Descr,RP.Estoque,RP.Preco);
			fread(&RP,sizeof(TpProduto),1,Ptr);
		}
	}
	
	getch();
	fclose(Ptr);
}

int main(void){
	CADProd();
	RELProd();
	return 0;
}
