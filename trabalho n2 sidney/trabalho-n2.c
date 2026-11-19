#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int numeros [3][5] = {
	{0,0,0,0,0},
	{0,0,0,0,0},//atribuir acentos vazios por padrão
	{0,0,0,0,0}
	};		
	int assentos;
	int sessao;
	float preco[3];
	int i, j; //criei essas variaveis de controle pra conseguir controlar melhor os loops (ela ta substituindo o antigo "numero")
	int menu;
	int erro;
	int sessaoCheia;
	int qtdAssentosLivres = 0, qtdAssentosReservados = 0, qtdAssentosLivresTotal = 0, qtdAssentosReservadosTotal = 0;
	float valorReservas = 0, valorReservasTotal = 0;
	
	printf("Antes de iniciar, escolha os preços das sessões: \n");
	for(i = 0; i < 3; i++){
		printf("Escolha o preço da %da sessão: ", i + 1);
		scanf("%f", &preco[i]);
	}
		
	printf("\nPreços das sessões: \n");
	for(i = 0; i < 3; i++){
		printf("\nSessão %d: %.2f",  i + 1, preco[i]);
	}
	
	printf("\n\n");
	do{
	printf("\n\n===MENU=== \n1 - Mostrar mapa de assentos \n2 - Reservar assento \n3 - Cancelar reserva \n4 - Mostrar resumo das sessões \n0 - Encerrar\n");
	scanf("%d", &menu);
		switch(menu){
		
		case 0:
			break;
			
		case 1:	//mostrar mapa de assentos
		printf("\n Mapa de assentos:\n");
		printf("Assento    1   2   3   4   5\n");
		for(i = 0; i < 3; i++){
		printf("Sessao %d:| ", i + 1);
			for(j = 0; j < 5; j++){
				printf("%d | ",numeros[i][j]);
			}
		printf("\n");
		}
		break;
		
		case 2: //reservar assento
			sessaoCheia = 0; //reseta a variavel sessaoCheia a cada sessão
			printf("Escolha sua sessão: \n");
			scanf("%d", &sessao);
			if(sessao < 1 || sessao > 3)// verifica se o numero escolhido para a sessão é válido
			{
				printf("Sessão invalida escolha uma sessão entre 1 e 3\n");
				continue;
			}
			for(i = 0; i < 5; i++) //atualizada o valor da variavel sessaoCheia para verificar se as sessões estão cheias
			{
				sessaoCheia += numeros[sessao - 1][i];
			}
				
			if(sessaoCheia == 5){
				printf("Sessão lotada! escolha outra sessão");
				continue;
			}else{
				
				printf("\nAssento    1   2   3   4   5\n");
				
				printf("Sessão %d:| ", sessao);
				for(i = 0; i < 5; i++){
					printf("%d | ",numeros[sessao - 1][i]);
				}
				
				do {
					printf("\nEscolha seu assento:\n");
					scanf("%d", &assentos);
					if(assentos < 1 || assentos > 5)// verifica se o numero escolhido para o assento é valido
					{
						printf("Assento inválido, escolha uma opção entre 1 e 5\n");
						continue;
					}
					if(numeros[sessao - 1][assentos - 1] == 0) // verifica se o numero escolhido para a sessão é valido
					{
						numeros[sessao - 1][assentos - 1] = 1;
						erro = 0;
					}else{
						printf("\nAssento ja reservado! escolha um assento válido ou escreva 0 para sair dessa aba\n");
						erro = 1;
					}	
				}while(assentos != 0 && erro == 1);
					
			}
			break;
		
		case 3: //cancelar reserva
		
			printf("Escolha sua sessão: \n");
			scanf("%d", &sessao);
			if(sessao < 1 || sessao > 3)// verifica se o numero escolhido para a sessão é válido
			{
				printf("Sessão invalida escolha uma sessão entre 1 e 3\n");
				continue;
			}
			
			printf("Escolha seu assento: \n");
			scanf("%d", &assentos);
			if(assentos < 1 || assentos > 5)// verifica se o numero escolhido para o assento é válido
			{
				printf("assento invalido escolha um assento entre 1 e 5\n");
				continue;
			}
			
			if(numeros[sessao - 1][assentos - 1] == 1)// verifica se o assento esta vazio ou cheio para cancelar
			{
				numeros[sessao - 1][assentos - 1] = 0;
				printf("Reserva cancelada!\n");
			}else{
				printf("Não existe reserva para esse assento, insira um assento válido!\n");
			}
			
			break;
			
		case 4: //mostrar resumo das sessões
		valorReservasTotal = 0;
		qtdAssentosLivresTotal = 0;
		qtdAssentosReservadosTotal = 0;
		
		for(i = 0; i < 3; i++){
			valorReservas = 0;
			qtdAssentosReservados = 0;
			qtdAssentosLivres = 0;
			for(j = 0; j < 5; j++){
				if(numeros[i][j] == 1){
					qtdAssentosReservados++;
					
				}else{
					qtdAssentosLivres++;
				} 
			}
			
			valorReservas = preco[i] * qtdAssentosReservados;
			
			printf("=====SESSÃO %d======\n", i + 1);
			printf("Quantidade de assentos livres: %d\n", qtdAssentosLivres);
			printf("Quantidade de assentos reservados: %d\n", qtdAssentosReservados);
			printf("Valor das reservas ativas da sessão: %.2f\n", valorReservas);
			printf("==================\n");	
			
			valorReservasTotal += valorReservas;
			qtdAssentosLivresTotal += qtdAssentosLivres;
			qtdAssentosReservadosTotal += qtdAssentosReservados;
			
		}
		printf("\n=====Geral=====\n");
		printf("Quantidade de assentos livres: %d\n", qtdAssentosLivresTotal);
		printf("Quantidade de assentos reservados: %d\n", qtdAssentosReservadosTotal);
		printf("Valor das reservas ativas da sessão: %.2f\n", valorReservasTotal);
		
		
		break;
		
		default:
		printf("Opção inválida. Escolha um menu de 1 a 4 ou 0 para encerrar");	
		}
	}while(menu != 0);

	
	

	
	
	
	
	return 0;
}
