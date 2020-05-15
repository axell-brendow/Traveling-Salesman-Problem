/**
 * Travelling Salesman Problem implementations:
 * - Brute force
 * - Branch and bound
 * - Dynamic programming
 * - Genetic algorithm
 */
class TSP
{
private:
    Graph graph;

    double distance;
    int *cities;

    /* Funções auxiliares do paradigma de Força Bruta */
    void permutation(int array[], int size, int n);
    void walkThePath(int *array);
    void showResult();
    int *initializePath(int *paths, int V);

    /* Funções auxiliares do paradigma de Força Bruta */
    void branchAndBound(int parcial, int nivel, int* caminhoParcial, bool* visitados, int menorCaminho);

public:
    TSP(Graph graph);

    /* Funções dos algoritmos dos paradigmas */
    void bruteForce();
<<<<<<< HEAD
    void branchAndBound();
=======
    void geneticAlgorithm();
>>>>>>> b8bff29577923de93f1dc15bcf5dd5afffbe0a9e
};