# Victorgonl - FamiliasTroia.py - 20220424



class Grafo:

    lista_adjacencia = []
    n_vertices = 0

    def __init__(self, n):
        self.n_vertices = n
        self.lista_adjacencia = [[] for _ in range(self.n_vertices)]

    def inserirAresta(self, u, v):
        self.lista_adjacencia[u].append(v)


def contarComponentesConexas(grafo) -> int:

    n = 0

    visited = [False for _ in range(grafo.n_vertices)]

    for u in range(grafo.n_vertices):
        if (visited[u] == False):
            dfs(grafo, u, visited)
            n += 1

    return n


def dfs(grafo: Grafo, u, visited: list) -> None:

    visited[u] = True

    for i in grafo.lista_adjacencia[u]:
        if (not visited[i]):
            dfs(grafo, i, visited)



from sys import setrecursionlimit
setrecursionlimit(50000)


def main() -> None:

    n, m = map(int, input().split(maxsplit=1))

    grafo = Grafo(n)

    for _ in range(m):
        u, v = map(int, input().split(maxsplit=1))
        u, v = u - 1, v - 1
        grafo.inserirAresta(u, v)
        grafo.inserirAresta(v, u)

    print(contarComponentesConexas(grafo), end="")


main()
