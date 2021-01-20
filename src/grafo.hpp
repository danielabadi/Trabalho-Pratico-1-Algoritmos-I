#ifndef GRAFO_H
#define GRAFO_H
#include "vertice.hpp"
struct Grafo{
	int quantidade_vertices;
	int jogadas = -1;
	int penultimo_valor;
	std::vector<std::pair<int, int>> chegaram_final;
	
	Grafo(int);
	void BFS(Vertice&, int);
	void desempate();
};
#endif