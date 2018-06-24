#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void show_map(int mapa2[12][12])
{	system("cls");
	system("color b");
    /** 0 --- PAREDE HORIZONTAL
        1 --- NADA
        2 --- ARMADILHAS
        3 --- TOCHAS
        4 --- TESOURO
        5 --- PLAYER 1
        6 --- PLAYER 2
        7 --- ESPACO VAZIO
        8 --- PAREDE VERTICAL
        9 --- POSICAO INICIAL
       10 --- PLAYER 1 E 2 JUNTOS
       21 --- ARMADILHA REVELADA
       22 --- ARMADILHA ENCONTRADA
       31 --- TOCHA REVELADA
       33 --- TOCHA ENCONTRADA
       41 --- TESOURO REVELADO
       44 --- TESOURO ENCONTRADO
    **/
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<12;j++)
        {
            if(mapa2[i][j]==0)
                printf(" == ");
            if(mapa2[i][j]==1||mapa2[i][j]==2||mapa2[i][j]==3||mapa2[i][j]==4)
                printf(" -- ");
            if(mapa2[i][j]==22)
                {
                    printf("TRAP");
                  //  messages(2,1);
                }
            if(mapa2[i][j]==33)
                {
                    printf("FIRE");
                    {
                    if(mapa2[i+1][j]==1)
                        mapa2[i+1][j]=7;
                    else if(mapa2[i+1][j]==3)
                        mapa2[i+1][j]=33;
                    else if(mapa2[i+1][j]==2)
                        mapa2[i+1][j]=22;
                    else if(mapa2[i+1][j]==4)
                        mapa2[i+1][j]=44;


                    if(mapa2[i-1][j]==1)
                        mapa2[i-1][j]=7;
                    else if(mapa2[i-1][j]==2)
                        mapa2[i-1][j]=22;
                    else if(mapa2[i-1][j]==3)
                        mapa2[i-1][j]=33;
                    else if(mapa2[i-1][j]==4)
                        mapa2[i-1][j]=44;


                   if(mapa2[i][j+1]==1)
                        mapa2[i][j+1]=7;
                   else if(mapa2[i][j+1]==2)
                        mapa2[i][j+1]=22;
                   else if(mapa2[i][j+1]==3)
                        mapa2[i][j+1]=33;
                   else if(mapa2[i][j+1]==4)
                        mapa2[i][j+1]=44;

                    if(mapa2[i][j-1]==1)
                        mapa2[i][j-1]=7;
                    else if(mapa2[i][j-1]==2)
                        mapa2[i][j-1]=22;
                    else if(mapa2[i][j-1]==3)
                        mapa2[i][j-1]=33;
                    else if(mapa2[i][j-1]==4)
                        mapa2[i][j-1]=44;
                    }
                }
            if(mapa2[i][j]==44)
                {
                    printf("GOLD");
                    //messages(4,1);
                }
            if(mapa2[i][j]==5)
                printf(" P1 ");
            if(mapa2[i][j]==6)
                printf(" P2 ");
            if(mapa2[i][j]==7)
                printf("    ");
            if(mapa2[i][j]==8)
                printf(" || ");
            if(mapa2[i][j]==9)
                printf(" <> ");
            if(mapa2[i][j]==10)
                printf("P1P2");
        }
        putchar('\n');
    }
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
            if(where_tocha <= 30 && where_tocha > 0 && tochas < num_tocha && mapa1[i][j] == 1)
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

void movimentacao1(int init_x,int init_y, int *x,int *y,int mapa1[][12])/** Funcao p/ movimentar o player 1 */
{    //*x, *y  Essa variaveis sao as coordenadas do player e serao de extrema importancia para a movimentacao.
/** Estou utilizando ponteiros em x e y, para nao mostrar na tela mais de 1x P1 ou P2(se fosse o caso)
 *  Isso estava acontecendo quando, ao terminar os passos do jogador I, depois os passos do jogador II.
 *  Ao voltar para esse procedimento, estava atualizando a posicao do jogador, e mostrando 2 P1 no mesmo mapa,o  que nao eh o objetivo  */
    char tecla1=0; // Essa variavel ira receber os valores w,a,s,d para controlar o player 1
    int passos=10,passos_andados=0;/**Variavel passos_andados ira armazenar cada passo realizado pelo jogador ate chegar no valor sorteado
    Variavel passos ira armazenar o valor sorteado, e servira para o controle do laco de repeticao */
    mapa1[init_x][init_y]=5;
    show_map(mapa1);
    printf("Player 1: Eu posso dar %d passos\n",passos);
    while(passos>passos_andados)
        {
            tecla1=getch();
             // Se lembra da vari�vel que ia pegar w,a,s,d? pronto aqui � onde ela recebe o valor
            /******Com o valor adquirido voc� ter� 4 ifs diferentes 1 pra cada letra.******/
            /* Esse � o if para cima, se queremos que o Player suba devemos mexer no x diminuindo,
            * pode parecer confuso, ou n, vc ter que diminuir para subir, mas vai fazer sentido
            */
            switch(tecla1)
            {
            case 'w':
            case 'W':
                {   (*x)--;
                    switch(mapa1[(*x)][(*y)])
                        case 0:
                            {   (*x)++;
                                passos++;//Tentativa de fazer com que o jogador nao perca nenhum passo ao ir para a parede, nao testei ainda
                                break;
                            }
                        case 1:
                            {   mapa1[*x][*y]=5;
                                mapa1[((*x)+1)][(*y)]=7;
                                break;
                            }
                        case 2:
                            {   mapa1[*x][*y]=22;
                                mapa1[((*x)+1)][(*y)]=7;
                                break;
                            }
                        case 3:
                            {   mapa1[*x][*y]=33;
                                mapa1[((*x)+1)][(*y)]=7;
                                break;
                            }
                        case 4:
                            {   mapa1[*x][*y]=44;
                                mapa1[((*x)+1)][(*y)]=7;
                                break;
                            }
                        case 6:
                            {   mapa1[*x][*y]=10;
                                mapa1[((*x)+1)][(*y)]=7;
                                break;
                            }
                        case 7:
                            {   mapa1[*x][*y]=5;
                                mapa1[((*x)+1)][(*y)]=7;
                                break;
                            }
                        case 9:
                            {   mapa1[*x][*y]=5;
                                mapa1[((*x)+1)][(*y)]=7;
                                break;
                            }
                        case 10:
                            {   mapa1[(*x)][(*y)]=5;
                                mapa1[((*x)+1)][(*y)]=6;
                                break;
                            }
                    break;
                }/*
            case 'a':
            case 'A':
                {
                    break;
                }
            case 's':
            case 'S':
                {
                    break;
                }
            case 'd':
            case 'D':
                {
                    break;
                }
            }
            */


        if(tecla1 == 'w' || tecla1 == 'W' || tecla1 == 's' || tecla1 == 'S' || tecla1 == 'a' || tecla1 == 'A' || tecla1 == 'd' || tecla1 == 'D')
        {   /*if(tecla1 == 'w' || tecla1 == 'W')
            {   (*x)--;
                if(mapa1[(*x)][(*y)]==0)
                 {  (*x)++;
                    passos++;//Tentativa de fazer com que o jogador nao perca nenhum passo ao ir para a parede, nao testei ainda
                 }
                if(mapa1[(*x)][(*y)]==1)
                {   mapa1[*x][*y]=5;
                    mapa1[((*x)+1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==2)
                {   mapa1[*x][*y]=22;
                    mapa1[((*x)+1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==3)
                {   mapa1[*x][*y]=33;
                    mapa1[((*x)+1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==4)
                {   mapa1[*x][*y]=44;
                    mapa1[((*x)+1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==6)
                {   mapa1[*x][*y]=10;
                    mapa1[((*x)+1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==7)
                {   mapa1[*x][*y]=5;
                    mapa1[((*x)+1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==9)
                {   mapa1[*x][*y]=5;
                    mapa1[((*x)+1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==10)
                {
                    mapa1[(*x)][(*y)]=5;
                    mapa1[((*x)+1)][(*y)]=6;
                }
            }// fim do if cima
                */
		/* Ja esse eh o if para descer, seguindo a mesma l�gica do anterior por�m agora
		 * aumentando o x
		 */
            if(tecla1 == 's' || tecla1 == 'S')
            {   (*x)++;
                if(mapa1[(*x)][(*y)]==8)
                {   (*x)--;
                    passos++;
                }
                if(mapa1[(*x)][(*y)]==1)
                {   mapa1[*x][*y]=5;
                    mapa1[((*x)-1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==2)
                {   mapa1[*x][*y]=22;
                    mapa1[((*x)-1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==3)
                {   mapa1[*x][*y]=33;
                    mapa1[((*x)-1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==4)
                {   mapa1[*x][*y]=44;
                    mapa1[((*x)-1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==6)
                {   mapa1[*x][*y]=10;
                    mapa1[((*x)-1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==7)
                {   mapa1[*x][*y]=5;
                    mapa1[((*x)-1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==9)
                {   mapa1[*x][*y]=5;
                    mapa1[((*x)-1)][(*y)]=7;
                }
                if(mapa1[(*x)][(*y)]==10)
                {
                    mapa1[(*x)][(*y)]=5;
                    mapa1[((*x)-1)][(*y)]=6;
                }
            }// fim do if baixo

		/* Esse eh o if para ir para a esquerda como est�
		 * se deslocando na horizontal mexe-se no y, diminuindo
		 */
            if(tecla1 == 'a' || tecla1 == 'A')
            {
                (*y)--;
                if(mapa1[(*x)][(*y)]==0)
                 {  (*y)++;
                    passos++;
                 }
                if(mapa1[(*x)][(*y)]==1)
                {   mapa1[*x][*y]=5;
                    mapa1[((*x))][(*y)+1]=7;
                }
                if(mapa1[(*x)][(*y)]==2)
                {   mapa1[*x][*y]=22;
                    mapa1[((*x))][(*y)+1]=7;
                }
                if(mapa1[(*x)][(*y)]==3)
                {   mapa1[*x][*y]=33;
                    mapa1[((*x))][(*y)+1]=7;
                }
                if(mapa1[(*x)][(*y)]==4)
                {   mapa1[*x][*y]=44;
                    mapa1[((*x))][(*y)+1]=7;
                }
                if(mapa1[(*x)][(*y)]==6)
                {   mapa1[*x][*y]=10;
                    mapa1[((*x))][(*y)+1]=7;
                }
                if(mapa1[*x][*y]==7)
                {   mapa1[*x][*y]=5;
                    mapa1[*x][(*y)+1]=7;
                }
                if(mapa1[(*x)][(*y)]==9)
                {   mapa1[*x][*y]=5;
                    mapa1[((*x))][(*y)+1]=7;
                }
                if(mapa1[(*x)][(*y)]==10)
                {
                    mapa1[(*x)][(*y)]=5;
                    mapa1[((*x))][(*y)+1]=6;
                }
            }// fim do if esquerda

            /* Esse � o �ltimo if, aponta para a direita, apenas mexemos no y aumentando-o */
            if(tecla1 == 'd' || tecla1 == 'D')
            {
                (*y)++;
                if(mapa1[(*x)][(*y)]==0)
                 {  (*y)--;
                    passos++;
                 }
                if(mapa1[(*x)][(*y)]==1)
                {   mapa1[*x][*y]=5;
                    mapa1[((*x))][(*y)-1]=7;
                }
                if(mapa1[(*x)][(*y)]==2)
                {   mapa1[*x][*y]=22;
                    mapa1[((*x))][(*y)-1]=7;
                }
                if(mapa1[(*x)][(*y)]==3)
                {   mapa1[*x][*y]=33;
                    mapa1[((*x))][(*y)-1]=7;
                }
                if(mapa1[(*x)][(*y)]==4)
                {   mapa1[*x][*y]=44;
                    mapa1[((*x))][(*y)-1]=7;
                }
                if(mapa1[(*x)][(*y)]==6)
                {   mapa1[*x][*y]=10;
                    mapa1[((*x))][(*y)-1]=7;
                }
                if(mapa1[(*x)][(*y)]==7)
                {
                    mapa1[(*x)][(*y)]=5;
                    mapa1[(*x)][(*y)-1]=7;
                }
                if(mapa1[(*x)][(*y)]==9)
                {   mapa1[*x][*y]=5;
                    mapa1[((*x))][(*y)-1]=7;
                }
                if(mapa1[(*x)][(*y)]==10)
                {
                    mapa1[(*x)][(*y)]=5;
                    mapa1[((*x))][(*y)-1]=6;
                }
            }
        passos--;
        mapa1[init_x][init_y] = 9;//Mostrar sempre a posicao inicial do jogador
        show_map(mapa1);//Apos o jogador ter digitado algo, temos que imprimir a matriz novamente
        printf("Player 1 tem mais %d passos...\n",passos);//Mostrar ao jogador quantos passos restantes ele tem
        }
        system("cls");//Sempre limpar o que estava antes na tela
        }
}
}

int main()
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
	init_x=x;   init_y=y;   init_w = w; init_z=z;
/*  Enviar o init_x e etc como argumento para o procedimento show_map(), para mostrar onde os jogadores escolheram iniciar */
	while(1)
	{
	    show_map(mapa1);
        movimentacao1(init_x,init_y,&x,&y,mapa1);
    }
}
