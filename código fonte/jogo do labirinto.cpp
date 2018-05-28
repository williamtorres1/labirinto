/******************************
*	File:Saturn Project	      *
*	Author: William Torres    *
*							  *
*							  *
******************************/


#include <stdio.h>
#include <stdlib.h>//Biblioteca necessária para gerar numeros aleatorios (passos e distribuicaoo das armadilhas, tochas e o tesouro
#include <conio.h>//Biblioteca para ler as teclas digitadas pelo usuario, com proposito de faze-lo percorrer o mapa(matriz)
#include <time.h>//Biblioteca para complementacao da funcao srand()


void sorteio_passos(int *Passos)//Funcao para calcular quantos passos poderao ser realizados pelos jogadores
{	zsrand(time(NULL));
	*Passos=3+rand()%10;	//esta funcao sera substituida por srand(time(NULL)), para sempre ter numeros aleatorios a cada execucao
							//mas para saber se o jogo esta funcionando, iremos trabalhar com valores constantes
}

void sorteio_distribuicao()
{	int num_trap=0;
	num_fire=rand()%32;
	for(int trap=0;trap<=num_trap;trap++)
	{	
		for()//laco para distribuir a
	}
	int num_tocha=0;
	num_tocha=rand()% ;
	for(int tocha=0;tocha<=num_tocha;tocha++)
	{
		for()//laco para distruibuir as tochas
	}
	int gold=1;
	where_gold=rand()%98;
	for()//Laco para distribuir o tesouro
}

void mensagens(int situacao_agora, int player, int passos)
//situacao_agora == recebera um valor inteiro para determinar qual mensagem sera mostrada
//player == int p/ identificar qual player || quantos passos serao dados e quantos restam
{
	switch(situacao_agora)
	{	
		case 1:
		{	printf("\t\t\tBem-vindo a caca ao Tesouro!\n");
			break;
		}
		case 2:
		{	printf("Player %d pode dar: %d passos",player,passos);
			break;
		}
		case 3:
		{	printf("Player %d encontrou uma tocha!",player);
			break;
		}
		case 4:
		{	printf("Player %d perdeu 1 Health Point",player);
			break;
		}
		case 5:
		{	printf("Player %d encontrou o tesouro!",player);
			break;
		}
		case 6:
		{	printf("Player %d GANHOU!! PARABENSS",player);
			break;
		}
	}
}


void mapa()			//Ainda estou com muitas duvida sobre como  utilizar vetores e matrizes
{	
	int linhas=12,colunas=12;
	char mapa1[linhas][colunas]	// Modelo do labirito a ser percorrido, os caracteres 'X' serao as paredes que noa poderao ser atravessadas
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


void player1()
{
	
}


void player2()
{
	
}


void jogo()//Funcao principal do jogo
{
	int passos,player;
	do
	{
		sorteio_passos(&passos);
		mensagens(1,0,0);
		mapa();
		mensagens(2,player,passos);
		break;
	}
	while(1);
}


int main()
{	
	
	jogo();
	putchar('\n');
	system("pause");
	getch();
	return 1;
}
