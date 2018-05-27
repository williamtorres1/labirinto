#include <stdio.h>
void jogo()//Função principal do jogo
{
	do
	{
		
	}
	while(1);
}
int sorteio_passos()//Função para calcular quantos passos poderão ser realizados pelos jogadores
{
	int passos;
	return passos;
}
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
	int linhas=12,colunas=12;
	char mapa1[linhas][colunas]	// Modelo do labirito a ser percorrido, os caracteres 'X' são as paredes que não poderão ser atravessadas
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
	};
	
} 
int main()
{
	jogo();
	return 1;
}
