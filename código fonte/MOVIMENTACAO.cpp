#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{

	char muv; // Essa variável irá receber os valores w,a,s,d para controlar os player
	int x = 1, y = 1; // Essa variáveis são as coordenadas do player e seram de estrema importância para a movimentação.
    int trap=0,num_trap=0,where_trap=0;//trap = armadilhas, num_trap = numero de armadilhas
                                       //where_trap = chance de conter uma armadilha naquele elemento da matriz [i][j]
    int tochas=0,num_tocha=0,where_tocha=0;//mesma logica das armadilhas
    int ouro=0,where_ouro=0;//ouro = tesouro
                            //mesma lógica das armadilhas, mas podendo conter somente um ouro no mapa, e PRECISA TER UM tesouro
	while(1){
		muv=getch(); // Se lembra da variável que ia pegar w,a,s,d? pronto aqui é onde ela recebe o valor

		/******Com o valor adquirido você terá 4 ifs diferentes 1 pra cada letra.******/

		/* Esse é o if para cima, se queremos que o Player suba devemos mexer no x diminuindo,
		 * pode parecer confuso, ou n, vc ter que diminuir para subir, mas vai fazer sentido
		 */
		if(muv == 'w'){
			x--;
			mapa1[x][y] = 5;
			mapa1[x+1][y] = 7;
		}// fim do if cima

		/* Já esse é o if para descer, seguindo a mesma lógica do anterior porém agora
		 * aumentando o x
		 */
		if(muv == 's'){
			x++;
			mapa1[x][y] = 5;
			mapa1[x-1][y] = 7;
		}// fim do if baixo

		/* Esse é o if para ir para a esquerda como está
		 * se deslocando na horizontal mexe-se no y, diminuindo
		 */
		if(muv == 'a'){
			y--;
			mapa1[x][y] = 5;
			mapa1[x][y+1] = 7;
		}// fim do if esquerda

		/* Esse é o último if, aponta para a direita, apenas mexemos no y aumentando-o */
		if(muv == 'd'){
			y++;
			mapa1[x][y] = 5;
			mapa1[x][y-1] = 7;
		}// fim do if direita

		system("cls");

		/* E esse for faz o mesmo que  o de lá de cima, imprime a matriz, porém como vc altrou x ou y
		 * mudou as elementos da matriz a precisa imprimir de novo
		 */
	//	 system("cls");

	}
	return 0;
} // fim do método main
