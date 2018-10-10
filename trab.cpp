#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <stack>

#include "trab.h"

using namespace std;

Grafo::Grafo(int nVertex)
{
    this->nVertex = nVertex;
    adj = new list<int>[nVertex];
}

void Grafo::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

// The function to do Topological Sort.
void Grafo::khanSort()
{
    // Create a vector to store indegrees of all
    // vertices. Initialize all indegrees as 0.
    vector<int> in_degree(nVertex, 0);

    // Traverse adjacency lists to fill indegrees of
    // vertices.  This step takes O(nVertex+E) time
    for (int u = 0; u < nVertex; u++)
    {
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
            in_degree[*itr]++;
    }

    // Create an queue and enqueue all vertices with
    // indegree 0
    queue<int> q;
    for (int i = 0; i < nVertex; i++)
        if (in_degree[i] == 0)
            q.push(i);

    // Initialize count of visited vertices
    int cnt = 0;

    // Create a vector to store result (A topological
    // ordering of the vertices)
    vector<int> top_order;

    // One by one dequeue vertices from queue and enqueue
    // adjacents if indegree of adjacent becomes 0
    while(!q.empty()){
        // Extract front of queue (or perform dequeue)
        // and add it to topological order
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        // Iterate through all its neighbouring nodes
        // of dequeued node u and decrease their in-degree
        // by 1
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)

            // If in-degree becomes zero, add it to queue
            if (--in_degree[*itr] == 0)
                q.push(*itr);

        cnt++;
    }

    // Check if there was a cycle
    if (cnt != nVertex)
    {
        cout << "There exists a cycle in the grafo\n";
        return;
    }

    // Print topological order
    cout << "Usando o Algoritmo de Khan, temos a seguinte ordenacao topologica\n";
    for (int i = 0; i < top_order.size(); i++){
        cout << top_order[i] << " ";
    }
    cout << endl;
}

//Funcao recursiva do dfs para visitar os nos
void Grafo::visitar(int v, bool visitado[], stack<int> &Pilha)
{
    // Mark the current node as visitado
    visitado[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visitado[*i])
            visitar(*i, visitado, Pilha);

    // Push current vertex to pilha which stores result
    Pilha.push(v);
}

// Inicia o dfs, fazendo chamadas recursivas da funcao 'visitar'
void Grafo::DFS()
{
    stack<int> Pilha;

    // inicializa os vertices como nao visitados
    bool *visitado = new bool[nVertex];
    for (int i = 0; i < nVertex; i++)
        visitado[i] = false;

    //Faz a chamada de todos os nos
    for (int i = 0; i < nVertex; i++)
        if (visitado[i] == false)
            visitar(i, visitado, Pilha);

    // imprime a pilha, com a ordenacao feita
    cout << "\n\nUsando o Algoritmo de DFS, temos a seguinte ordenacao topologica\n";
    while (Pilha.empty() == false)
    {
        cout << Pilha.top() << " ";
        Pilha.pop();
    }
}

