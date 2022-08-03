# Trabalho Prático 1 -Jogo do Pulo
## Introdução

Adriana e suas amigas são apaixonadas por jogos de tabuleiro. Em um dia qualquer, Adriana descobre um jogo muito interessante: O Jogo do Pulo. Ansiosa por compartilhar o jogo com suas amigas, imediatamente marca um encontro para jogarem. Já inicia o encontro explicando o jogo. O objetivo do Jogo do Pulo é bem simples: dado um tabuleiro, jogadores e suas posições iniciais, atingir a última casa do tabuleiro (em um tabuleiro de tamanho NxM, essa seria a casa N-1xM-1).

O tabuleiro pode conter qualquer número de dimensões, dependendo do modo do jogo e da realidade em que está inserido. Neste trabalho iremos abordar o modo bi-dimensional do jogo. Cada célula do tabuleiro contém um número que informa quantas casas o jogador deve pular partindo dela. Note que é o número exato de casas, e não o máximo partindo dela. O tabuleiro possui números inteiros positivos, e pode conter casas com o número zero (no caso do número da casa ser um zero, o jogador nunca consegue sair dela).

Os personagens movimentam-se apenas em sentidos paralelos aos limites do tabuleiro. No caso de um tabuleiro bidimensional, por exemplo, o personagem só pode andar nas direções x ou y, ou seja, movimentos diagonais não são permitidas. Além disso, o movimento pode se dar em qualquer sentido, desde que seguindo a restrição anterior. Novamente, no caso bi-dimensional, o personagem pode se movimentar nas direções +x, -x, +y ou -y.

A ordem de jogadas e a casa inicial dos jogadores é definida no começo do jogo. No nosso caso, essa ordem e as casas iniciais serão dadas como entrada do problema.

Definidas as posições iniciais, vamos começar o jogo. Seguindo a ordem posteriormente sorteada, cada jogador pula o número de casas escrito na sua posição, em qualquer sentido permitido e desejado. A ordem de jogadas nas rodadas seguintes é definida pelo tamanho do pulo anterior. A regra é que tem maior prioridade aquele que pulou a menor quantidade de casas na rodada anterior e, em caso de empate, tem prioridade o jogador que jogou antes na primeira rodada.

O jogo pode terminar de duas maneiras: i) a vitória de algum jogador; e ii) a impossibilidade de vitória. No primeiro caso, o jogo termina quando o primeiro jogador atinge a última casa do tabuleiro. Já no segundo caso, o jogo acaba quando fica definido que nenhum jogador conseguirá vencer nunca o jogo (jogo sem vencedores).

Um jogo sem vencedores pode ocorrer quando nenhum jogador consegue chegar na ultima posição do tabuleiro. Isso pode acontecer ao cair em uma casa marcada com o número 0 (e ele não conseguiria sair de lá), ou ao ficar rodando sempre pelas mesmas casas, sem conseguir sair delas.

## Objetivo

O objetivo deste trabalho é definir, para um determinado tabuleiro bidimensional, um determinado número de jogadores (com nomes), determinada posição e ordem inicial, qual jogador será o vencedor e em qual rodada.

Podemos assumir que:
- Após escolhidas as posições iniciais, os jogadores adotarão sempre a melhor estratégia (aquela que lhe dará maiores chances de vencer);
- Como se trata de um jogo bidimensional, os jogadores podem pular nas direções +x, −x, +y ou −y;
- O pulo deve sempre respeitar os limites do tabuleiro (claro que um jogador não pode pular para fora do tabuleiro);
- Para um tabuleiro de dimensões M × N, a última casa é a casa (M − 1, N − 1); 
- A ordem na qual os jogadores são apresentados, é a ordem inicial (primeiro jogador apresentado é o primeiro a jogar).

Importante ficar atento:
- Cuidado com loops na solução (jogador que fica pulando entre as mesmas duas casas, por exemplo);
- Evite calcular caminhos de jogadores que não tem chances de ganhar (se um jogador A chega na casa X em alguma rodada, um outro jogador que atinja essa mesma casa em rodadas posteriores tem alguma chance de ganhar o jogo?);
- Pense que existe uma prioridade a ser seguida ao decidir quem será o próximo a pular, e qual a melhor estrutura de dados a ser usada para isso;
- Pense em que situações o programa deve assumir que não existem vencedores;
- Pesquise sobre BFS em grafos, e veja as possíveis modificações para este problema específico.


