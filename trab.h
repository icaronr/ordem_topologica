#ifndef TRAB_H
#define TRAB_H
#include <iostream>
#include <list>
#include <stack>
#include <string>

using namespace std;

// Classe do grafo
class Grafo
{
    int nVertex; // No. of vertices

    // Pointer to an array containing adjacency listsList
    list<int> *adj;

  public:
    Grafo(int nVertex); // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v);

    // prints a Topological Sort of the complete graph
    void khanSort();

    void visitar(int v, bool visitado[], stack<int> &Pilha);
    void DFS();

};

#endif