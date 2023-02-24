#include <fstream>
#include <iostream>
#include "tradutor.h"
using namespace std;

// CONSIDERA-SE ECX COMO ACUMULADOR UNICO

ofstream saida;

// INPUT
void instrINPUT(string label)
{
    
}
void functINPUT()
{
    
}
// OUTPUT
void instrOUTPUT(string label) {
    saida << "push " << label << endl;
    saida << "call _OUTPUT" << endl;
    saida << "add esp,4" << endl;
}

void functOUTPUT() {
    saida << "_OUTPUT:" << endl;
    saida << "enter 20, 0" << endl;
    saida << "push ebx" << endl;
    saida << "push ecx" << endl;
    saida << "push edx" << endl;
    saida << "mov BYTE [ebp-15], 0" << endl;
    saida << "cmp DWORD [ebp+8], 0" << endl;
    saida << "jl negativo" << endl;
    saida << "mov BYTE [ebp-14], 0" << endl;
    saida << "jmp div_start" << endl;
    saida << "negativo: mov BYTE [ebp-14], '-'" << endl;
    saida << "mov DWORD [ebp-20], 0" << endl;
    saida << "mov eax, [ebp+8]" << endl;
    saida << "sub [ebp-20], eax" << endl;
    saida << "mov eax, [ebp-20]" << endl;
    saida << "mov [ebp+8], eax" << endl;
    saida << "div_start: mov eax, [ebp+8]" << endl;
    saida << "div_loop: mov edx, 0" << endl;
    saida << "mov ecx, 10" << endl;
    saida << "div ecx" << endl;
    saida << "mov [ebp-20], dl" << endl;
    saida << "add DWORD [ebp-20], 0x30" << endl;
    saida << "mov edx, 0" << endl;
    saida << "mov dl, [ebp-15]" << endl;
    saida << "not edx" << endl;
    saida << "add edx, 1" << endl;
    saida << "mov ecx, 0" << endl;
    saida << "mov cl, [ebp-20]" << endl;
    saida << "mov ebx, ebp" << endl;
    saida << "sub ebx, 4" << endl;
    saida << "mov [ebx + edx], cl" << endl;
    saida << "inc BYTE [ebp-15]" << endl;
    saida << "cmp eax, 0" << endl;
    saida << "ja div_loop" << endl;
    saida << "cmp BYTE [ebp-14], 0" << endl;
    saida << "je chamada" << endl;
    saida << "treat_neg: mov edx, 0" << endl;
    saida << "mov dl, [ebp-15]" << endl;
    saida << "not edx" << endl;
    saida << "add edx, 1" << endl;
    saida << "mov ecx, 0" << endl;
    saida << "mov cl, '-'" << endl;
    saida << "mov ebx, ebp" << endl;
    saida << "sub ebx, 4" << endl;
    saida << "mov [ebx + edx], cl" << endl;
    saida << "inc BYTE [ebp-15]" << endl;
    saida << "chamada: mov ecx, 0" << endl;
    saida << "mov cl, [ebp-15]" << endl;
    saida << "sub cl, 1" << endl;
    saida << "mov ebx, ebp" << endl;
    saida << "sub ebx, 4" << endl;
    saida << "sub ebx, ecx" << endl;
    saida << "mov ecx, ebx" << endl;
    saida << "mov eax, 0" << endl;
    saida << "mov al, [ebp-15]" << endl;
    saida << "mov edx, eax" << endl;
    saida << "mov ebx, 1" << endl;
    saida << "mov eax, 4" << endl;
    saida << "int 0x80" << endl;
    saida << "pop edx" << endl;
    saida << "pop ecx" << endl;
    saida << "pop ebx" << endl;
    saida << "leave" << endl;
    saida << "ret" << endl;
}
//---------------------------------------
// OUTPUT_C
void instrOUTPUT_C(string label)
{
    saida << "push " << label << endl;
    saida << "call _OUTPUT_C" << endl;
    saida << "add esp, 4" << endl;
}

void functOUTPUT_C()
{
    saida << "_OUTPUT_C:" << endl;
    saida << "enter 0, 0" << endl;
    saida << "push ecx" << endl;
    saida << "mov ecx, [ebp+8]" << endl;
    saida << "mov edx, 1" << endl;
    saida << "mov ebx, 1" << endl;
    saida << "mov eax, 4" << endl;
    saida << "int 0x80" << endl;
    saida << "pop ecx" << endl;
    saida << "leave" << endl;
    saida << "ret" << endl;
}

// OUTPUT_S
void instrOUTPUT_S(string label, string len)
{
    saida << "push " << label << endl;
    saida << "push " << len << endl;
    saida << "call _OUTPUT_S" << endl;
    saida << "add esp, 8" << endl;
}

void functOUTPUT_S()
{
    saida << "_OUTPUT_S:" << endl;
    saida << "enter 0, 0" << endl;
    saida << "push ecx" << endl;
    saida << "mov ecx, [ebp+8]" << endl;
    saida << "mov edx, 1" << endl;
    saida << "mov ebx, 1" << endl;
    saida << "mov eax, 4" << endl;
    saida << "int 0x80" << endl;
    saida << "pop ecx" << endl;
    saida << "leave" << endl;
    saida << "ret" << endl;
}
//----------------------------------------------
// INPUT_C
void instrINPUT_C(string label)
{
    saida << "push " << label << endl;
    saida << "call _INPUT_C" << endl;
    saida << "add esp, 4" << endl;
}

void functINPUT_C()
{
    saida << "_INPUT_C:" << endl;
    saida << "enter 0, 0" << endl;
    saida << "push ecx" << endl;
    saida << "mov ecx, [ebp+8]" << endl;
    saida << "mov edx, 1" << endl;
    saida << "mov ebx, 0" << endl;
    saida << "mov eax, 3" << endl;
    saida << "int 0x80" << endl;
    saida << "pop ecx" << endl;
    saida << "leave" << endl;
    saida << "ret" << endl;
}

// INPUT_S
void instrINPUT_S(string label, string len)
{
    saida << "push " << label << endl;
    saida << "push " << len << endl;
    saida << "call _INPUT_S" << endl;
    saida << "add esp, 8" << endl;
}

void functINPUT_S()
{
    saida << "_INPUT_S:" << endl;
    saida << "enter 0, 0" << endl;
    saida << "push ecx" << endl;
    saida << "mov ecx, [ebp+8]" << endl;
    saida << "mov edx, 1" << endl;
    saida << "mov ebx, 0" << endl;
    saida << "mov eax, 3" << endl;
    saida << "int 0x80" << endl;
    saida << "pop ecx" << endl;
    saida << "leave" << endl;
    saida << "ret" << endl;
}
//-------------------------------------------
// ADD
void instrADD(string label)
{
    saida << "add ecx," << label << endl;
}
// SUB
void instrSUB(string label)
{
    saida << "sub ecx," << label << endl;
}
// MUL
void instrMUL(string label)
{
    saida << "mov eax, ecx" << endl;
    saida << "mov ecx, " << label << endl;
    saida << "imul ecx" << endl;
    saida << "mov ecx, eax" << endl;
}
// DIV
void instrDIV(string label)
{
    saida << "mov ax, cx" << endl;
    saida << "mov cx, " << label << endl;
    saida << "cbw" << endl;
    saida << "idiv cx" << endl;
    saida << "mov ecx, 0" << endl;
    saida << "mov cx, ax" << endl;
}
// LOAD
void instrLOAD(string label)
{
    saida << "mov ecx, [" << label << "]" << endl;
}
// STORE
void instrSTORE(string label)
{
    saida << "mov [" << label << "] ,ecx" << endl;
}
// JMP
void instrJMP(string label)
{
    saida << "jmp " << label << endl;
}
// JMPN
void instrJMPN(string label)
{
    saida << "cmp ecx, 0" << endl;
    saida << "jl " << label << endl;
}
// JMPP
void instrJMPP(string label)
{
    saida << "cmp ecx, 0" << endl;
    saida << "jg " << label << endl;
}
// JMZ
void instrJMPZ(string label)
{
    saida << "cmp ecx, 0" << endl;
    saida << "je " << label << endl;
}
// COPY
void instrCOPY(string label1, string label2)
{
    saida << "mov ecx, [" << label2 << "]" << endl;
    saida << "mov [" << label1 << "] ,ecx" << endl;
}
// STOP
void instrSTOP(string label)
{
    saida << "mov eax,1" << endl;
    saida << "mov ebx,0" << endl;
    saida << "int 80h" << endl;
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
        saida << label << " dd " << arg << endl;
    }
    else
    {
        label = regex_replace(line, regex(":.+$"), "$2");
        arg = regex_replace(line, regex(".+ "), "$2");
        saida << label << ": db " << arg << endl;
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
                size = regex_replace(line, regex("\\D+"), "$2");
                saida << label << ": resd " << size << endl;
    }
    else
    {
        string label;
        label = regex_replace(line, regex(":.*"), "$2");
        saida << label << ": resd 1" << endl;
    }
}

void tradutor(string nome_arquivo)
{
    nome_arquivo.append(".s");

    fstream codigo_base;

    codigo_base.open("preproc.pre", fstream::in);
    saida.open(nome_arquivo, fstream::out);

    Simbolo temp;
    string line, word;
    smatch var;
    vector<string> consts, spaces;

    saida << "section .text" << endl;
    saida << "global _start" << endl;
    saida << "_start:" << endl;

    while (getline(codigo_base, line))
    {
        if(regex_search(line,var,regex(".+:")) && !regex_search(line,var,regex("SPACE")) && !regex_search(line,var,regex("CONST")))
        {
            string label;
            label = regex_search(line,var,regex("(.+:)"));
            saida<<var[1]<<endl;
        }

        if(regex_search(line,var,regex("ADD")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrADD(var[0]);
        }
        else if(regex_search(line,var,regex("SUB")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrSUB(var[0]);
        }
        else if(regex_search(line,var,regex("MUL")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrMUL(var[0]);
        }
        else if(regex_search(line,var,regex("DIV")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrDIV(var[0]);
        }
        else if(regex_search(line,var,regex("JMPN")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrJMPN(var[0]);
        }
        else if(regex_search(line,var,regex("JMPP")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrJMPP(var[0]);
        }
        else if(regex_search(line,var,regex("JMPZ")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrJMPZ(var[0]);
        }
        else if(regex_search(line,var,regex("JMP")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrJMP(var[0]);
        }
        else if(regex_search(line,var,regex("COPY")))
        {
            regex_search(line,var,regex("(\\w+),\\w+$"));
            string str = var[1];
            // regex_search(str,var,regex("(\\w+)"));
            regex_search(line,var,regex("(\\w+$)"));
            instrCOPY(str, var[0]);
        }
        else if(regex_search(line,var,regex("LOAD")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrLOAD(var[0]);
        }
        else if(regex_search(line,var,regex("STORE")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrSTORE(var[0]);
        }
        else if(regex_search(line,var,regex("INPUT_C")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrINPUT_C(var[0]);
        }
        else if(regex_search(line,var,regex("OUTPUT_C")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrOUTPUT_C(var[0]);
        }
        else if(regex_search(line,var,regex("INPUT_S")))
        {
            regex_search(line,var,regex("(\\w+),\\d+$"));
            string str = var[1];
            regex_search(line,var,regex("(\\d+$)"));
            instrINPUT_S(str, var[0]);
        }
        else if(regex_search(line,var,regex("OUTPUT_S")))
        {
            regex_search(line,var,regex("(\\w+),\\d+$"));
            string str = var[1];
            regex_search(line,var,regex("(\\d+$)"));
            instrOUTPUT_S(str, var[0]);
        }
        else if(regex_search(line,var,regex("INPUT")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrINPUT(var[0]);
        }
        else if(regex_search(line,var,regex("OUTPUT")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrOUTPUT(var[0]);
        }
        else if(regex_search(line,var,regex("STOP")))
        {
            regex_search(line,var,regex("(\\w+$)"));
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

    functINPUT();
    functOUTPUT();
    functINPUT_C();
    functOUTPUT_C();
    functINPUT_S();
    functOUTPUT_S();

    saida << "section .bss" << endl;
    for (int i = 0; i < int(spaces.size()); i++)
        instrSPACE(spaces[i]);
    
    saida << "section .data" << endl;
    for (int i = 0; i < int(consts.size()); i++)
        instrCONST(consts[i]);
    codigo_base.close();
    saida.close();
}
