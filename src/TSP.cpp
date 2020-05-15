#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include <string>
#include <iostream>

#include "../constants.h"
#include "graph.h"
#include "TSP.h"

using namespace std;

TSP::TSP(Graph graph, string name) :
    graph(graph),
    cities(new int[graph.getV()]),
    distance(MAX),
    name(name) {}

void TSP::printClock()
{
    cout << "Time elapsed for " << name << ": " << fixed
        << time << setprecision(5);
    cout << " sec " << endl;
}

double TSP::runAndCountTime()
{
    clock_t start, end;

    start = clock();
    cout << "Starting: " << name << endl;
    run();
    cout << "Ending: " << name << endl;
    end = clock();

    time = double(end - start) / double(CLOCKS_PER_SEC);
    totalTime += time;
    printClock();

    return time;
}

void printArray(int *array, int n)
{
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
}

void TSP::showResult()
{
    cout << "V: " << this->graph.getV() << endl;
    cout << "Shortest distance: " << distance << endl;
    cout << "Shortest path:" << endl;
    printArray(cities, graph.getV());
}

/**
 * Função que percorre um determinado conjunto de vertices dado em um array de inteiro
 * e faz a soma de seus pesos
 * 
 * @param array array de inteiro com os vértices a serem visitados
 * 
 * @return Custo ao seguir essa sequência de vértices.
 */
double TSP::sumPath(int *array, int arraySize)
{
    double sum = 0.0;
    int weight;
    double **graphMatrix = this->graph.getGraph();

    for (int i = 0, j = 1; j < arraySize; i++, j++)
    {
        weight = graphMatrix[array[i]][array[j]];

        if (weight != UNDEFINED) sum += weight;
        else return -1; // O caminho não gera um ciclo hamiltoniano (faltou aresta)
    }
    
    return sum;
}

/**
 * Função que percorre um determinado conjunto de vertices dado em um array de inteiro
 * e faz a soma de seus pesos
 * 
 * @param array array de inteiro com os vértices a serem visitados
 * 
 * @return Custo ao seguir essa sequência de vértices.
 */
double TSP::sumPath(int *array)
{
    return sumPath(array, this->graph.getV() + 1);
}
