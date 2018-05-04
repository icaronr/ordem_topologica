#ifndef LEITOR_H
#define LEITOR_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "trab.h"

//Retorna o numero de vertices
int primeiraLeitura(string arquivo);

//Retorna as arestas
void segundaLeitura(Grafo* g);

void executa(string arquivo);


#endif