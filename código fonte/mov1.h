#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void messages(int situacao,int player);/**Funcao p/ Mostrar todas as mensagens aos jogadores.
Necessita de 2 parametros, a mensagem que sera mostrada e a qual jogador ela se refere */
void show_map(int mapa2[12][12]);
void sorteio_passos(int *passos);/**Funcao p/ sortear quantos passos serao realizados pelos jogadores*/
void movimentacao1(int init_x,int init_y, int *x,int *y,int mapa1[][12])/** Funcao p/ movimentar o player 1 */
{    //*x, *y  Essa variaveis sao as coordenadas do player e serao de extrema importancia para a movimentacao.
/** Estou utilizando ponteiros em x e y, para nao mostrar na tela mais de 1x P1 ou P2(se fosse o caso)
 *  Isso estava acontecendo quando, ao terminar os passos do jogador I, depois os passos do jogador II.
 *  Ao voltar para esse procedimento, estava atualizando a posicao do jogador, e mostrando 2 P1 no mesmo mapa,o  que nao eh o objetivo  */
    char tecla1=0; // Essa variavel ira receber os valores w,a,s,d para controlar o player 1
    int passos=0,passos_andados=0;/*Variavel passos ira armazenar o valor sorteado, e servira para o controle do laco de repeticao */
    sorteio_passos(&passos);//Sorteio de quantos passos poderao ser dados pelo jogador - sempre de 3 a 10
    mapa1[init_x][init_y]=5;
    show_map(mapa1);
    messages(7,1);
    printf("Player 1: Eu posso dar %d passos\n",passos);
    while(passos>0)//Quando chegar em 0, termina o laco e o termina o turno
        {   tecla1=getch();
             // Se lembra da vari?vel que ia pegar w,a,s,d? pronto aqui ? onde ela recebe o valor
            /******Com o valor adquirido voc? ter? 4 ifs diferentes 1 pra cada letra.******/
            /* Esse ? o if para cima, se queremos que o Player suba devemos mexer no x diminuindo,
            * pode parecer confuso, ou n, vc ter que diminuir para subir, mas vai fazer sentido
            */
            if(tecla1 == 'w' || tecla1 == 'W' || tecla1 == 's' || tecla1 == 'S' || tecla1 == 'a' || tecla1 == 'A' || tecla1 == 'd' || tecla1 == 'D')
            {   if(tecla1 == 'w' || tecla1 == 'W')
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

		/* Ja esse eh o if para descer, seguindo a mesma l?gica do anterior por?m agora
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

		/* Esse eh o if para ir para a esquerda como est?
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

            /* Esse ? o ?ltimo if, aponta para a direita, apenas mexemos no y aumentando-o */
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
                    messages(2,1);
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
        messages(7,1);
        printf("Player 1 tem mais %d passos...\n",passos);//Mostrar ao jogador quantos passos restantes ele tem
        }

        }
        system("cls");//Sempre limpar o que estava antes na tela
}
