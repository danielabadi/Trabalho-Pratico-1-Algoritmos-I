#include "vertice.hpp"
void Vertice::cria_vizinhos(Vertice &vizinho){
	this->vizinhos.push_back(&vizinho);
}