#include <stdio.h>
#include <stdlib.h>
void menu(char *user)
{   printf("\t\tBem-vindo ao caca ao tesouro!\n\na) --- Comecar a jogar\nb) --- Creditos\nc) --- Sair\nd) --- Ir a marte\n");
    *user=getch();
    switch(*user)
    {   case 'a':
        case 'A':
            {   system("cls");
                printf("Processando sua resposta...");
                Sleep(0.5);
                printf("\n\t\t\tEntao vamos comecar");
                Sleep(1);
                system("cls");
                printf("Comecou\n");
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
                Sleep(5);
                break;
            }
        case 'c':
        case 'C':
            {   printf("E triste ve-lo partir:/ \nAte mais...\n");
                Sleep(1.5);
                system("cls");
                printf("Encerrando...");
                break;
            }
        case 'd':
        case 'D':
            {   printf("Processando sua resposta...");
                Sleep(0.5);
                printf("\nLamento, ainda nao e possivel\n");
                printf("Quem sabe em 2030?\n");
                break;
            }
        default:
            {   system("cls");
                printf("Processando sua resposta...");
                Sleep(0.5);
                system("cls");
                printf("Estamos chateados com voce\n");
                printf("Digita um valor valido ai, mano\n");
                break;
            }
    }
}

