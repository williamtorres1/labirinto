#include <stdio.h>
void mensagens(int situacao_agora, int player, int passos)
//situacao_agora == recebera um valor inteiro para determinar qual mensagem será mostrada || player == int p/ identificar qual player || quantos passos serão dados e quantos restam
{
	switch(situacao_agora)
	{
		case 1:
		{	printf("Player %d pode dar: %d passos",player,passos);
			break;
		}
		case 2:
		{	printf("Player %d encontrou uma tocha!",player);
			break;
		}
		case 3:
		{	printf("Player %d perdeu 1 Health Point",player);
			break;
		}
		case 4:
		{	printf("Player %d encontrou o tesouro!",player);
			break;
		}
		case 5:
		{	printf("Player %d GANHOU!! PARABÉNS",player);
			break;
		}
	}
}
char mapa()			//Ainda estou com muitas duvida sobre como  utilizar vetores e matrizes
{
	char mapa1[12][12]
	{
	'X','X','X','X','X','X','X','X','X','X','X','X',
	'X','*','*','*','*','*','*','*','*','*','*','X',
	'X','*','*','*','*','*','*','*','*','*','*','X',	
	'X','*','*','*','*','*','*','*','*','*','*','X',	
	'X','*','*','*','*','*','*','*','*','*','*','X',	
	'X','*','*','*','*','*','*','*','*','*','*','X',
	'X','*','*','*','*','*','*','*','*','*','*','X',
	'X','*','*','*','*','*','*','*','*','*','*','X',
	'X','*','*','*','*','*','*','*','*','*','*','X',
	'X','*','*','*','*','*','*','*','*','*','*','X',
	'X','*','*','*','*','*','*','*','*','*','*','X',
	'X','X','X','X','X','X','X','X','X','X','X','X'
	}
	
}
int main()
{
	
	return 1;
}
