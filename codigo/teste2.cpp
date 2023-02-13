#include <bits/stdc++.h>
using namespace std;

struct mem
{
    int tipo;
    string msg;
    int size;
};


int main(int argc, char const *argv[])
{
    fstream codigo_base;
    codigo_base.open("teste.asm", fstream::in);
    string line, word;
    smatch var;
    mem token;

    while (getline(codigo_base, line))
    {
        if(regex_search(line,var,regex("CONST")))
        {
            string label, arg;
            if(regex_match(line, regex(".+\\d")))
            {
                label = regex_replace(line, regex(":.+$"), "$2");
                arg = regex_replace(line, regex("\\D+"), "$2");
                cout << label << " dd " << arg << endl;
            }
            else
            {
                label = regex_replace(line, regex(":.+$"), "$2");
                arg = regex_replace(line, regex(".+ "), "$2");
                cout << label << " db " << arg << endl;
            }
        }
        else if(regex_search(line,var,regex("SPACE")))
        {
            if(regex_match(line, var, regex("^.+\\d+$")))
            {   
                string label, size;
                label = regex_replace(line, regex(":.*"), "$2");
                size = regex_replace(line, regex(".+\\+"), "$2");
                cout << label << ": resd " << size << endl;
            }
            else
            {
                string label;
                label = regex_replace(line, regex(":.*"), "$2");
                cout << label << ": resd 1" << endl;
            }
        }
    }

    return 0;
}
