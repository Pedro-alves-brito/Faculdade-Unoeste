#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

struct TpProduto
{                  //33B
    int CodProd, Estoque;
    char Descr[20], Status;
    float Preco;
};

int BuscaCODProd(FILE *PtrArq, int Codigo)
{
	TpProduto R;
	rewind(PtrArq); //Início do Arquivo
	fread(&R,sizeof(TpProduto),1,PtrArq);
	while (!feof(PtrArq) && (Codigo!=R.CodProd || R.Status! ='A'))
		fread(&R,sizeof(TpProduto),1,PtrArq);
		
	if (!feof(PtrArq))
		return ftell(PtrArq)-sizeof(TpProduto);
	else
		return -1;
}

void CADProd(void)
{
	TpProduto RegProd;
	FILE *PtrProd = fopen("Prod.dat","ab+");
	clrscr();
	printf("*** CADASTRAR Produtos ***\n");
	printf("Novo Codigo: ");  scanf("%d",&RegProd.CodProd);
	while(RegProd.CodProd>0)
	{
		if (BuscaCODProd(PtrProd,RegProd.CodProd) == -1) //não achou!
		{
			printf("Descricao: ");
			fflush(stdin);
			gets(RegProd.Descr);
			printf("Estoque: ");
			scanf("%d",&RegProd.Estoque);
			printf("Preco: R$ ");
			scanf("%f",&RegProd.Preco);
			RegProd.Status = 'A';
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

void RELProd(void)
{
	TpProduto RP;
	FILE *Ptr = fopen("Prod.dat","rb");
	clrscr();
	printf("\n### Relatorio de Produtos ###\n");
	if (Ptr==NULL)
		printf("\nErro de abertura!\n");
	else
		{
			fread(&RP,sizeof(TpProduto),1,Ptr);
			while(!feof(Ptr))
			{		
				if(RP.Status =='a')
				{
					printf("%d - %s - %d - %.2f\n",RP.CodProd,RP.Descr,RP.Estoque,RP.Preco);
					fread(&RP,sizeof(TpProduto),1,Ptr);
				}
			}
			fclose(Ptr);
		}		
	getch();
}

void CONSProd(void)
{
	TpProduto RP;
	int pos;
	FILE *PtrProd = fopen("Prod.dat","rb");
	clrscr();
	printf("\n### CONSULTAR Produtos pelo Codigo ###\n");
	if (PtrProd == NULL)
	{
		printf("\nErro de abertura!\n");
		getch();
	}
	else
		{
			printf("\nCodigo: ");
			scanf("%d",&RP.CodProd);
			while(RP.CodProd>0)
			{
				pos = BuscaCODProd(PtrProd,RP.CodProd);
				if (pos != -1)
				{
					printf("\n*** Detalhes do Produto ***\n");
					fseek(PtrProd,pos,0);
					fread(&RP,sizeof(TpProduto),1,PtrProd);
					printf("Codigo: %d\n",RP.CodProd);
					printf("Descricao: %s\n",RP.Descr);
					printf("Estoque: %d\n",RP.Estoque);
					printf("Preco: R$ %.2f\n",RP.Preco);
				}
				else
					printf("\nProduto nao Cadastrado!\n");
			
				Sleep(1000);
				printf("\nCodigo: ");
				scanf("%d",&RP.CodProd);
			}
			fclose(PtrProd);
		}
}

void ALTProd(void)
{
	TpProduto RP;
	int pos;
	FILE *PtrProd = fopen("Prod.dat","rb+");
	clrscr();
	printf("\n### ALTERAR Produtos pelo Codigo ###\n");
	if (PtrProd == NULL)
	{
		printf("\nErro de abertura!\n");
		getch();
	}
	else
		{
			printf("\nCodigo: ");
			scanf("%d",&RP.CodProd);
			while(RP.CodProd>0)
			{
				pos = BuscaCODProd(PtrProd,RP.CodProd);
				if (pos != -1)
				{
					printf("\n*** Detalhes do Produto ***\n");
					fseek(PtrProd,pos,0);
					fread(&RP,sizeof(TpProduto),1,PtrProd);
					printf("Codigo: %d\n",RP.CodProd);
					printf("Descricao: %s\n",RP.Descr);
					printf("Estoque: %d\n",RP.Estoque);
					printf("Preco: R$ %.2f\n",RP.Preco);
					
					printf("\nAlterar dados (S/N)? ");
					if(toupper(getche())=='S')
					{
						printf("NOVA Descricao: ");
						fflush(stdin);
						gets(RP.Descr);
						printf("NOVO Estoque: ");
						scanf("%d",&RP.Estoque);
						printf("NOVO Preco: R$ ");
						scanf("%f",&RP.Preco);
						//Posicionar no arquivo e Gravar os novos dados
						fseek(PtrProd,pos,0);
						fwrite(&RP,sizeof(TpProduto),1,PtrProd);
						printf("\nProduto ALTERADO com Suceeeesso!\n");
					}
				}
				else
					printf("\nProduto nao Cadastrado!\n");
			
				Sleep(1000);
				printf("\nCodigo: ");
				scanf("%d",&RP.CodProd);
			}
			fclose(PtrProd);
		}
}

void EXCLOGProd(void)
{
	TpProduto RP;
	int pos;
	FILE *PtrProd = fopen("Prod.dat","rb+");
	clrscr();
	printf("\n### EXCLUIR Produtos pelo Codigo ###\n");
	if (PtrProd == NULL)
	{
		printf("\nErro de abertura!\n");
		getch();
	}
	else
		{
			printf("\nCodigo: ");
			scanf("%d",&RP.CodProd);
			while(RP.CodProd>0)
			{
				pos = BuscaCODProd(PtrProd,RP.CodProd);
				if (pos != -1)
				{
					printf("\n*** Detalhes do Produto ***\n");
					fseek(PtrProd,pos,0);
					fread(&RP,sizeof(TpProduto),1,PtrProd);
					printf("Codigo: %d\n",RP.CodProd);
					printf("Descricao: %s\n",RP.Descr);
					printf("Estoque: %d\n",RP.Estoque);
					printf("Preco: R$ %.2f\n",RP.Preco);
					
					printf("\nExcluir dados (S/N)? ");
					if(toupper(getche())=='S')
					{
						RP.Status ='I';
						//Posicionar no arquivo e Gravar os novos dados
						fseek(PtrProd,pos,0);
						fwrite(&RP,sizeof(TpProduto),1,PtrProd);
						printf("\nProduto EXCLUIDO com Suceeeesso!\n");
					}
				}
				else
					printf("\nProduto nao Cadastrado!\n");
			
				Sleep(1000);
				printf("\nCodigo: ");
				scanf("%d",&RP.CodProd);
			}
			fclose(PtrProd);
		}
}

void EXCFISProd(void)
{
	TpProduto RP;
	int pos, Codigo;
	FILE *PtrProd = fopen("Prod.dat","rb");
	clrscr();
	if (PtrProd == NULL)
	{
		printf("\nErro de abertura!\n");
		getch();
	}
	else
		{
			FILE *PtrTemp = fopen("Temp.dat","wb");
			fseek(PtrProd,0,0); //rewind(PtrProd);
			fread(&RP,sizeof(TpProduto),1,PtrProd);
			while(!feof(PtrProd))
			{
				if (RP.Status != 'I')
						fwrite(&RP,sizeof(TpProduto),1,PtrTemp);
					
				fread(&RP,sizeof(TpProduto),1,PtrProd);
			}
			fclose(PtrTemp);
			fclose(PtrProd);
			remove("Produtos.dat"); 
			rename("Temp.dat","Prod.dat");
		}
}

int main(void)
{
	CADProd();
	RELProd();
	CONSProd();
	ALTProd();
	RELProd();
	EXCLOGProd();
	RELProd();
	EXCFISProd();
	RELProd();
	return 0;
}
