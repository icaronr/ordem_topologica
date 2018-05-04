#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "leitor.h"


ifstream myFile;

//Retorna o numero de vertices
int primeiraLeitura(string arquivo){
   
   int N;
   myFile.open(arquivo);
   if(myFile.is_open()){
       myFile >> N;
       cout << endl << N << endl;
   }else{
       cout << "Erro ao abrir o arquivo!" << endl;
       return -1;
   }
   return N;
}
//Retorna as arestas
void segundaLeitura(Grafo *g)
{
    int origem, destino;
    int i=0;
    if(myFile.is_open()){
        while(myFile.good()){
            myFile >> origem >> destino;
          //  cout << " origem  - " << origem << endl;
          //  cout << " destno  - " << destino << endl;
          g->addEdge(origem, destino);
            i++;
        }
    }else{
        cout << "ERRO NO ARQUIVO!!!!" << endl;
    }
    cout << "NUMERO DE ARESTAS - " << i << endl;
    myFile.close();
    return;
}

void executa(string arquivo){
    int numVertex;
    numVertex = primeiraLeitura(arquivo);
    Grafo g(numVertex);
    segundaLeitura(&g);
    g.khanSort();
    g.DFS();
}