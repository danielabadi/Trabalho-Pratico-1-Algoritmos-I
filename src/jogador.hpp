#ifndef JOGADOR_H
#define JOGADOR_H
#include "grafo.hpp"

struct Jogador{
	Vertice* posicao_inicial;
	Grafo* grafo;
	int casas_andadas = 0, desempate;
	Jogador(Vertice&, int);
};
#endif