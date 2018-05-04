#include <iostream>
#include <string>

#include "trab.h"
#include "leitor.h"

int main()
{
    
    while(true){
        printf("\e[1;1H\e[2J");
        int opcao = 0, numVertex;
        string arquivo;
        cout << "Escolha uma opcao: " << endl;
        cout << "1 - 10" << endl;
        cout << "2 - 100" << endl;
        cout << "3 - 10000" << endl;
        cout << "4 - 100000" << endl;
        cout << "5 - sair do programa" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            arquivo = "top_small.txt";
            executa(arquivo);
            break;
        case 2:
            arquivo = "top_med.txt";
            executa(arquivo);
            break;
        case 3:
            arquivo = "top_large.txt";
            executa(arquivo);
            break;
        case 4:
            arquivo = "top_huge.txt";
            executa(arquivo);
            break;
        case 5:exit(0); break;
        default:
            cout << "OPCAO INVALIDA !!!!" << endl;
        }
        getchar();
        getchar();
    }


    return 0;
}