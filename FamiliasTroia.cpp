// Victorgonl - FamiliasTroia.cpp - 20220424



class Grafo;


class Vertice{

	private:

		unsigned valor;
		Vertice* proximo;

	public:

		Vertice(unsigned v, Vertice* p = nullptr){
			valor = v;
			proximo = p;
		}

	friend class Grafo;
	friend void dfs(Grafo& g, int u, bool*& visitados);
};


class Grafo{

	private:

		Vertice** lista_adjacencia;
		unsigned n_vertices;

	public:

		Grafo(int n){

			n_vertices = n;
			lista_adjacencia = new Vertice*[n_vertices];

			for (unsigned i = 0; i < n_vertices; i++){
				lista_adjacencia[i] = nullptr;
			}

		}

		~Grafo(){

			for(unsigned i = 0; i < n_vertices; i++){
				while(lista_adjacencia[i] != nullptr){
					Vertice* temp = lista_adjacencia[i];
					lista_adjacencia[i] = lista_adjacencia[i]->proximo;
					delete temp;
				}
			}

			delete[] lista_adjacencia;

		}

		void inserirAresta(unsigned u, unsigned v){
			Vertice* novo_vertice = new Vertice(v, lista_adjacencia[u]);
			lista_adjacencia[u] = novo_vertice;
		}

	friend void dfs(Grafo& g, int u, bool*& visitados);
	friend unsigned contarComponentesConexas(Grafo& g);
};


void dfs(Grafo& g, int u, bool*& visitados){

	visitados[u] = true;

	for(Vertice* i = g.lista_adjacencia[u]; i != nullptr; i = i->proximo)
		if(!visitados[i->valor]){
			dfs(g, i->valor, visitados);
		}
}


unsigned contarComponentesConexas(Grafo& g){

	unsigned total = 0;

	bool* visitados = new bool[g.n_vertices]();

	for(unsigned u = 0; u < g.n_vertices; u++){
		if(!visitados[u]){
			dfs(g, u, visitados);
			total++;
		}
	}

	delete[] visitados;

	return total;
}



#include <iostream>


int main(){

	unsigned n, m;
	std::cin >> n >> m;

	Grafo grafo(n);

	unsigned u, v;
	for(unsigned i = 0; i < m; i++){
		std::cin >> u >> v;
		u--; v--;
		grafo.inserirAresta(u, v);
		grafo.inserirAresta(v, u);
	}

	std::cout << contarComponentesConexas(grafo);

	return 0;
}