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
	int numero;
	int menu;
	
	printf("Antes de iniciar, escolha os preços das sessões: \n");
	for(numero = 0;numero < 3; numero++){
		printf("Escolha o preço da %da sessão: ", numero + 1);
		scanf("%f", &preco[numero]);
	}
		
	printf("\nPreços das sessões: \n");
	for(numero = 0; numero < 3; numero++){
		printf("\nSessão %d: %.2f",  numero + 1, preco[numero]);
	}
	
	printf("\n\n");
	do{
	printf("\n\n===MENU=== \n1 - Mostrar mapa de assentos \n2 - Reservar assento \n3 - Cancelar reserva \n4 - Mostrar resumo das sessões \n0 - Encerrar\n");
	scanf("%d", &menu);
		switch(menu){
		case 1:	//mostrar mapa de assentos
		printf("\n Mapa de assentos:\n");
		printf("Assento    1   2   3   4   5\n");
		for(sessao = 0; sessao < 3; sessao++){
		printf("Sessao %d:| ", sessao + 1);
			for(assentos = 0; assentos < 5; assentos++){
				printf("%d | ",numeros[sessao][assentos]);
			}
		printf("\n");
		}
		break;
		
		case 2: //reservar assento
		do{
			printf("Escolha sua sessão: \n");
			scanf("%d", &sessao);
	
			printf("Sua sessão: ");
			for(assentos = 0; assentos < 5; assentos++){
				printf("%d | ",numeros[sessao - 1][assentos]);
		}
	
		}while(sessao < 1 && sessao > 4);
	
	
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
