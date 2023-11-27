#include <iostream>
#include "Exercicio01.h"

int main() {
    Exercicio01 exercicio1;

    std::vector<std::vector<int>> grafoNaoDirecionado = {{0, 1, 0, 0, 1},
                                                        {1, 0, 1, 1, 1},
                                                        {0, 1, 0, 1, 0},
                                                        {0, 1, 1, 0, 1},
                                                        {1, 1, 0, 1, 0}};

    std::vector<std::vector<int>> grafoDirecionado = {{0, 1, 0, 1, 0, 0},
                                                     {0, 0, 0, 0, 1, 0},
                                                     {0, 0, 0, 0, 1, 1},
                                                     {0, 1, 0, 0, 0, 0},
                                                     {0, 0, 0, 1, 0, 0},
                                                     {0, 0, 0, 0, 0, 1}};

    std::vector<std::vector<int>> grafoDesconexo = {{0, 1, 0, 0},
                                                    {1, 0, 0, 1},
                                                    {0, 0, 0, 0},
                                                    {0, 1, 0, 0}};

    std::vector<std::vector<int>> grafoConexo = {{0, 1, 0, 0},
                                                 {1, 0, 0, 1},
                                                 {0, 0, 1, 0},
                                                 {0, 1, 0, 0}};

    std::vector<std::vector<int>> grafoCiclico1 = {{0, 1, 0, 1},
                                                   {1, 0, 1, 0},
                                                   {0, 1, 0, 1},
                                                   {1, 0, 1, 0}};

    std::vector<std::vector<int>> grafoAciclico1 = {{0, 1, 0, 0},
                                                    {0, 0, 0, 0},
                                                    {0, 0, 0, 0},
                                                    {0, 0, 0, 0}};

    exercicio1.quantidadeArestas(grafoNaoDirecionado);
    exercicio1.quantidadeArestas(grafoDirecionado);

    std::cout << "=========================" << std::endl;
    exercicio1.direcionadoOuNao(grafoNaoDirecionado);
    exercicio1.direcionadoOuNao(grafoDirecionado);

    std::cout << "=========================" << std::endl;
    exercicio1.grauDeCadaVertice(grafoNaoDirecionado);
    std::cout << std::endl;
    exercicio1.grauDeCadaVertice(grafoDirecionado);

    std::cout << "=========================" << std::endl;
    exercicio1.listaAdjacencia(grafoNaoDirecionado);
    std::cout << std::endl;
    exercicio1.listaAdjacencia(grafoDirecionado);

    std::cout << "=========================" << std::endl;
    exercicio1.conexoOuDesconexo(grafoDesconexo);
    exercicio1.conexoOuDesconexo(grafoConexo);

    std::cout << "=========================" << std::endl;
    exercicio1.ciclicoOuAciclico(grafoCiclico1);
    exercicio1.ciclicoOuAciclico(grafoAciclico1);

    return 0;
}
