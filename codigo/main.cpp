#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "preprocessamento.h"
#include "tradutor.h"

/*
    Modo de usar o programa:
    ./tradutor -<arquivo>

    Arquivo sem extensao - assumir que usuario usa extensoes corretas
*/

int main(int argc, char* argv[]) {
    if (argc == 2) {    // qtd de argumentos correta

        string nome_arquivo;
        nome_arquivo = (string)argv[1] + ".asm";
        string nome_no_extension = (string)argv[1];

        // converte texto para all caps
        string nome_arq_upper;
        nome_arq_upper = (string)argv[1] + "UPPER.asm";
        file2UPPER(nome_arquivo, nome_arq_upper);
        preprocessamento(nome_arq_upper);
        tradutor(nome_no_extension);

    } else {    // qtd de argumentos incorreta
        cout << "Uso incorreto do programa. Exemplo de uso: ./tradutor programa" << endl;
    }

    return 0;
}