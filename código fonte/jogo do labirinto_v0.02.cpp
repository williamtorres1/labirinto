#include <stdio.h>//Biblioteca p/ printf e putchar
#include <stdlib.h>//Biblioteca necessaria para gerar numeros aleatorios (passos e distribuicaoo das armadilhas, tochas e o tesouro
#include <conio.h>//Biblioteca para ler as teclas digitadas pelo usuario, com proposito de faze-lo percorrer o mapa(matriz)
#include <time.h>//Biblioteca para complementacao da funcao srand()
#include <windows.h>//sleep
int sorteio_passos(int *passos)
{
	do
	{
		*passos=rand()%11;
	}while(*passos > 10 || *passos < 3 );
}
void messages(int situacao,int player)
{
	switch(situacao)
	{
		case 1:
		{
			printf("\t\t\tBem-vindo a caca ao Tesouro!\n\n\n");
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
		{	printf("Player %d GANHOU!! PARABENSS",player);
			break;
		}
	}
}
void show_map(int mapa2[12][12])
{
	system("cls");
	system("color b");
    mapa2[1][1]=5;
    mapa2[1][10]=6;
    messages(1,0);
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<12;j++)
        {
            if(mapa2[i][j]==0)
                printf(" == ");
            if(mapa2[i][j]==1||mapa2[i][j]==2||mapa2[i][j]==3||mapa2[i][j]==4)
                printf(" -- ");
            if(mapa2[i][j]==5)
              printf(" P1 ");
            if(mapa2[i][j]==6)
              printf(" P2 ");
            if(mapa2[i][j]==7)
              printf("    ");
            if(mapa2[i][j]==8)
                printf(" || ");
            if(mapa2[i][j]==9)
                printf(" <  >");
        }
        putchar('\n');
    }
}
void distribuicao(int mapa1[][12])
{
    int trap=0,num_trap=0,where_trap=0;//trap = armadilhas, num_trap = numero de armadilhas
                                       //where_trap = chance de conter uma armadilha naquele elemento da matriz [i][j]
    int tochas=0,num_tocha=0,where_tocha=0;//mesma logica das armadilhas
    int ouro=0,where_ouro=0;//ouro = tesouro
                            //mesma lógica das armadilhas, mas podendo conter somente um ouro no mapa, e PRECISA TER UM tesouro
     //ARMADILHAS
    do      //laco para o numero de armadilhas nao passar de 32
    {
        num_trap=rand()%32;
	}while(num_trap>32);
	printf(" \nTerao %d Armadilhas",num_trap);
  //printf p/ poder contar no mapa se as armadilhas estao funcionando
    for(trap=0;trap<num_trap;trap++)
  //laco para distribuir as armadilhas, sem ultrapassar o numero sorteado
        for(int i=2;i<10;i++)
            for(int j=1;j<11;j++)
            {
                do      //laco para sortear a chance de cair uma armmadilha num elemento da matriz
                        //nao podendo exceder 100
                {
                    where_trap=rand()%101;
                }while(where_trap>101);
                //Quando sortear um valor entre 0 e 100, irá fazer a análise abaixo
                //Para uma trap ser colocada em um elemento da matriz, o numero sorteado precisa ser entre 0 e 25
                //O numero de traps colocadas não deve exceder o numero sorteado de traps
                if(where_trap<=25 && trap<num_trap)
                {
                    //Sendo tudo verdadeiro, colocaremos a tocha naquela posição e adicionaremos +1 na variavel trap
                    //ou seja, o loop não precisará ser realizado mais alguma vez
                    mapa1[i][j]=2;
                    trap++;
                }
            }
    //TOCHAS
    do      //laco para o numero de tochas nao passar de 5
    {
        num_tocha=rand()%5;
	}while(num_tocha>5);
	printf(" \nTerao %d Tochas\n\n",num_tocha);
	//printf para conferirmos se as tochas foram colocadas corretamente(em numero e local)

    do    //laco para distribuir as tochas, sem ultrapassar o numero sorteado
    {
        for(int i=2;i<10;i++)
            for(int j=1;j<11;j++)
            {
                do      //laco para sortear a chance de cair uma tocha num elemento da matriz nao podendo exceder 100
                {
                    where_tocha=rand()%101;
                }while(where_tocha>101);
                //Quando sortear um valor entre 0 e 100, irá fazer a análise abaixo
                //Para uma tocha ser colocada em um elemento da matriz, o numero sorteado precisa ser entre 0 e 15
                //O numero tochas colocadas não deve exceder o numero sorteado de tochas
                //E não pode colocar uma tocha se já colocarmos uma tocha antes naquele local
                if(where_tocha<=15 && tochas<num_tocha && mapa1[i][j]!=2)
                {
                    //Sendo tudo verdadeiro, colocaremos a tocha naquela posição e adicionaremos +1 na variavel tochas
                    //ou seja, o loop não precisará ser realizado mais alguma vez
                    mapa1[i][j]=3;
                    tochas++;
                }
            }
    /*Laco sera repetido ate que o numero de tochas sejam iguais ao numero sorteado */
    }while(tochas<num_tocha);

    //OURO
    do
    {
		for(int i=2;i<10;i++)
        	for(int j=1;j<11;j++)
        		{
				do
                {
                    where_ouro=rand()%101;
                }while(where_ouro>101);
                if(where_ouro<=2 && ouro<1 && mapa1[i][j]==1)
                    {
                        mapa1[i][j]=4;
                        ouro++;
                    }
                }
	}while(ouro<1);
}
void movimentacao1(int mapa1[][12])
{
    char tecla1=0; // Essa variável irá receber os valores w,a,s,d para controlar os player
	int x = 1, y = 1; // Essa variáveis são as coordenadas do player e seram de estrema importância para a movimentação.
    int passos=0;
    int passos_andados=0;
    sorteio_passos(&passos);
    printf("Player 1 pode dar %d passos\n",passos);
    while(passos>passos_andados)
        {
            tecla1=getch();
             // Se lembra da variável que ia pegar w,a,s,d? pronto aqui é onde ela recebe o valor
            /******Com o valor adquirido você terá 4 ifs diferentes 1 pra cada letra.******/
            /* Esse é o if para cima, se queremos que o Player suba devemos mexer no x diminuindo,
            * pode parecer confuso, ou n, vc ter que diminuir para subir, mas vai fazer sentido
            */
                if(tecla1 == 'w' || tecla1 == 'W')
            {
                x--;
                mapa1[x][y] = 5;
                mapa1[x+1][y] = 7;
            }// fim do if cima

		/* Já esse é o if para descer, seguindo a mesma lógica do anterior porém agora
		 * aumentando o x
		 */
            if(tecla1 == 's' || tecla1 == 'S')
            {
                x++;
                mapa1[x][y] = 5;
                mapa1[x-1][y] = 7;
            }// fim do if baixo

		/* Esse é o if para ir para a esquerda como está
		 * se deslocando na horizontal mexe-se no y, diminuindo
		 */
            if(tecla1 == 'a' || tecla1 == 'A')
            {
                y--;
                mapa1[x][y] = 5;
                mapa1[x][y+1] = 7;
            }// fim do if esquerda

            /* Esse é o último if, aponta para a direita, apenas mexemos no y aumentando-o */
            if(tecla1 == 'd' || tecla1 == 'D')
            {
                y++;
                mapa1[x][y] = 5;
                mapa1[x][y-1] = 7;
            }
        passos--;
        mapa1[1][1] = 9;
        show_map(mapa1);
        printf("Player 1 pode dar %d passos\n",passos);
        }
}
void movimentacao2(int mapa1[][12])
{
    int tecla1=0; // Essa variável irá receber os valores w,a,s,d para controlar os player
	int x = 1, y = 10; // Essa variáveis são as coordenadas do player e seram de estrema importância para a movimentação.
    int passos=0;
    sorteio_passos(&passos);
    printf("Player 2 pode dar %d passos\n",passos);
    int passos_andados=0;
    while(passos>passos_andados)
        {
            scanf("%d",&tecla1); // Se lembra da variável que ia pegar w,a,s,d? pronto aqui é onde ela recebe o valor
            /******Com o valor adquirido você terá 4 ifs diferentes 1 pra cada letra.******/
            /* Esse é o if para cima, se queremos que o Player suba devemos mexer no x diminuindo,
            * pode parecer confuso, ou n, vc ter que diminuir para subir, mas vai fazer sentido
            */
            //verificacao das teclas
            if(tecla1 == 8)
            {
                x--;
                mapa1[x][y] = 6;
                mapa1[x+1][y] = 7;
                mapa1[1][10] = 9;
            }// fim do if cima

		/* Já esse é o if para descer, seguindo a mesma lógica do anterior porém agora
		 * aumentando o x
		 */
            if(tecla1 == 5)
            {
                x++;
                mapa1[x][y] = 6;
                mapa1[x-1][y] = 7;
            }// fim do if baixo

		/* Esse é o if para ir para a esquerda como está
		 * se deslocando na horizontal mexe-se no y, diminuindo
		 */
            if(tecla1 == 4)
            {
                y--;
                mapa1[x][y] = 6;
                mapa1[x][y+1] = 7;
            }// fim do if esquerda

            /* Esse é o último if, aponta para a direita, apenas mexemos no y aumentando-o */
            if(tecla1 == 6)
            {
                y++;
                mapa1[x][y] = 6;
                mapa1[x][y-1] = 7;
            }
        passos--;
        mapa1[1][10]= 9;
        show_map(mapa1);
        printf("Player 2 pode dar %d passos\n",passos);
        }
}
void map()
{
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
	show_map(mapa1);
	while(1)
    {
	movimentacao1(mapa1);
	movimentacao2(mapa1);
    }
}
int main()
{
    srand(time(NULL));
    int passos=0,player=0;
    map();
}
