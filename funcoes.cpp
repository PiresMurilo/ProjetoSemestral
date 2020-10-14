//FUNÇÃO MENU
typedef struct {
    int codigo;
    char nome[50];
    float preco;
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

};

FILE * arq;

float menu(void){
	arq = fopen("notaFiscal.TXT" , "w"); //ABRE O ARQUIVO
	
	setlocale(LC_ALL, "Portuguese");

	//CABEÇALHO DO ARQUIVO A SER GRAVADO
	fprintf(arq, "\n\t\t====================================================================\n");
	fprintf(arq, "\t\t|\t\t      Drive Thru Mickey & Donald       \t\t|\n");
	fprintf(arq, "\t\t--------------------------------------------------------------------\n");
	fprintf(arq, "\t\t    Produto          Valor unitario       Quantidade      Valor do pedido");
	

	//Apresentação inicial
	printf("\n\t\t|=======================================================|\n");
	printf("\t\t+-------------------[FACA SEU PEDIDO]-------------------+\n");
	printf("\t\t|=======================================================|\n\n");

	//Cardapio
	printf("\t\t=========================================================\n");
	printf("\t\t|\t\tDrive Thru Mickey & Donald\t\t|\n");
	printf("\t\t---------------------------------------------------------\n");
	printf("\t\t|  Código  |   \t\tProduto\t\t   |   Valor    |\t\n");
	printf("\t\t---------------------------------------------------------\n");
	printf("\t\t|=======================[Lanches]=======================|\n");
	printf("\t\t---------------------------------------------------------\n");
	printf("\t\t|     1    |   \t   Hambúrguer         \t   |  R$ 10,50  |\t\n");
	printf("\t\t|     2    |   \t   Batata Frita       \t   |  R$ 6,00   |\t\n");
	printf("\t\t|     3    |   \t   Cachorro Quente    \t   |  R$ 8,50   |\t\n");
	printf("\t\t|     4    |   \t   Nuggets            \t   |  R$ 8,50   |\t\n");
	printf("\t\t|     5    |   \t   Burguer Veggie     \t   |  R$ 10,75  |\t\n");
	printf("\t\t---------------------------------------------------------\n");
	printf("\t\t|=======================[Bebidas]=======================|\n");
	printf("\t\t---------------------------------------------------------\n");
	printf("\t\t|     6    |   \t  Refrigerante        \t   |  R$ 5,50   |\t\n");
	printf("\t\t|     7    |   \t  Suco                \t   |  R$ 4,00   |\t\n");
	printf("\t\t|     8    |   \t  Cerveja             \t   |  R$ 6,00   |\t\n");
	printf("\t\t|     9    |   \t  Água sem gas        \t   |  R$ 3,50   |\t\n");
	printf("\t\t|    10    |   \t  Água com gas        \t   |  R$ 4.00   |\t\n");
	printf("\t\t=========================================================\n");    


int i, quantidade, desejo;
float vrecebido, valorTotal = 0;	
		
	do{ 
		printf("\n\t\tDigite o código do produto: ");
		scanf("%i", &i);
		i--;
		printf("\n\t\t=============================");
		printf(" \n \t\tProduto: %s ", produto[i].nome);
		printf("\n\t\t============================= ");
		printf("\n\t\t=============================");
		printf(" \n \t\tPreço: %.2f ", produto[i].preco);
		printf("\n\t\t============================= \n");
		printf("\t\t============================= ");
		printf("\n\t\tQuantidade: ");
		scanf("%d", &quantidade);
		printf("\t\t============================= \n");
	
		float valorDoPedido = produto[i].preco*quantidade;
		printf("\n\t\t============================= \n");
		printf(" \t\tValor do Pedido: %.2f \n", valorDoPedido);
		printf("\t\t============================= \n\n");

		//GRAVAÇÃO DOS PEDIDOS NO ARQUIVO
		fprintf(arq, "\n\t\t%12s             %.2f              %3d               %.2f", produto[i].nome, produto[i].preco, quantidade, valorDoPedido);

		valorTotal = valorTotal + valorDoPedido;
			
		printf("\t\tDeseja mais alguma coisa? sim(1) ou nao(0): ");
    	fflush(stdin);
    	scanf("%i", &desejo);
		
	}while (desejo == 1); //PEDIDOS SERÃO FEITOS ENQUANTO O CLIENTE DESEJAR ALGO MAIS

	//ENCERRAMENTO DA GRAVAÇAO DO ARQUIVO
	fprintf(arq, "\n\n\t\t   Valor total do pedido: R$ %.2f", valorTotal);
	fprintf(arq, "\n\t\t====================================================================\n");
	fclose(arq);

return valorTotal;
}


//FUNÇÃO PAGAR
void pagamento(float valorTotal){
	setlocale(LC_ALL, "Portuguese");

	printf("\n\n\t\t============================= \n");
	printf(" \t\tValor a pagar: %.2f \n", valorTotal);
	printf("\t\t============================= \n\n");

	printf("\n\t\t|=================================================|\n");
	printf("\t\t+---------------------[PAGUE]---------------------+\n");
	printf("\t\t|=================================================|\n");

	printf("\n\t\t===================================================\n");
	printf("\t\t|            Drive Thru Mickey & Donald           |\n");
	printf("\t\t---------------------------------------------------\n");
	printf("\t\t|--------------[Formas de Pagamento]--------------|\n");
	printf("\t\t---------------------------------------------------\n");
	printf("\t\t|     1    |   \t  Dinheiro \t\t\t  |\n");
	printf("\t\t|     2    |   \t  Cartão de crédito/débito   \t  |\t\n");
	printf("\t\t|     3    |   \t  Cheque        \t          |\n");
	printf("\t\t===================================================\n");
	
	int opcao, cheque;
	printf("\n\t\tDigite a opção desejada: ");
	scanf("%i", &opcao);
	float valorRecebido, troco;

	switch(opcao){
		case 1:{
			//PAGAMENTO EM DINHEIRO
			printf("\n\t\t=============================");
			printf("\n\t\t Valor a pagar: R$ %.2f", valorTotal);
			printf("\n\t\t============================= \n");
			
			printf("\t\t============================= ");
			printf("\n\t\t Valor recebido: R$ ");
			scanf("%f", &valorRecebido);
			printf("\t\t============================= \n");
	
			troco = valorRecebido - valorTotal;
			if (troco > 0){
				printf("\n\t\t============================= \n");
				printf("\t\t Troco: R$ %.2f \n", troco);
				printf("\t\t============================= \n");
			}
			else{
				printf("\n\t\t============================= \n");
				printf("\n\t\t Não há troco \n");
				printf("\t\t============================= \n");
			}	
		}
		break;

		case 2:{
			int getch(void);
			//PAGAMENTO EM CARTAO
			printf("\n\t\t===============================");
			printf("\n\t\t Valor a pagar: R$ %.2f", valorTotal);
			printf("\n\t\t=============================== \n");
			
			int i;
    		char digito[16], senha[6];
			printf("\n\t\t===============================");
    		printf("\n\t\tDigite o número do seu cartão: \n");
			printf("               ");

			for(i=0; i<16; i++)
			{
				digito[i] = getch();
            	fflush(stdin);
            	printf("%c", digito[i]);

			}
			printf("\n\t\t===============================");
			printf("\n\t\t===============================");
			printf("\n\t\tDigite sua senha(seis digitos): \n");
			printf("\t\t");
			
			for(i=0; i<6 ;i++){
				fflush (stdin);
				senha[i] = getch();
				printf ("*");
				
			}

            printf("\n\t\t===============================");
			printf("\n\t\t===============================");
			printf("\n\t\tTransação aprovada!");
			printf("\n\t\t===============================\n");

/*  ISSO AQUI É APENAS NA PARTE DE REGISTRAR NO .DAT
    		for(i=0; i<16; i++)
    		{
				//TEM COMO DAR ESPAÇO AQUI????
				if(i > 4 && i < 13){
            	digito[i] = getch();
            	fflush(stdin);
            	printf("*");
        		}
        	else{
            	digito[i] = getch();
            	fflush(stdin);
            	printf("%c", digito[i]);
				}
       		}    
			printf("\n\t\t===============================");

    		printf("\n\t\tvisualizacao: ");
    		for(i=0; i<16; i++){
        	printf("%c", digito[i]);
        	} */
		}
		break;

		case 3:{
			do {
				
				printf("\n\t\t=============================");
				printf("\n\t\t Valor a pagar: R$ %.2f", valorTotal);
				printf("\n\t\t============================= \n");
			
				printf("\t\t============================= ");
				printf("\n\t\t Cheque foi recebido? sim(1) ou não(0) ");
				scanf("%i", &cheque);
				printf("\n\t\t============================= \n");

			} while (cheque == 0);

		}
		break;

		default: 
			printf("Opção inválida!");
			fflush(stdout);
			break;
		}

}