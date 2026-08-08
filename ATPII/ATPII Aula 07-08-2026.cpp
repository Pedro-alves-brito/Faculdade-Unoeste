#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#define tfp 30
#define tfc 10
#define tfv 500

int main(void){
	
	int estoque[tfp], tlp=0, tlc=0, tlv=0, x, y, venda[tfv][3];
	float preco[tfp];
	char produto[tfp][50], cliente[tfc][50], opcao;
	
	do{
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
			case 'A': printf("Cadastro de Produto\n");
				break;
			case 'B': printf("Relatorio de Produto\n");
				break;
			case 'C': printf("Cadastro de Clientes\n");
				break;
			case 'D': printf("Relatorio de Clientes\n");
				break;
			case 'E': printf("Vender Produtos\n");
				break;
		}
		
	}while(opcao != 27);
	return 0;
}
