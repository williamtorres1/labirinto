/****************************
*   File:   Saturn Project  *
*   Author: William Torres  *
*****************************/
#include <stdio.h>//Biblioteca p/ funcao printf e putchar
#include <stdlib.h>//"" p/ funcao rand( ) - gerar numeros aleatorios (passos e distribuicaoo das armadilhas, tochas e o tesouro
#include <conio.h>//""p/ getch ( ) - ler as teclas digitadas pelo usuario, com proposito de faze-lo percorrer o mapa(matriz)
#include <time.h>//""p/ complementacao da funcao srand(time(NULL))
#include <windows.h>//""p/ funcao sleep(1) - esperar algum tempo e o programa voltar a executar as proximas linhas
#include "mov1.h"
#include "mov2.h"
#include "show_map.h"
#include "menu.h"
void sorteio_passos(int *passos)/**Funcao p/ sortear quantos passos serao realizados pelos jogadores*/
{	do
	{
		*passos=rand()%11;
	}while(*passos > 10 || *passos < 3 );/**Valor sorteado deve estar entre 3 e 10, sendo a condicao verdadeira, o laco termina **/
}

void distribuicao(int mapa1[][12])/**Funcao p/ distribuir as armadilhas, tochas e o ouro dentro do mapa
Foi criada uma funcao, para os elementos nao alterarem durante a execucao do programa */
{
    int trap=0,num_trap=0,where_trap=0;//trap = armadilhas, num_trap = numero de armadilhas
                                       //where_trap = chance de conter uma armadilha naquele elemento da matriz [i][j]
    int tochas=0,num_tocha=0,where_tocha=0;//mesma logica das armadilhas
    int ouro=0,where_ouro=0;//ouro = tesouro
                            //mesma l�gica das armadilhas, mas podendo conter somente um ouro no mapa, e PRECISA TER UM tesouro
    mapa1[1][1]=9;
    mapa1[1][10]=9;
    mapa1[10][1]=9;
    mapa1[10][10]=9;
     //ARMADILHAS
    do      //laco para o numero de armadilhas nao passar de 32
    {num_trap=rand()%33;
	}while(num_trap>32);
    for(int i=1;i<11;i++)
        for(int j=1;j<11;j++)
        {
            do      //laco para sortear a chance de cair uma armmadilha num elemento da matriz
                    //nao podendo exceder 100
            {
                where_trap=rand()%101;
            }while(where_trap>101);
            //Quando sortear um valor entre 0 e 100, ir� fazer a an�lise abaixo
            //Para uma trap ser colocada em um elemento da matriz, o numero sorteado precisa ser entre 0 e 25
            //O numero de traps colocadas n�o deve exceder o numero sorteado de traps
                if(where_trap <= 25 && where_trap > 0 && trap < num_trap && mapa1[i][j] == 1)
                {
                    //Sendo tudo verdadeiro, colocaremos a tocha naquela posi��o e adicionaremos +1 na variavel trap
                    //ou seja, o loop n�o precisar� ser realizado mais alguma vez
                    mapa1[i][j]=2;
                    trap++;
                }
            }

    //TOCHAS
    do      //laco para o numero de tochas nao passar de 5
    {num_tocha=rand()%6;
	}while(num_tocha>5);
        for(int i=2;i<10;i++)
            for(int j=1;j<11;j++)
            {do      //laco para sortear a chance de cair uma tocha num elemento da matriz nao podendo exceder 100
                {where_tocha=rand()%101;
                }while(where_tocha>101);
                /**Quando sortear um valor entre 0 e 100, ir� fazer a an�lise abaixo**/
                /**Para uma tocha ser colocada em um elemento da matriz, o numero sorteado precisa ser entre 0 e 15
                  O numero tochas colocadas n�o deve exceder o numero sorteado de tochas
                  E n�o pode colocar uma tocha se j� colocarmos uma tocha antes naquele local*/
                if(where_tocha <= 15     && where_tocha > 0 && tochas < num_tocha && mapa1[i][j] == 1)
                {   /**Sendo tudo verdadeiro, colocaremos a tocha naquela posi��o e adicionaremos +1 na variavel tochas
                       ou seja, o loop n�o precisar� ser realizado mais alguma vez**/
                    mapa1[i][j]=3;
                    tochas++;
                }
            }

    //OURO
    do
    {for(int i=2;i<10;i++)
        	for(int j=1;j<11;j++)
        		{
				do
                {where_ouro=rand()%101;
                }while(where_ouro>101);
                if(where_ouro == 1 && ouro < 1 && mapa1[i][j] == 1)
                    {   mapa1[i][j]=4;
                        ouro++;
                    }
                }
	}while(ouro<1);
}

void escolha_player(int player)
{
    printf("Jogador %d, onde deseja comecar a jogar?\n",player);
	printf("||  ==   ==   ==   ==   ==   ==   ==  ==  ==  ==  ||\n||  1    --   --   --   --   --   --  --  --  2   ||\n");
	for(int i = 0 ; i < 8 ; i++)
/** Este laco eh so para economizar linhas, como temos 8 linhas que serao repetidas, por que nao usar um laco?  */
            printf("||  --   --   --   --   --   --   --  --  --  --  ||\n");
	printf("||  3    --   --   --   --   --   --  --  --  4   ||\n||  ==   ==   ==   ==   ==   ==   ==  ==  ==  ==  ||\n");
}
void map()
{
    int x=1,y=1,w=1,z=10;
/** X e Y = Coordenadas do Player I
    W e Z = Coordenadas do Player II                    */
    int init_x = x, init_y = y, init_w = w, init_z = z;
/** init_x e init_y = Coordenadas iniciais do Player I
 *  init_w e  init_z = Coordendas iniciais do Player II */
    int user1=0,user2=0;
/*  user1 e user2 = Variaveis para fazer os jogadores escolherem onde irao comecar a jogar */
	int mapa1[12][12]//numero de linhas e colunas da matriz
	{
    {8,0,0,0,0,0,0,0,0,0,0,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,1,1,1,1,1,1,1,1,1,1,8},
    {8,0,0,0,0,0,0,0,0,0,0,8},
    /*
    [i][j]
	[0][0] [0][1] [0][2] [0][3] [0][4] [0][5] [0][6] [0][7] [0][8] [0][9] [0][10] [0][11]
	[1][0] [1][1] [1][2] [1][3] [1][4] [1][5] [1][6] [1][7] [1][8] [1][9] [1][10] [1][11]
	[2][0] [2][1] [2][2] [2][3] [2][4] [2][5] [2][6] [2][7] [2][8] [2][9] [2][10] [2][11]
	[3][0] [3][1] [3][2] [3][3] [3][4] [3][5] [3][6] [3][7] [3][8] [3][9] [3][10] [3][11]
	[4][0] [4][1] [4][2] [4][3] [4][4] [4][5] [4][6] [4][7] [4][8] [4][9] [4][10] [4][11]
	[5][0] [5][1] [5][2] [5][3] [5][4] [5][5] [5][6] [5][7] [5][8] [5][9] [5][10] [5][11]
	[6][0] [6][1] [6][2] [6][3] [6][4] [6][5] [6][6] [6][7] [6][8] [6][9] [6][10] [6][11]
	[7][0] [7][1] [7][2] [7][3] [7][4] [7][5] [7][6] [7][7] [7][8] [7][9] [7][10] [7][11]
	[8][0] [8][1] [8][2] [8][3] [8][4] [8][5] [8][6] [8][7] [8][8] [8][9] [8][10] [8][11]
	[9][0] [9][1] [9][2] [9][3] [9][4] [9][5] [9][6] [9][7] [9][8] [9][9] [9][10] [9][11]
	[10][0] [10][1] [10][2] [10][3] [10][4] [10][5] [10][6] [10][7] [10][8] [10][9] [10][10] [10][11]
	[11][0] [11][1] [11][2] [11][3] [11][4] [11][5] [11][6] [11][7] [11][8] [11][9] [11][10] [11][11]
*/
    };
    distribuicao(mapa1);
    system("cls");
	escolha_player(1);
/** Este eh o procedimento somente para mostrar o mapa ao jogador, escolhi criar ele, porque estava ocupando muitas linhas
    O numero (1) como argumento eh p/ as mensagens serem direcionadas ao player I           */
	scanf("%d",&user1);//user1=getch() - '0';
/** Se o player I escolher algumnumero entre 1 e 4, ira alterar as variaveis x e y(Coordendas do jogador I)
    */
	if(user1 == 1 || user1 == 2 || user1 == 3 || user1 == 4)
    {   if(user1==1)
        {   x=1;
            y=1;
        }
        if(user1==2)
        {   x=1;
            y=10;
        }
        if(user1==3)
        {   x=10;
            y=1;
        }
        if(user1==4)
        {   x=10;
            y=10;
        }
    }
/** Se o Jogador digitar algum valor errado, ele ira iniciar o jogo a partir das coordenadas padrão */
    else
    {   x=1;
        y=1;
    }
    system("cls");
    escolha_player(2);
	scanf("%d",&user2);//user2=getch() - '0';
/** Mesma coisa do algoritmo acima, porem a posicao escolhida tem de ser diferente da escolhida pelo jogador 1
 *  Se o jogador 1 digitar algum valor invalido, ele comecara da linha 1 e coluna 1
 *  Logo, o Jogador II nao podera comecar nessa posicao                             */
	if(user2 == 1 || user2 == 2 || user2 == 3 || user2 == 4 || user2 != user1)
    {   if(user2==1)
        {   w=1;
            z=1;
        }
        if(user2==2)
        {   w=1;
            z=10;
        }
        if(user2==3)
        {   w=10;
            z=1;
        }
        if(user2==4)
        {   w=10;
            z=10;
        }
        if(user2 == user1)
        {   w=1;
            z=10;
        }
    }
    else
    {   w=1;
        z=10;
    }
	init_x=x;   init_y=y;   init_w = w; init_z=z;
/*  Enviar o init_x e etc como argumento para o procedimento show_map(), para mostrar onde os jogadores escolheram iniciar */
	while(1)
	{
	    show_map(mapa1);

        movimentacao1(init_x,init_y,&x,&y,mapa1);
        movimentacao2(init_w,init_z,&w,&z,mapa1);
    }
}
int main()
{
    /**srand(time(NULL));//Enquanto o programa não está pronto, deixe esta linha do jeito que está
        Esta linha vai deixar os elementos da matriz totalmente aleatórios              */
    char user=0;
    menu(&user);
    if(user == 'a' || user == 'A')
        map();
    system("pause");
    return 1;
}
