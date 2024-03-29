#include <fstream>
#include <iostream>
#include <cctype>
using namespace std;

#define EQU_QUANT 5

/*
    Processa diretivas EQU e IF e salva resultado num arquivo chamado preproc.pre
*/
void preprocessamento(string nome_arquivo) {
    ifstream codigo_base;
    codigo_base.open(nome_arquivo);

        if (!(codigo_base.good())) {
            cout << "Erro ao abrir arquivo." << endl;
            return;
        }

    // abre novo arquivo para escrita
    ofstream newcode;
    newcode.open("preproc.pre");
    if (!(newcode.good())) {
        cout << "Erro ao criar arquivo" << endl;
        return;
    }

    string line;
    string var_name;
    string var_value;
    string str_label;
    string names[EQU_QUANT];
    string values[EQU_QUANT];
    char aux;
    int i, pos;
    int count_EQU = 0;
    int section_flag = 0;
    int label_flag = 0;

    // loop para leitura e escrita
    while (!(codigo_base.eof())) {
        if (label_flag == 0) {
            getline(codigo_base, line);
        } else {
            label_flag = 0;
        }

        // checa por linha vazia
        i = 0;
        while (i < int(line.length()) && isspace(line[i])) {
            i++;
        }
        if (i >= int(line.length()))
            continue;   // ignora linha vazia

        // checa por SECTION
        if (line.find("SECTION") != string::npos) {
            if (line.find("TEXT") != string::npos) {
                section_flag++;
            }
            continue;   // nao inclui linha
        }

        // retira comentario
        if (line.find(";") != string::npos) {
            // ignora espacos
            i = 0;
            while(isspace(line[i])) {
                i++;
            }
            if (line[i] == ';') {   // comentario de linha inteira
                continue;           // nao inclui linha
            } else {                // comentario inline
                i = 0;
                while(line[i] != ';') {
                    i++;
                }
                if (line[i] == ';') {   // apaga comentario
                    line.erase(i, string::npos);
                }
            }
        }

        // retira espacos desnecessarios
        i = 0;
        while (i < line.length()) {
            // retira espacos iniciais
            if (i == 0 && isspace(line[i])) {
                do {
                    line.erase(i, 1);
                } while (isspace(line[i]));
                continue;
            }

            if (!(isspace(line[i]))) {      // caracter nao e espaco
                // pula palavra
                while (!(isspace(line[i])) && i < line.length()) {
                    i++;
                }
                if (i == line.length()) {   // chegou ao fim e nao e espaco no fim
                    continue;
                }
            } else {                        // caracter e espaco
                // apaga espacos a mais
                do {
                    line.erase(i, 1);
                } while (isspace(line[i]));
                if (i < line.length()) {
                    line.insert(i, " ");
                    i++;
                }
            }

            // apaga espaco no final da linha
            if (i == (line.length() - 1) && isspace(line[i])) {
                line.erase(i, 1);
                continue;
            }
        }

        // retira Label + Enter
        if (line.find(':') != string::npos) {   // achou label
            i = int(line.find(':')) + 1;
            while (isspace(line[i]) && i < line.length()) {
                i++;
            }

            if (i == line.length()) {   // label sozinha na linha
                // apaga espaco no final da linha
                i = int(line.find(':')) + 1;
                while (i < (line.length())) {
                    line.erase(i, 1);
                }
                // salva label e adiciona espaco
                str_label = line;
                str_label.append(" ");
                // adiciona label na proxima linha
                getline(codigo_base, line);
                line.insert(0, str_label);

                label_flag = 1;
                continue;
            }
        }

        if (line.find("EQU") != string::npos) {
            // processa EQU
            // obtem nome da variavel do EQU
            var_name.clear();
            i = 0;
            aux = '0';
            while (!(isspace(line[i]))) {
                aux = line[i];
                var_name += aux;
                i++;
            }

            // obtem valor a ser substituido
            var_value.clear();
            i = line.find("EQU") + 3;
            aux = '0';
            // pula espacos
            while ((isspace(line[i]))) {
                i++;
            }
            // armazena valor
            while (!(isspace(line[i])) && i < (int)line.length()) {
                aux = line[i];
                var_value += aux;
                i++;
            }

            count_EQU++;

            // salva nome e valor
            names[count_EQU-1] = var_name;
            values[count_EQU-1] = var_value;

            continue;
        }

        // modificacoes para EQU
        if (count_EQU > 0) {
            for (int i = 0; i < count_EQU; i++) {
                if (line.find(names[i]) != string::npos) {
                    pos = line.find(names[i]);
                    line.replace(pos, names[i].length(), values[i]);
                }
            }
        }

        if (line.find("IF") != string::npos) {
            // processa IF
            i = 2;
            while (isspace(line[i])) {
                i++;
            }

            if (line[i] == '0') {
                getline(codigo_base, line);
            }
            continue;
        }

        // inclui linha no novo arquivo e limpa string
        line.append("\n");
        newcode << line;
        line.clear();
    }

    if (section_flag == 0) {
        cout << "WARNING: TEXT SECTION NOT FOUND" << endl;
    } else if (section_flag > 1) {
        cout << "WARNING: MULTIPLE TEXT SECTIONS FOUND" << endl;
    }

    newcode.close();
    codigo_base.close();

    return;
}

void file2UPPER(string base_filename, string new_filename) {
    ifstream base_file;
    base_file.open(base_filename);

    ofstream new_file;
    new_file.open(new_filename);

    string line_read, new_line;

    while (!(base_file.eof())) {
        getline(base_file, line_read);
        new_line.clear();
        for (int i = 0; i < (int)line_read.length(); i++) {
            if (isalpha(line_read[i])) {
                new_line += toupper(line_read[i]);
                continue;
            }
            new_line += line_read[i];
        }
        new_line += '\n';
        new_file << new_line;
    }

    base_file.close();
    new_file.close();

    return;
}

