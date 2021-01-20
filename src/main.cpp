#include "jogador.hpp"
#include <fstream>

int main(int argc, char* argv[]){
	std::ifstream arq;
	
	arq.open(argv[1]); 
	 if(!arq.is_open()){
        return 0;
    }
	
	int m, n, k, valor, posicaox, posicaoy, id, menor_num_jogadas, penultima_jogada, ganhador;
	arq >> n >> m >> k;
	Vertice **tabuleiro = new Vertice *[n];
	for(int i = 0; i < n; i++){
		tabuleiro[i] = new Vertice[m];
	}
	Jogador* jogadores[k];
	
	//O bloco abaixo faz toda a operação que recebe os dados do tabuleiro e define o ID de cada vértice.
	id = 1;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			arq >> valor;
			tabuleiro[i][j].valor = valor;
			tabuleiro[i][j].id = id;
			id++;
		}
	} 
	
	
	//Este bloco define os vizinhos de cada vértice.
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(tabuleiro[i][j].valor == 0) continue;
			posicaox = i - tabuleiro[i][j].valor;
			posicaoy = j - tabuleiro[i][j].valor;
			if(posicaox >= 0) tabuleiro[i][j].cria_vizinhos(tabuleiro[posicaox][j]);
			if(posicaoy >= 0) tabuleiro[i][j].cria_vizinhos(tabuleiro[i][posicaoy]);
			
			posicaox = i + tabuleiro[i][j].valor;
			posicaoy = j + tabuleiro[i][j].valor;
			if(posicaox < n) tabuleiro[i][j].cria_vizinhos(tabuleiro[posicaox][j]);
			if(posicaoy < m) tabuleiro[i][j].cria_vizinhos(tabuleiro[i][posicaoy]);
		}
	}
	//Cria todos os jogadorese já faz todo o processo do BFS.
	for(int i = 0; i < k; i++){
		arq >> posicaox >> posicaoy;
		jogadores[i] = new Jogador(tabuleiro[posicaox][posicaoy], m*n);
	}
	
	
	//Com todos os BFS's feitos, este bloco de código define quem é o ganhador, se houver um.
	menor_num_jogadas = jogadores[0]->casas_andadas;
	penultima_jogada = jogadores[0]->desempate;
	ganhador = 1;
	for(int i = 0; i < k; i++){
		if(jogadores[i]->casas_andadas == -1) continue;
		if(jogadores[i]->casas_andadas == 1){
			menor_num_jogadas = 1;
			penultima_jogada = 0;
			ganhador = i+1;
			break;
		} else if(jogadores[i]->casas_andadas < menor_num_jogadas){
			menor_num_jogadas = jogadores[i]->casas_andadas;
			penultima_jogada = jogadores[i]->desempate;
			ganhador = i+1;
		} else if(jogadores[i]->casas_andadas == menor_num_jogadas && jogadores[i]->desempate < penultima_jogada){
			menor_num_jogadas = jogadores[i]->casas_andadas;
			penultima_jogada = jogadores[i]->desempate;
			ganhador = i+1;
		}
	}
	
	//Desalocação das variáveis.
	for (int i = 0; i < n; ++i){
		delete [] tabuleiro[i];
	}
	delete [] tabuleiro;
	
	for(int i = 0; i < k; i++){
		delete jogadores[i]->grafo;
		delete jogadores[i];
	}
	
	//Impressão do resultado do jogo.
	char vencedor;
	if(menor_num_jogadas < 0){
		std::cout << "SEM VENCEDORES\n"; 
	} else{
		vencedor = ganhador + 64;
		std::cout << vencedor << "\n" << menor_num_jogadas << "\n";
	}
	arq.close();
	return 0;
}