#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <locale>
#include <memory>

#include "graph.h"
#include "TSP.h"
#include "constants.h"
#include "arguments.h"
#include "algorithms/branchAndBound.h"
#include "algorithms/bruteForce.h"
#include "algorithms/dynamicProgramming.h"
#include "algorithms/geneticAlgorithm.h"

using namespace std;

template <typename Algorithm>
double runAlgorithm(Graph &graph)
{
    TSP &&algorithm = Algorithm(graph);
    return algorithm.runAndCountTime();
}

template <typename Algorithm>
void debug()
{
    Graph graph(4);

    graph.createLigation(0, 1, 10);
    graph.createLigation(0, 2, 15);
    graph.createLigation(0, 3, 20);
    graph.createLigation(1, 2, 35);
    graph.createLigation(1, 3, 25);
    graph.createLigation(2, 3, 30);

    /*
    Graph graph(10);

    graph.newRandomGraph();
    */

    graph.print();
    runAlgorithm<Algorithm>(graph);
}

int main(int argc, char **argv)
{
    // debug<BranchAndBound>();
    vector<unique_ptr<TSP>> algorithms;
    readArgs(argc, argv, algorithms);

    srand(time(NULL));
    int vertexs, edges;
    int x, y, weight;

    int actualV = 3;

    while (scanf("%d %d", &vertexs, &edges) != EOF)
    {
        if (actualV != vertexs) //calcula a média de tempo dos grafos calculados de V vertices
        {
            for (auto &&algorithm : algorithms)
            {
                cout << "MEDIA " << algorithm->getName()
                    << " n = " << actualV << ": "
                    << algorithm->getTotalTime() / NUMBEROFGRAPHS << " ms" << endl;
                    
                algorithm->setTotalTime(0);
            }

            actualV = vertexs;
        }

        Graph graph(vertexs);
        for (int i = 0; i < edges; i++)
        {
            cin >> x;
            cin >> y;
            cin >> weight;

            graph.createLigation(x, y, weight);
        }

        // graph.print();

        for (const auto &algorithm : algorithms)
        {
            algorithm->setGraph(graph);
            algorithm->runAndCountTime();
            cout << "----------------" << endl;
        }
    }
}
