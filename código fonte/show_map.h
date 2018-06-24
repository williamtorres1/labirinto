#include <stdio.h>
#include <stdlib.h>
#include "messages.h"
void show_map(int mapa2[12][12])
{	system("cls");
	system("color b");
    messages(1,0);
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
            if(mapa2[i][j]==21)
                printf("TRAP");
            if(mapa2[i][j]==22)
                printf("TRAP");
            if(mapa2[i][j]==31)
                {printf("FOGO");
                /*mapa2[i][j]=31;*/}
            if(mapa2[i][j]==33)
                {
                    printf("FIRE");
                    {   if(mapa2[i][j]==31)
                        printf("FOGO");
                    if(mapa2[i+1][j]==1)
                        mapa2[i+1][j]=7;
                    else if(mapa2[i+1][j]==3)
                        mapa2[i+1][j]=31;
                    else if(mapa2[i+1][j]==2)
                        mapa2[i+1][j]=21;
                    else if(mapa2[i+1][j]==4)
                        mapa2[i+1][j]=41;


                    if(mapa2[i-1][j]==1)
                        mapa2[i-1][j]=7;
                    else if(mapa2[i-1][j]==3)
                        mapa2[i-1][j]=31;
                    else if(mapa2[i-1][j]==2)
                        mapa2[i-1][j]=21;
                    else if(mapa2[i-1][j]==4)
                        mapa2[i-1][j]=41;


                   if(mapa2[i][j+1]==1)
                        mapa2[i][j+1]=7;
                   else if(mapa2[i][j+1]==2)
                        mapa2[i][j+1]=21;
                   else if(mapa2[i][j+1]==3)
                        mapa2[i][j+1]=31;
                   else if(mapa2[i][j+1]==4)
                        mapa2[i][j+1]=41;

                    if(mapa2[i][j-1]==1)
                        mapa2[i][j-1]=7;
                    else if(mapa2[i][j-1]==2)
                        mapa2[i][j-1]=21;
                    else if(mapa2[i][j-1]==3)
                        mapa2[i][j-1]=31;
                    else if(mapa2[i][j-1]==4)
                        mapa2[i][j-1]=41;
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

