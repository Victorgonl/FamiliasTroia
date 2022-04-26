// Victorgonl - FamiliasTroia-vector.cpp - 20220424



#include <vector>

typedef unsigned Vertice;


class Grafo{

	private:

		std::vector<std::vector<Vertice>> lista_adjacencia;
		unsigned n_vertices;

	public:

		Grafo(unsigned n){
			n_vertices = n;
			lista_adjacencia.resize(n_vertices);
			for(unsigned u = 0; u < n_vertices; u++){
				lista_adjacencia[u].reserve(n_vertices);
			}
		}

		void inserirAresta(Vertice u, Vertice v){
			lista_adjacencia[u].push_back(v);
		}

	friend void dfs(Grafo&, const Vertice&, std::vector<bool>&);
	friend unsigned contarComponentesConexas(Grafo&);
};


void dfs(Grafo& g, const Vertice& u, std::vector<bool>& visitados){

	visitados[u] = true;

	for(std::vector<Vertice>::iterator v = g.lista_adjacencia[u].begin(); v != g.lista_adjacencia[u].end(); v++){
		if(!visitados[*v]){
			dfs(g, *v, visitados);
		}
	}

}


unsigned contarComponentesConexas(Grafo& g){

	unsigned total = 0;

	std::vector<bool> visitados(g.n_vertices, false);

	for(unsigned u = 0; u < g.n_vertices; u++){
		if(!visitados[u]){
			dfs(g, u, visitados);
			total++;
		}
	}

	return total;
}



#include <iostream>


int main(){

	unsigned n, m;
	std::cin >> n >> m;

	Grafo grafo(n);

	Vertice u, v;
	for(unsigned i = 0; i < m; i++){
		std::cin >> u >> v;
		u--; v--;
		grafo.inserirAresta(u, v);
		grafo.inserirAresta(v, u);
	}

	std::cout << contarComponentesConexas(grafo);

	return 0;
}