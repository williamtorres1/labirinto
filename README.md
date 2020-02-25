# Labirinto
Projeto para a nota da segunda unidade
## Iniciando
Utilizando o [GCC Compiller](https://gcc.gnu.org/), vá para a pasta que está o arquivo .c e digite o seguinte comando no terminal:
```
	g++ -o <nome do arquivo> <nome do arquivo>.c
```
Você pode renomear o arquivo com o nome "main", para ficar mais fácil utilizar o terminal.
Pronto! Agora você pode utilizar este jogo.

## Sobre a Jogabilidade
					
### Jogadores

    1. Cada jogador tem 5 Pontos de Vida(HP).
    2. O jogador 1 utiliza W, A, S, D para mover-se.	
       ex: W – Move o jogador para cima; A - Move o jogador para a esquerda; S – Move o jogador para baixo; 
       D – Move o jogador para a direita.
    3. O jogador 2 utiliza 8, 4, 5, 6 para mover-se.	
       ex: 8 – Move o jogador para cima; 4 - Move o jogador para a esquerda; 5 – Move o jogador para baixo; 
       6 – Move o jogador para a direita.

### Elementos

    1. Armadilha: Retira um Ponto de Vida àquele que pisar nela.
       O jogador perderá 1 Ponto de Vida ao entrar numa armadilha. 
       Após o jogador entrar naquela armadilha, ela desaparece.
       	Ex: Armadilha –> *P1*
    2. Tocha: Ilumina um elemento às suas verticais e horizontais. 
    Um elemento à cima, à direita, à esquerda e abaixo serão revelados.
               Ex: Tocha –> &P1&
               
### Objetivos do jogo

    1. Ficar vivo até encontrar o tesouro(ou gold).
    2. Encontrar o tesouro primeiro que o adversário.
       Ex: O jogador que encontrar o tesouro primeiro ganha.
    3. Não morrer antes do adversário.
       Ex: O jogador que morrer primeiro, automaticamente o outro ganha.
       
### Mensagens

    1. Abaixo do Mapa, mostrar as informações dos jogadores.
       Ex: PLAYER I		PLAYER II
           HP: 5/5		HP: 5/5
    2. Ao terminar o turno de um jogador, tem que avisar quem irá jogar posteriormente.
       Ex: Player I pode andar 3 casas –> Player I pode dar mais 2 passos –> Player I Pode dar mais 1 passo.
       Ex: Player II pode andar 7 casas –> Player II pode dar mais 6 passos e etc... 
    3. Ao pisar numa armadilha.
       Ex: Player I pisou numa armadilha, perdeu 1 Ponto de Vida(HP).
    4. Ao encontrar uma tocha.
       Ex: Player I encontrou uma tocha.
       
### Sobre a construção do jogo – Criação do código

    1. Como decidir onde ficará cada elemento – TEM DE SER ALEATÓRIO:
        #include <stdlib.h> /* Para a função rand( ) e srand( ) */
       rand( ) –> Retorna um valor aleatório.
       rand( ) % x –> Retorna um valor que vai de 0 à X-1
       Ex: Se X for 10, a função vai retornar números de 0 à 9;
    2. Para tudo ser realmente aleatório, é necessário fazer o seguinte:
       #include <time.h>/* Para a função time */
       srand( ) –> Alterar o valor semente da função rand ( ).
    3. Receberá como argumento o retorno da função time(NULL)
       Ex: srand(time(NULL)) – Detalhe: Só precisa fazer isso UMA VEZ no programa, logo no início do main.

### Definições dos elementos da matriz

    1. Precisa de um símbolo indicando o ponto de partida.
        1. Ex: <> –> Indicará de onde aquele jogador deu partida.
        2. Ex:[1][1]  - Ponto inicial do jogador 1.
              [1][10] - Ponto inicial do jogador 2.
    2. Matriz 10x10.
    3. Armadilhas(TRAP): Podem existir até 32 armadilhas(de 0 à 32).
    Em cada elemento da matriz[i][j], testar a chance de 25% de conter uma armadilha(trap) naquele elemento.
       Ex: Se for sorteado qualquer número entre de 1 à 25, colocar uma armadilha.
    4. Tochas(FIRE): 
    Podem existir até 5 tochas(de 0 à 5). 
    Em cada elemento, testar a possibilidade de 15% de conter uma tocha(fire).
    5. Ex: Se for sorteado qualquer número entre 1 à 15, colocar uma tocha.
       se cair qualquer numero de 1 à 25, colocar um fire.
    6. Tesouro(OURO ou GOLD): 
    Pode existir 1, e somente 1 ouro, chance de 1%. Pode estar em qualquer lugar a partir da segunda linha.
       Ex: Não pode estar na primeira linha, ou seja, da segunda para baixo.
            Exceções descritas nos Bônus
    7. Ordem de preencher os elementos:
        1. De cima para baixo ou de baixo para cima, fica à critério do programador.

### Avaliação

       Você começa com 10 e perde pontos se:
    1. Não executou as armadilhas corretamente: -2,0 pontos.
       Ex: Esqueceu de colocar as traps, ou tirar ponto de vida do jogador.
    2. Não executou as tochas corretamente: -2,0 pontos.
       Ex: Mesmos princípios das armadilhas.
    3. Não executou o tesouro corretamente, mesmos princípios das armadilhas: -1,0 ponto.
       Ex: Na partida não teve nenhum tesouro, ou a partida não encerrou quando o tesouro foi encontrado.
    4. Não colocou as mensagens corretamente – as ações do jogo: -2,0 pontos.
        1. Ex: Quantas casas ainda tem para movimentar.
        2. Ex: Ao cair numa armadilha – portanto, perdeu um ponto de vida(HP).
        3. Ex: Ao encontrar uma tocha.
        4. Ex: Ao encontrar o tesouro.
        5. Ex: Dizer quem ganhou.
    5. Não fez corretamente o desenho do labirinto: -1,0 ponto.
       Detalhe: Não precisa ser o labirinto perfeito, o mais bonito do mundo.
        1. Ex: Os jogadores tem de ser capazes de identificar visualmente tudo que está acontecendo.
        2. Ex: Esquecer de mostrar os jogadores = ERRO. 
    6. Não fez as validações corretas de fim de jogo: -2,0 pontos.
        1. Ex: Se algum jogador perdeu todos os pontos de vida, a partida tem que acabar.
        2. Ex: Se algum jogador encontrou o tesouro, a partida tem que acabar.

## BÔNUS - para recuperação da primeira unidade
    1. Se o programa permitir que os jogadores escolham a posição inicial, sendo um destes 4 pontos.
        1. Ex:
		[01][1]			[01][10]
		[10][1]			[10][10]
        2. Detalhe: Nesta versão, o tesouro tem de ficar a partir da linha 2 e até a linha 9.
    2. Se utilizar Mult-Thread: Permitir aos dois jogadores jogarem ao mesmo tempo.
        1. DETALHE: UTILIZANDO MULT-THREAD.
        2. DETALHE: Os jogadores NÃO PODEM começar do mesmo ponto.
    3. Se permitir 4 jogadores jogarem ao mesmo tempo.
  
# ATENÇÃO
NÃO DEVE-SE UTILIZAR VARIÁVEIS GLOBAIS
