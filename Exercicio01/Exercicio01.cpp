#include "Exercicio01.h"
#include <iostream>
#include <vector>
#include <list>

void Exercicio01::quantidadeArestas(std::vector<std::vector<int>>& grafo) {
    int tamanho = grafo.size();

    for (int x = 0; x < tamanho; x++) {
        for (int y = 0; y < tamanho; y++) {
            if (grafo[x][y] != 0) {
                std::cout << "{" << x << "," << y << "}, ";
            }
        }
    }
    std::cout << std::endl;
}

void Exercicio01::direcionadoOuNao(std::vector<std::vector<int>>& grafo) {
    int tamanho = grafo.size();
    bool grafoDirecionado = false;

    for (int x = 0; x < tamanho; x++) {
        for (int y = 0; y < tamanho; y++) {
            if (grafo[x][y] != grafo[y][x]) {
                grafoDirecionado = true;
                x = y = tamanho + 1;
            }
        }
    }

    if (grafoDirecionado) {
        std::cout << "O grafo é direcionado" << std::endl;
    } else {
        std::cout << "O grafo não é direcionado" << std::endl;
    }
}

void Exercicio01::grauDeCadaVertice(std::vector<std::vector<int>>& grafo) {
    int tamanho = grafo.size();
    int grauDoVertice = 0;

    for (int x = 0; x < tamanho; x++) {
        for (int y = 0; y < tamanho; y++) {
            if (grafo[x][y] != 0)
                grauDoVertice++;
        }
        std::cout << "Grau do vértice [" << x << "] = " << grauDoVertice << std::endl;
        grauDoVertice = 0;
    }
}

void Exercicio01::conexoOuDesconexo(std::vector<std::vector<int>>& grafo) {
    bool desconexo = false;
    int i;

    for (i = 0; i < grafo.size(); i++) {
        if (todasLinhasEColunasZeradas(grafo, i)) {
            desconexo = true;
            break;
        }
    }

    if (desconexo) {
        std::cout << "Grafo é desconexo por causa do " << (i + 1) << "º vértice." << std::endl;
    } else {
        std::cout << "Grafo é conexo" << std::endl;
    }
}

bool Exercicio01::todasLinhasEColunasZeradas(std::vector<std::vector<int>>& grafo, int vertice) {
    for (int i = 0; i < grafo.size(); i++) {
        if (grafo[vertice][i] != 0) {
            return false;
        }
    }

    for (int i = 0; i < grafo.size(); i++) {
        if (grafo[i][vertice] != 0) {
            return false;
        }
    }

    return true;
}

void Exercicio01::ciclicoOuAciclico(std::vector<std::vector<int>>& grafo) {
    bool ciclico = false;
    int vertices = grafo.size();
    std::vector<bool> visitado(vertices, false);

    for (int i = 0; i < vertices; i++) {
        if (!visitado[i] && possuiCicloRecursiva(grafo, i, -1, visitado)) {
            ciclico = true;
            break;
        }
    }

    if (ciclico) {
        std::cout << "O grafo é cíclico" << std::endl;
    } else {
        std::cout << "O grafo é acíclico" << std::endl;
    }
}

bool Exercicio01::possuiCicloRecursiva(std::vector<std::vector<int>>& grafo, int verticeAtual, int pai, std::vector<bool>& visitado) {
    visitado[verticeAtual] = true;

    for (int vizinho = 0; vizinho < grafo.size(); vizinho++) {
        if (grafo[verticeAtual][vizinho] == 1) {
            if (!visitado[vizinho]) {
                if (possuiCicloRecursiva(grafo, vizinho, verticeAtual, visitado)) {
                    return true;
                }
            } else if (vizinho != pai) {
                return true;
            }
        }
    }

    return false;
}

void Exercicio01::listaAdjacencia(std::vector<std::vector<int>>& matriz) {
    int tamanho = matriz.size();
    std::vector<std::list<int>> arestas(tamanho);

    for (int x = 0; x < tamanho; x++) {
        for (int y = 0; y < tamanho; y++) {
            if (matriz[x][y] == 1) {
                arestas[x].push_back(y);
            }
        }

        std::cout << x << " >>> ";
        for (int neighbor : arestas[x]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}
