#ifndef EXERCICIO01_H
#define EXERCICIO01_H

#include <vector>
#include <list>

class Exercicio01 {
public:
    void quantidadeArestas(std::vector<std::vector<int>>& grafo);
    void direcionadoOuNao(std::vector<std::vector<int>>& grafo);
    void grauDeCadaVertice(std::vector<std::vector<int>>& grafo);
    void conexoOuDesconexo(std::vector<std::vector<int>>& grafo);
    void ciclicoOuAciclico(std::vector<std::vector<int>>& grafo);
    void listaAdjacencia(std::vector<std::vector<int>>& matriz);

private:
    bool todasLinhasEColunasZeradas(std::vector<std::vector<int>>& grafo, int vertice);
    bool possuiCicloRecursiva(std::vector<std::vector<int>>& grafo, int verticeAtual, int pai, std::vector<bool>& visitado);
};

#endif // EXERCICIO01_H
