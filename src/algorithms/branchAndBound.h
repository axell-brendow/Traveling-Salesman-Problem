#pragma once

#include "../TSP.h"
#include "../graph.h"

class BranchAndBound : public TSP
{
public:
    BranchAndBound();
    BranchAndBound(Graph &graph);
    BranchAndBound(Graph &&graph);

    void run();

    void atualizarMelhorCaminho(int *caminhoParcial);
    void branchAndBound(double **matriz, double parcial, int nivel,
                        int *caminhoParcial, bool *visitados);
    int primeiroMenor(int vertice);
    int segundoMenor(int vertice);
};
