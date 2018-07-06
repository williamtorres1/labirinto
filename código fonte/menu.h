#include <stdio.h>
#include <stdlib.h>
void menu(char *user)
{   printf("\t\tBem-vindo ao caca ao tesouro!\n\na) --- Comecar a jogar\nb) --- Creditos\nc) --- Ir a marte\nd) --- Ajuda\ne) --- Sair\n");
    *user=getch();
    switch(*user)
    {   case 'a':
        case 'A':
            {   system("cls");
                printf("Processando sua resposta...");
                Sleep(500);
                printf("\n\n\t\t\tEntao vamos comecar");
                Sleep(500);
                system("cls");
                printf("\n\n\t\t\t****Comecou****\n");
                break;
            }
        case 'b':
        case 'B':
            {   system("cls");
                printf("Processando sua resposta...");
                system("cls");
                printf("\n\n\nEste software foi desenvolvido por:\nWilliam Torres\n");
                printf("GitHub:    github.com/williamtorres1\n");
                printf("Facebook:  facebook.com/williamtorres.4\n");
                printf("Instagram: instagram.com/williamtoorres\n");	
                system("pause");
                break;
            }
        case 'c':
        case 'C':
            {   system("cls");
                printf("Processando sua resposta...");
                Sleep(500);
                printf("\nLamento, ainda nao e possivel\n");
                printf("Quem sabe em 2030?\n");
                system("pause");
                break;
            }
        case 'd':
        case 'D':
            {   system("cls");
		printf("Esta aba e uma guia de instrucoes aos jogadores.\n");
		printf("\n1)Como Jogar\nVoce e outro jogador devem escolher o local de saida, apos o inicio do jogo, voce deve se movimentar para encontrar o tesouro primeiro! Mas tome cuidado pelo caminho que anda ;D\n");
		printf("\n2)Teclas usadas pelo jogador 1\nMovimentacao --- W(cima), A(esquerda), S(baixo), D(direita).\nTeclas usadas pelo jogador 2\nMovimentacao --- 8(cima), 4(esquerda), 5(baixo), 6(direita).\n\n");
                system("pause");
                break;
            }
        case 'e':
        case 'E':
            {   system("cls");
                printf("E triste ve-lo partir:/ \nAte mais...\n");
                Sleep(1500);
                system("cls");
                printf("Encerrando...\n\n");
                break;
            }
        default:
            {   system("cls");
                printf("Processando sua resposta...");
                Sleep(500);
                system("cls");
                printf("Estamos chateados com voce\n");
                printf("Digita um valor valido ai, mano\n");
                break;
            }
    }
}
