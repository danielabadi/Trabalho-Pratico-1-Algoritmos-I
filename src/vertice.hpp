#ifndef VERTICE_H
#define VERTICE_H
#include<bits/stdc++.h>

struct Vertice{
	int valor;
	int id;
	std::vector<Vertice*> vizinhos;

	void cria_vizinhos(Vertice&);
	
};
#endif