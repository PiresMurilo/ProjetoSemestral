/*-------------------------------------------------------------------
+ Programa: Sistema de gerenciamento do drivethru Mickey & Donald
+ Autor: Murilo S. Pires
+ Prontuário: SP3052737
+ Descrição: O sistema tem por objetivo realizar a venda de produtos
  alimentícios, gerenciando a oferta (menu de produtos), o pedido do
  cliente, a forma de pagamento e a fila de atendimentos.
+ Disciplina: LG1A1 - Lógica de Programação  
+ Professor: André Evandro Lourenço
--------------------------------------------------------------------*/ 

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <termios.h> //substitutas da conio.h
#include <unistd.h>
#include "funcoes.cpp" //funções criadas por mim

/*
typedef struct {
    int codigo;
    char nome[50];
    float preco;
    //int quantidade;
}infos;

infos produto[10] = 
{
    {1, "Hamburguer", 10.50,},
    {2, "Batata Frita", 6.00,},
    {3, "Cachorro Quente", 8.50,},
    {4, "Nuggets", 8.50,},
    {5, "Burguer Veggie", 10.75,},
    {6, "Refrigerante", 5.50,},
    {7, "Suco", 4.50,},
    {8, "Cerveja", 6.00,},
    {9, "Agua sem gas", 3.50,},
    {10, "Agua com gas", 4.00,}

}; */


int modulo;
float valorTotal;

int main(){
    int getch(void);
    setlocale(LC_ALL, "Portuguese");

	printf("\n\t\tOlá, seja muito bem vindo ao Drive Thru Mickey & Donald! \n");

    //Início
	do{
	printf("\n\t\t=========================================\n");
	printf("\t\t|\tDrive Thru Mickey & Donald\t|\n");
	printf("\t\t-----------------------------------------\n");
	printf("\t\t|---------------[Módulos]---------------|\n");
	printf("\t\t-----------------------------------------\n");
	printf("\t\t|     1    |   \t  Faça seu pedido \t|\n");
	printf("\t\t|     2    |   \t  Pague        \t        |\t\n");
	printf("\t\t|     3    |   \t  Fila         \t        |\n");
	printf("\t\t|     4    |   \t  Leve         \t        |\n");
	printf("\t\t|     5    |   \t  Sair         \t        |\n");
	printf("\t\t=========================================\n");

	printf("\n\t\tSelecione o módulo desejado: "); // Switch case pra escolha dos modulos
    scanf("\t\t%i", &modulo);
    
	switch(modulo){
		case 1:{
			//Nesse caso o programa rodará todos os módulos desde o 1
			valorTotal = menu();
			pagamento(valorTotal);
			break;
		}
		break;

		case 2:{
			//Caso a pessoa queira começar a partir do módulo 2
			
			printf("\n\t\tDigite o valor total do pedido: R$ ");
			scanf("%f", &valorTotal);
			pagamento(valorTotal); 
			
		}
		break;

		case 3:{
			//função modulo 3
		}
		break;

		case 4:{
			// função modulo 4
		}
		break;

		case 5:{
			exit(0);
		}
		break; 

		default:{
			printf("\n \t\tOpção inválida!");
			printf ("\n \t\tPressione qualquer tecla para voltar as opções de módulo");
			getch();
		}
			
	}
	}while(modulo != 5); //vai ficar em loop enquanto não for digitada a opção de sair
    

    return 0;
}

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

/* HEADERS PARA OS MODULOS
printf("\n\t\t|=======================================================|\n");
printf("\t\t+------------------------[PAGUE]------------------------+\n");
printf("\t\t|=======================================================|\n\n");

printf("\n\t\t|=======================================================|\n");
printf("\t\t+------------------------[FILA]-------------------------+\n");
printf("\t\t|=======================================================|\n\n");

printf("\n\t\t|=======================================================|\n");
printf("\t\t+-----------------------[ENTREGA]-----------------------+\n");
printf("\t\t|=======================================================|\n\n");
*/