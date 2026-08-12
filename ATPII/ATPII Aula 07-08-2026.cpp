#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define tfp 30
#define tfc 10
#define tfv 500

int main(void){
	
	int estoque[tfp], tlp=0, tlc=0, tlv=0, x, y, venda[tfv][3],i;
	float preco[tfp];
	char produto[tfp][50], cliente[tfc][50], opcao, AuxProd[50];
	
	do{
		system("cls");
		printf("\n # # #   MENU   # # #");
		printf("\n [A] Cadastrar Produtos");
		printf("\n [B] Relatorio de Produto");
		printf("\n [C] Cadastrar Clientes");
		printf("\n [D] Relatorio de Cliente");
		printf("\n [E] Vender Produtos");
		printf("\n [ESC] Finalizar");
		printf("\n\n Opcao desejada: ");
		
		opcao = toupper(getch());
		
		switch(opcao){
			case 'A': system("cls");
				printf("Cadastro de Produto\n");
				printf("\n Nome:");
				fflush(stdin);
				gets(AuxProd);
				while(tlp<tfp && strlen(AuxProd)>0){
					
					strcpy(produto[tlp],AuxProd);
					printf("Preco: R%");
					scanf("%f",&preco[tlp]);
					printf("Estoque: R%");
					scanf("%d",&estoque[tlp]);
					tlp++;
					
					printf("\nNome:");
					fflush(stdin);
					gets(AuxProd);	
				}
				break;
			case 'B': system("cls");
				printf("Relatorio de Produto\n");
				if(tlp==0)
					printf("\nNão ha produtos!\n");
				else{
					for(i=0;i<tlp;i++)
					printf("\n%s \t R$%.2f \t %d", produto[1],preco[i,estoque[i]]);
				}
				getch();
				break;
			case 'C': system("cls");
				printf("Cadastro de Clientes\n");
				break;
			case 'D': system("cls");
				printf("Relatorio de Clientes\n");
				break;
			case 'E': system("cls");
				printf("Vender Produtos\n");
				break;
		}
	}while(opcao != 27);
	return 0;
}
