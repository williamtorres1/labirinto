#include <stdio.h>
#include <stdlib.h>
void messages(int situacao,int player)/**Funcao p/ Mostrar todas as mensagens aos jogadores.
Necessita de 2 parametros, a mensagem que sera mostrada e a qual jogador ela se refere */
{   switch(situacao)
	{	case 1:
		{   printf("\t\t\t\t\tBem-vindo a caca ao Tesouro!\n\n\n");
			break;
		}
		case 2:
		{   printf("\nPlayer %d pisou numa armadilha, perdeu 1 HP\n",player);
		    Sleep(1500);
			break;
		}
		case 3:
		{	printf("\nPlayer %d encontrou uma tocha!",player);
			Sleep(1500);
			break;
		}
		case 4:
		{	system("cls");
		    Sleep(500);
		    printf("\n\n\n\t\t\t*****Player %d encontrou o tesouro!*****",player);
		    Sleep(1500);
            system("cls");
			break;
		}
		case 5:
        {
            system("cls");
            Sleep(500);
            printf("\n\n\n\t\t\t*****Player %d GANHOU!! PARABENSS*****",player);
            Sleep(1500);
            system("cls");
            break;
        }
	}
}
