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
			do{
				printf("Escolha sua sessão: \n");
				scanf("%d", &sessao);
				if(sessao < 1 && sessao > 3){
					printf("Sessão invalida escolha uma sessão entre 1 e 3\n");
				}
			} while(sessao < 1 && sessao > 4);
			printf("\nAssento    1   2   3   4   5\n");
			
			printf("Sessão %d:| ", sessao);
			for(i = 0; i < 5; i++){
				printf("%d | ",numeros[sessao - 1][i]);
			}
			
			do {
				printf("\nEscolha seu assento:\n");
				scanf("%d", &assentos);
				if(numeros[sessao - 1][assentos - 1] == 0){
					numeros[sessao - 1][assentos - 1] = 1;
					erro = 0;
				} else{
					printf("\nAssento ja reservado! escolha um assento válido ou escreva 0 para sair dessa aba\n");
					erro = 1;
				}
				
			} while(assentos != 0 && erro == 1);	

	
		break;
		
		case 3: //cancelar reserva
		
		break;
		case 4: //mostrar resumo das sessões
		
		break;
		
		default:
		printf("Opção inválida. Escolha um menu de 1 a 4 ou 0 para encerrar");	
		}
	}while(menu != 0);

	
	

	
	
	
	
	return 0;
}
