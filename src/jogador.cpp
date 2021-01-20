#include "jogador.hpp"

Jogador::Jogador(Vertice &posicao_inicial, int quantidade_vertices){
	//Recebe o endereço de memória do vértice que representa a posição inicial do jogador.
	this->posicao_inicial = &posicao_inicial;
	
	//Cria o grafo.
	this->grafo = new Grafo(quantidade_vertices);
	
	//Chama o procedimento BFS
	this->grafo->BFS(*(this->posicao_inicial), quantidade_vertices);
	
	//Recebe o número de jogadas que o jogador fez, nesse caso a camada em que foi encontrado o vértice final.
	this->casas_andadas = this->grafo->jogadas;
	
	//Recebe o valor da penúltima casa que o jogador esteve.
	this->desempate = this->grafo->penultimo_valor;
}