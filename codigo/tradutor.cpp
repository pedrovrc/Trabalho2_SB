#include <fstream>
#include <iostream>
#include "tradutor.h"
using namespace std;

ofstream saida;

// INPUT
void instrINPUT(string label, int size)
{

}
void functINPUT()
{
    
}
// OUTPUT
void instrOUTPUT(string label) {
    cout << "push " << label << endl;
    cout << "call _OUTPUT" << endl;
    cout << "add esp,4" << endl;
}

void functOUTPUT() {
    cout << "_OUTPUT:" << endl;
    cout << "enter 20, 0" << endl;
    cout << "push ebx" << endl;
    cout << "push ecx" << endl;
    cout << "push edx" << endl;
    cout << "mov BYTE [ebp-15], 0" << endl;
    cout << "cmp DWORD [ebp+8], 0" << endl;
    cout << "jl negativo" << endl;
    cout << "mov BYTE [ebp-14], 0" << endl;
    cout << "jmp div_start" << endl;
    cout << "negativo: mov BYTE [ebp-14], '-'" << endl;
    cout << "mov DWORD [ebp-20], 0" << endl;
    cout << "mov eax, [ebp+8]" << endl;
    cout << "sub [ebp-20], eax" << endl;
    cout << "mov eax, [ebp-20]" << endl;
    cout << "mov [ebp+8], eax" << endl;
    cout << "div_start: mov eax, [ebp+8]" << endl;
    cout << "div_loop: mov edx, 0" << endl;
    cout << "mov ecx, 10" << endl;
    cout << "div ecx" << endl;
    cout << "mov [ebp-20], dl" << endl;
    cout << "add DWORD [ebp-20], 0x30" << endl;
    cout << "mov edx, 0" << endl;
    cout << "mov dl, [ebp-15]" << endl;
    cout << "not edx" << endl;
    cout << "add edx, 1" << endl;
    cout << "mov ecx, 0" << endl;
    cout << "mov cl, [ebp-20]" << endl;
    cout << "mov ebx, ebp" << endl;
    cout << "sub ebx, 4" << endl;
    cout << "mov [ebx + edx], cl" << endl;
    cout << "inc BYTE [ebp-15]" << endl;
    cout << "cmp eax, 0" << endl;
    cout << "ja div_loop" << endl;
    cout << "cmp BYTE [ebp-14], 0" << endl;
    cout << "je chamada" << endl;
    cout << "treat_neg: mov edx, 0" << endl;
    cout << "mov dl, [ebp-15]" << endl;
    cout << "not edx" << endl;
    cout << "add edx, 1" << endl;
    cout << "mov ecx, 0" << endl;
    cout << "mov cl, '-'" << endl;
    cout << "mov ebx, ebp" << endl;
    cout << "sub ebx, 4" << endl;
    cout << "mov [ebx + edx], cl" << endl;
    cout << "inc BYTE [ebp-15]" << endl;
    cout << "chamada: mov ecx, 0" << endl;
    cout << "mov cl, [ebp-15]" << endl;
    cout << "sub cl, 1" << endl;
    cout << "mov ebx, ebp" << endl;
    cout << "sub ebx, 4" << endl;
    cout << "sub ebx, ecx" << endl;
    cout << "mov ecx, ebx" << endl;
    cout << "mov eax, 0" << endl;
    cout << "mov al, [ebp-15]" << endl;
    cout << "mov edx, eax" << endl;
    cout << "mov ebx, 1" << endl;
    cout << "mov eax, 4" << endl;
    cout << "int 0x80" << endl;
    cout << "pop edx" << endl;
    cout << "pop ecx" << endl;
    cout << "pop ebx" << endl;
    cout << "leave" << endl;
    cout << "ret" << endl;
}
//---------------------------------------
// OUTPUT_C
void instrOUTPUT_C(string label)
{
    cout << "push " << label << endl;
    cout << "call _OUTPUT_C" << endl;
    cout << "add esp, 4" << endl;
}

void functOUTPUT_C()
{
    cout << "_OUTPUT_C:" << endl;
    cout << "enter 0, 0" << endl;
    cout << "push ecx" << endl;
    cout << "mov ecx, [ebp+8]" << endl;
    cout << "mov edx, 1" << endl;
    cout << "mov ebx, 1" << endl;
    cout << "mov eax, 4" << endl;
    cout << "int 0x80" << endl;
    cout << "pop ecx" << endl;
    cout << "leave" << endl;
    cout << "ret" << endl;
}

// OUTPUT_S
void instrOUTPUT_S(string label, string len)
{
    cout << "push " << label << endl;
    cout << "push " << len << endl;
    cout << "call _OUTPUT_S" << endl;
    cout << "add esp, 8" << endl;
}

void functOUTPUT_S()
{
    cout << "_OUTPUT_S:" << endl;
    cout << "enter 0, 0" << endl;
    cout << "push ecx" << endl;
    cout << "mov ecx, [ebp+8]" << endl;
    cout << "mov edx, 1" << endl;
    cout << "mov ebx, 1" << endl;
    cout << "mov eax, 4" << endl;
    cout << "int 0x80" << endl;
    cout << "pop ecx" << endl;
    cout << "leave" << endl;
    cout << "ret" << endl;
}
//----------------------------------------------
// INPUT_C
void instrINPUT_C(string label)
{
    cout << "push " << label << endl;
    cout << "call _INPUT_C" << endl;
    cout << "add esp, 4" << endl;
}

void functINPUT_C()
{
    cout << "_INPUT_C:" << endl;
    cout << "enter 0, 0" << endl;
    cout << "push ecx" << endl;
    cout << "mov ecx, [ebp+8]" << endl;
    cout << "mov edx, 1" << endl;
    cout << "mov ebx, 0" << endl;
    cout << "mov eax, 3" << endl;
    cout << "int 0x80" << endl;
    cout << "pop ecx" << endl;
    cout << "leave" << endl;
    cout << "ret" << endl;
}

// INPUT_S
void instrINPUT_S(string label, string len)
{
    cout << "push " << label << endl;
    cout << "push " << len << endl;
    cout << "call _INPUT_S" << endl;
    cout << "add esp, 8" << endl;
}

void functINPUT_S()
{
    cout << "_INPUT_S:" << endl;
    cout << "enter 0, 0" << endl;
    cout << "push ecx" << endl;
    cout << "mov ecx, [ebp+8]" << endl;
    cout << "mov edx, 1" << endl;
    cout << "mov ebx, 0" << endl;
    cout << "mov eax, 3" << endl;
    cout << "int 0x80" << endl;
    cout << "pop ecx" << endl;
    cout << "leave" << endl;
    cout << "ret" << endl;
}
//-------------------------------------------
// ADD
void instrADD(string label)
{
    cout << "add ecx," << label << endl;
}
// SUB
void instrSUB(string label)
{
    cout << "sub ecx," << label << endl;
}
// MUL
void instrMUL(string label)
{
    cout << "mov eax, " << label << endl;
    cout << "mul ecx" << endl;
    cout << "mov ecx, eax" << endl;
}
// DIV
void instrDIV(string label)
{
    cout << "mov eax, " << label << endl;
    cout << "cbw" << endl;
    cout << "idiv cl" << endl;
    cout << "mov ecx, al" << endl;
}
// LOAD
void instrLOAD(string label)
{
    cout << "mov ecx," << label << endl;
}
// STORE
void instrSTORE(string label)
{
    cout << "mov " << label << ",ecx" << endl;
}
// JMP
void instrJMP(string label)
{
    cout << "jmp " << label << endl;
}
// JMPN
void instrJMPN(string label)
{
    cout << "jmpn " << label << endl;
}
// JMPP
void instrJMPP(string label)
{
    cout << "jmpp " << label << endl;
}
// JMZ
void instrJMPZ(string label)
{
    cout << "jmpz " << label << endl;
}
// COPY
void instrCOPY(string label1, string label2)
{
    cout << "mov ecx," << label2 << endl;
    cout << "mov " << label1 << ",ecx" << endl;
}
// STOP
void instrSTOP(string label)
{
    cout << "mov eax,1" << endl;
    cout << "mov ebx,0" << endl;
    cout << "int 80h" << endl;
}
// CONST
void instrCONST(string line)
{
    smatch var;
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
// SPACE
void instrSPACE(string line)
{
    smatch var;
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

void tradutor()
{
    fstream codigo_base;

    codigo_base.open(, fstream::in);
    saida.open("saida.o");

    Simbolo temp;
    string line, word;
    smatch var;
    vector<string> consts, spaces;

    cout << ".text" << endl;

    while (getline(codigo_base, line))
    {
        if(regex_search(line,var,regex("ADD")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrADD(var[0]);
        }
        else if(regex_search(line,var,regex("SUB")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrSUB(var[0]);
        }
        else if(regex_search(line,var,regex("MUL")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrMUL(var[0]);
        }
        else if(regex_search(line,var,regex("DIV")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrDIV(var[0]);
        }
        else if(regex_search(line,var,regex("JMP")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrJMP(var[0]);
        }
        else if(regex_search(line,var,regex("JMPN")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrJMPN(var[0]);
        }
        else if(regex_search(line,var,regex("JMPP")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrJMPP(var[0]);
        }
        else if(regex_search(line,var,regex("JMPZ")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrJMPZ(var[0]);
        }
        else if(regex_search(line,var,regex("COPY")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+),\\w+$"));
            string str = var[1];
            // regex_search(str,var,regex("(\\w+)"));
            regex_search(line,var,regex("(\\w+$)"));
            instrCOPY(str, var[0]);
        }
        else if(regex_search(line,var,regex("LOAD")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrLOAD(var[0]);
        }
        else if(regex_search(line,var,regex("STORE")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrSTORE(var[0]);
        }
        else if(regex_search(line,var,regex("INPUT")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrINPUT(var[0]);
        }
        else if(regex_search(line,var,regex("OUTPUT")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrOUTPUT(var[0]);
        }
        else if(regex_search(line,var,regex("INPUT_C")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrINPUT_C(var[0]);
        }
        else if(regex_search(line,var,regex("OUTPUT_C")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrOUTPUT_C(var[0]);
        }
        else if(regex_search(line,var,regex("INPUT_S")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+),\\d+$"));
            string str = var[1];
            // regex_search(str,var,regex("(\\w+)"));
            regex_search(line,var,regex("(\\d+$)"));
            instrINPUT_S(str, var[0]);
        }
        else if(regex_search(line,var,regex("OUTPUT_S")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+),\\d+$"));
            string str = var[1];
            // regex_search(str,var,regex("(\\w+)"));
            regex_search(line,var,regex("(\\d+$)"));
            instrOUTPUT_S(str, var[0]);
        }
        else if(regex_search(line,var,regex("STOP")))
        {
            // cout << var[0] << endl;
            regex_search(line,var,regex("(\\w+$)"));
            // cout << '[' << var[0] << ']' << endl;
            instrSTOP(var[0]);
        }
        else if(regex_search(line,var,regex("CONST")))
        {
            consts.push_back(line);
        }
        else if(regex_search(line,var,regex("SPACE")))
        {
            spaces.push_back(line);
        }
    }

    fucntINPUT();
    functOUTPUT();
    functINPUT_C();
    functOUTPUT_C();
    functINPUT_S();
    functOUTPUT_S();

    cout << ".bss" << endl;
    for (int i = 0; i < spaces.size(); i++)
        instrSPACE(spaces[i]);
    
    cout << ".data" << endl;
    for (int i = 0; i < consts.size(); i++)
        instrSPACE(consts[i]);
    codigo_base.close();
    saida.close();
}
