# Joguinho
Projeto para composição da nota da segunda unidade
                                          
                                         ESTE README NÃO ESTÁ COMPLETO


02/05
LINGUAGEM DE PROGRAMAÇÃO

    • PROJETO(Gameplay):
Labirinto 10x10;
2 Jogadores;
Trap (Caitlyn) = -1HP (32 traps, 25%), se esquecer das traps -2,5 na média;
FIRE (Brand) = Revela os conteúdos em cada 1 casa na vertical (cima e baixo) e horizontal (esquerda e direita), (5 tochas, 15%), se esquecer das tochas -2,5 pontos da media; 
Gold (Bardo) = Objeto de finalização (1 Gold, 1%), deve estar da terceira linha na horizontal para baixo;
Primeira e decima casa na horizontal primeira linha são as bases;
Objetivo: Achar o tesouro (Pegar Gold) /Ficar vivo (Não feedar);
Dado aleatório 3-10;
W A S D e 8 4 5 6 para movimentação;
HP :5;
Base tem símbolo (B);

    • Projeto(Matriz/regras):
Sempre tem que informar o que acontece para os usuários/jogadores para o que aconteceu (Ex: Jogador 1 achou uma tocha);
Códigos: rand()%x{0 a (x-1)}*
                #include <stdlib.h>
                #include <time.h>
                 srand(time(null));
                 multi thread
