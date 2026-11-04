#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

struct TpProduto
{                  //32B
    int CodProd, Estoque;
    char Descr[20];
    float Preco;
};

int BuscaCODProd(FILE *PtrArq, int Codigo)
{
	TpProduto R;
	rewind(PtrArq); //Vai pro Inicio do Arquivo
	fread(&R,sizeof(TpProduto),1,PtrArq);
	while(!feof(PtrArq) && Codigo!=R.CodProd)
		fread(&R,sizeof(TpProduto),1,PtrArq);
	if(!feof(PtrArq)) // Ou pode perguntar isso: Codigo==R.CodProd
		return ftell(PtrArq)-sizeof(TpProduto);
	else
		return -1;
}

void CADProd(void)
{
	TpProduto RegProd;
	FILE *PtrProd = fopen("Produtos.dat","ab+");
	clrscr();
	printf("*** Cadastro de Produtos ***\n");
	printf("Codigo: ");
	scanf("%d",&RegProd.CodProd);
	while(RegProd.CodProd>0)
	{
		if(BuscaCODProd(PtrProd, RegProd.CodProd) == -1)
		{
			printf("Descricao: ");
			fflush(stdin);
			gets(RegProd.Descr);
			printf("Estoque: ");
			scanf("%d",&RegProd.Estoque);
			printf("Preco: R$ ");
			scanf("%f",&RegProd.Preco);
			fwrite(&RegProd,sizeof(TpProduto),1,PtrProd);		
		}
		else
			printf("\nCodigo ja Cadastrado!\n");
		
		Sleep(1000);
		printf("\nNovo Codigo: "); 
		scanf("%d",&RegProd.CodProd);
	}
	fclose(PtrProd);
}

void CONProd(void)
{
	int pos;
	TpProduto RegProd;
	FILE *PtrProd = fopen("Produtos.dat","rb");
	if(PtrProd == NULL)
		printf("\nErro de abertura!");
	else
	{
		clrscr();
		printf("*** Consulta de Produtos ***\n");
		printf("Codigo: ");
		scanf("%d",&RegProd.CodProd);
		while(RegProd.CodProd>0)
		{	
			pos = BuscaCODProd(PtrProd, RegProd.CodProd);
			if(pos != -1)
			{
				printf("\n\tDescricao\n");
				fseek(PtrProd,pos,0);
				fread(&RegProd,sizeof(TpProduto),1,PtrProd);
				printf("\nCodigo: %d - Descricao: %s - Estoque: %d - Preco: %.2f\n",RegProd.CodProd,RegProd.Descr,RegProd.Estoque,RegProd.Preco);		
			}
			else
				printf("\nProduto nao Cadastrado!\n");
			
			Sleep(1000);
			printf("\nNovo Codigo: "); 
			scanf("%d",&RegProd.CodProd);
		}
		fclose(PtrProd);
	}
}

void ALTPROD(void)
{
	int pos;
	TpProduto RegProd;
	FILE *PtrProd = fopen("Produtos.dat","rb+");
	if(PtrProd == NULL)
		printf("\nErro de abertura!");
	else
	{
		clrscr();
		printf("*** Consulta de Produtos ***\n");
		printf("Codigo: ");
		scanf("%d",&RegProd.CodProd);
		while(RegProd.CodProd>0)
		{	
			pos = BuscaCODProd(PtrProd, RegProd.CodProd);
			if(pos != -1)
			{
				printf("\n\tDescricao\n");
				fseek(PtrProd,pos,0);
				fread(&RegProd,sizeof(TpProduto),1,PtrProd);
				printf("\nCodigo: %d - Descricao: %s - Estoque: %d - Preco: %.2f\n",RegProd.CodProd,RegProd.Descr,RegProd.Estoque,RegProd.Preco);
				
				printf("\n\nAlterar dados (S/N)?");
				if(toupper(getche())=='S'){
					printf("Descricao: ");
					fflush(stdin);
					gets(RegProd.Descr);
					printf("Estoque: ");
					scanf("%d",&RegProd.Estoque);
					printf("Preco: R$ ");
					scanf("%f",&RegProd.Preco);
					fwrite(&RegProd,sizeof(TpProduto),1,PtrProd);
				}		
			}
			else
				printf("\nProduto nao Cadastrado!\n");
			
			Sleep(1000);
			printf("\nNovo Codigo: "); 
			scanf("%d",&RegProd.CodProd);
		}
		fclose(PtrProd);
	}
}

void RELProd(void)
{
	TpProduto RP;
	FILE *Ptr = fopen("Produtos.dat","rb");
	if (Ptr==NULL)
		printf("\nErro de abertura!\n");
	else
		{
			fread(&RP,sizeof(TpProduto),1,Ptr);
			while(!feof(Ptr))
			{		
				printf("%d - %s - %d - %.2f\n",RP.CodProd,RP.Descr,RP.Estoque,RP.Preco);
				fread(&RP,sizeof(TpProduto),1,Ptr);
			}
		}
			
	getch();
	fclose(Ptr);
}

int main(void)
{
	CADProd();
	RELProd();
	CONProd();
	return 0;
}
