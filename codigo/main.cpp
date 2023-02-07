#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "preprocessamento.h"
#include "tradutor.h"

/*
    Modo de usar o programa:
    ./montador -<arquivo>

    Arquivo sem extensao - assumir que usuario usa extensoes corretas
*/

int main(int argc, char* argv[]) {
    if (argc == 2) {    // qtd de argumentos correta

        string nome_arquivo;
        nome_arquivo = (string)argv[1] + ".asm";

        // converte texto para all caps
        string nome_arq_upper;
        nome_arq_upper = (string)argv[1] + "UPPER.asm";
        file2UPPER(nome_arquivo, nome_arq_upper);
        string nome_preproc;
        nome_preproc = "preproc.pre";

        preprocessamento(nome_arq_upper);
        parser();
        tradutor();

    } else {    // qtd de argumentos incorreta
        cout << "Uso incorreto do programa. Exemplo de uso: ./montador programa" << endl;
    }

    return 0;
}