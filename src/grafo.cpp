#include "grafo.hpp"
//Cria o grafo.
Grafo::Grafo(int quantidade_vertices){
	this->quantidade_vertices = quantidade_vertices;
}

void Grafo::BFS(Vertice &vertice, int id_final){
	int id, num_vizinhos, penultimo_valor;
	int descobertos[this->quantidade_vertices]; //Inicializa um vetor que representa os vértices que já foram encontrados.
	int camada[this->quantidade_vertices]; //Inicializa outro vetor que representa qual a camada que o vértice foi encontrado.
	
	for(int i = 0; i <= this->quantidade_vertices; i++){ //Zera todo o vetor.
		descobertos[i] = 0;
	}
	
	descobertos[vertice.id] = 1;
	//Cria uma fila de Pair que recebe o endereço do vértice o um inteiro que representa o valor do vértice anterior.
	std::queue<std::pair <Vertice*, int>> fila; 
	fila.push({&vertice, vertice.valor});
	camada[vertice.id] = 0; //Inicializa com a camada 0.
	
	while(!fila.empty()){
		Vertice* vertice = fila.front().first;
		penultimo_valor = fila.front().second;
		fila.pop();
		
		num_vizinhos = vertice->vizinhos.size();
		
		for(int i = 0; i < num_vizinhos; i++){
			id = vertice->vizinhos[i]->id;
			if(descobertos[id] == 0){
				descobertos[id] = 1;
				fila.push({vertice->vizinhos[i], vertice->valor});
				camada[id] = camada[vertice->id] + 1;
			}
			if(id == id_final){
				this->chegaram_final.push_back({camada[id], penultimo_valor});
			}
		}
	}
	if(this->chegaram_final.size() > 0){
		desempate();
	}
}
//Tenta cobrir o corner case citado na documentação, na subseção 2.3.2
void Grafo::desempate(){
	int menos_jogadas = this->chegaram_final[0].first;
	int menor_casa = this->chegaram_final[0].second;
	int tamanho_vector = this->chegaram_final.size();
	for(int i = 1; i < tamanho_vector; i++){
		if(this->chegaram_final[i].first < menos_jogadas){
			menos_jogadas = this->chegaram_final[i].first;
			menor_casa = this->chegaram_final[i].second;
		} else if(this->chegaram_final[i].first == menos_jogadas){
			if(this->chegaram_final[i].second < menor_casa){
				menos_jogadas = this->chegaram_final[i].first;
				menor_casa = this->chegaram_final[i].second;
			}
		}
	}
	this->jogadas = menos_jogadas;
	this->penultimo_valor = menor_casa;
}