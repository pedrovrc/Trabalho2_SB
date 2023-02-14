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
    cout << "push " << label << endl;
    saida << "push " << label << endl;
    cout << "call _OUTPUT" << endl;
    saida << "call _OUTPUT" << endl;
    cout << "add esp,4" << endl;
    saida << "add esp,4" << endl;
}

void functOUTPUT() {
    cout << "_OUTPUT:" << endl;
    saida << "_OUTPUT:" << endl;
    cout << "enter 20, 0" << endl;
    saida << "enter 20, 0" << endl;
    cout << "push ebx" << endl;
    saida << "push ebx" << endl;
    cout << "push ecx" << endl;
    saida << "push ecx" << endl;
    cout << "push edx" << endl;
    saida << "push edx" << endl;
    cout << "mov BYTE [ebp-15], 0" << endl;
    saida << "mov BYTE [ebp-15], 0" << endl;
    cout << "cmp DWORD [ebp+8], 0" << endl;
    saida << "cmp DWORD [ebp+8], 0" << endl;
    cout << "jl negativo" << endl;
    saida << "jl negativo" << endl;
    cout << "mov BYTE [ebp-14], 0" << endl;
    saida << "mov BYTE [ebp-14], 0" << endl;
    cout << "jmp div_start" << endl;
    saida << "jmp div_start" << endl;
    cout << "negativo: mov BYTE [ebp-14], '-'" << endl;
    saida << "negativo: mov BYTE [ebp-14], '-'" << endl;
    cout << "mov DWORD [ebp-20], 0" << endl;
    saida << "mov DWORD [ebp-20], 0" << endl;
    cout << "mov eax, [ebp+8]" << endl;
    saida << "mov eax, [ebp+8]" << endl;
    cout << "sub [ebp-20], eax" << endl;
    saida << "sub [ebp-20], eax" << endl;
    cout << "mov eax, [ebp-20]" << endl;
    saida << "mov eax, [ebp-20]" << endl;
    cout << "mov [ebp+8], eax" << endl;
    saida << "mov [ebp+8], eax" << endl;
    cout << "div_start: mov eax, [ebp+8]" << endl;
    saida << "div_start: mov eax, [ebp+8]" << endl;
    cout << "div_loop: mov edx, 0" << endl;
    saida << "div_loop: mov edx, 0" << endl;
    cout << "mov ecx, 10" << endl;
    saida << "mov ecx, 10" << endl;
    cout << "div ecx" << endl;
    saida << "div ecx" << endl;
    cout << "mov [ebp-20], dl" << endl;
    saida << "mov [ebp-20], dl" << endl;
    cout << "add DWORD [ebp-20], 0x30" << endl;
    saida << "add DWORD [ebp-20], 0x30" << endl;
    cout << "mov edx, 0" << endl;
    saida << "mov edx, 0" << endl;
    cout << "mov dl, [ebp-15]" << endl;
    saida << "mov dl, [ebp-15]" << endl;
    cout << "not edx" << endl;
    saida << "not edx" << endl;
    cout << "add edx, 1" << endl;
    saida << "add edx, 1" << endl;
    cout << "mov ecx, 0" << endl;
    saida << "mov ecx, 0" << endl;
    cout << "mov cl, [ebp-20]" << endl;
    saida << "mov cl, [ebp-20]" << endl;
    cout << "mov ebx, ebp" << endl;
    saida << "mov ebx, ebp" << endl;
    cout << "sub ebx, 4" << endl;
    saida << "sub ebx, 4" << endl;
    cout << "mov [ebx + edx], cl" << endl;
    saida << "mov [ebx + edx], cl" << endl;
    cout << "inc BYTE [ebp-15]" << endl;
    saida << "inc BYTE [ebp-15]" << endl;
    cout << "cmp eax, 0" << endl;
    saida << "cmp eax, 0" << endl;
    cout << "ja div_loop" << endl;
    saida << "ja div_loop" << endl;
    cout << "cmp BYTE [ebp-14], 0" << endl;
    saida << "cmp BYTE [ebp-14], 0" << endl;
    cout << "je chamada" << endl;
    saida << "je chamada" << endl;
    cout << "treat_neg: mov edx, 0" << endl;
    saida << "treat_neg: mov edx, 0" << endl;
    cout << "mov dl, [ebp-15]" << endl;
    saida << "mov dl, [ebp-15]" << endl;
    cout << "not edx" << endl;
    saida << "not edx" << endl;
    cout << "add edx, 1" << endl;
    saida << "add edx, 1" << endl;
    cout << "mov ecx, 0" << endl;
    saida << "mov ecx, 0" << endl;
    cout << "mov cl, '-'" << endl;
    saida << "mov cl, '-'" << endl;
    cout << "mov ebx, ebp" << endl;
    saida << "mov ebx, ebp" << endl;
    cout << "sub ebx, 4" << endl;
    saida << "sub ebx, 4" << endl;
    cout << "mov [ebx + edx], cl" << endl;
    saida << "mov [ebx + edx], cl" << endl;
    cout << "inc BYTE [ebp-15]" << endl;
    saida << "inc BYTE [ebp-15]" << endl;
    cout << "chamada: mov ecx, 0" << endl;
    saida << "chamada: mov ecx, 0" << endl;
    cout << "mov cl, [ebp-15]" << endl;
    saida << "mov cl, [ebp-15]" << endl;
    cout << "sub cl, 1" << endl;
    saida << "sub cl, 1" << endl;
    cout << "mov ebx, ebp" << endl;
    saida << "mov ebx, ebp" << endl;
    cout << "sub ebx, 4" << endl;
    saida << "sub ebx, 4" << endl;
    cout << "sub ebx, ecx" << endl;
    saida << "sub ebx, ecx" << endl;
    cout << "mov ecx, ebx" << endl;
    saida << "mov ecx, ebx" << endl;
    cout << "mov eax, 0" << endl;
    saida << "mov eax, 0" << endl;
    cout << "mov al, [ebp-15]" << endl;
    saida << "mov al, [ebp-15]" << endl;
    cout << "mov edx, eax" << endl;
    saida << "mov edx, eax" << endl;
    cout << "mov ebx, 1" << endl;
    saida << "mov ebx, 1" << endl;
    cout << "mov eax, 4" << endl;
    saida << "mov eax, 4" << endl;
    cout << "int 0x80" << endl;
    saida << "int 0x80" << endl;
    cout << "pop edx" << endl;
    saida << "pop edx" << endl;
    cout << "pop ecx" << endl;
    saida << "pop ecx" << endl;
    cout << "pop ebx" << endl;
    saida << "pop ebx" << endl;
    cout << "leave" << endl;
    saida << "leave" << endl;
    cout << "ret" << endl;
    saida << "ret" << endl;
}
//---------------------------------------
// OUTPUT_C
void instrOUTPUT_C(string label)
{
    cout << "push " << label << endl;
    saida << "push " << label << endl;
    cout << "call _OUTPUT_C" << endl;
    saida << "call _OUTPUT_C" << endl;
    cout << "add esp, 4" << endl;
    saida << "add esp, 4" << endl;
}

void functOUTPUT_C()
{
    cout << "_OUTPUT_C:" << endl;
    saida << "_OUTPUT_C:" << endl;
    cout << "enter 0, 0" << endl;
    saida << "enter 0, 0" << endl;
    cout << "push ecx" << endl;
    saida << "push ecx" << endl;
    cout << "mov ecx, [ebp+8]" << endl;
    saida << "mov ecx, [ebp+8]" << endl;
    cout << "mov edx, 1" << endl;
    saida << "mov edx, 1" << endl;
    cout << "mov ebx, 1" << endl;
    saida << "mov ebx, 1" << endl;
    cout << "mov eax, 4" << endl;
    saida << "mov eax, 4" << endl;
    cout << "int 0x80" << endl;
    saida << "int 0x80" << endl;
    cout << "pop ecx" << endl;
    saida << "pop ecx" << endl;
    cout << "leave" << endl;
    saida << "leave" << endl;
    cout << "ret" << endl;
    saida << "ret" << endl;
}

// OUTPUT_S
void instrOUTPUT_S(string label, string len)
{
    cout << "push " << label << endl;
    saida << "push " << label << endl;
    cout << "push " << len << endl;
    saida << "push " << len << endl;
    cout << "call _OUTPUT_S" << endl;
    saida << "call _OUTPUT_S" << endl;
    cout << "add esp, 8" << endl;
    saida << "add esp, 8" << endl;
}

void functOUTPUT_S()
{
    cout << "_OUTPUT_S:" << endl;
    saida << "_OUTPUT_S:" << endl;
    cout << "enter 0, 0" << endl;
    saida << "enter 0, 0" << endl;
    cout << "push ecx" << endl;
    saida << "push ecx" << endl;
    cout << "mov ecx, [ebp+8]" << endl;
    saida << "mov ecx, [ebp+8]" << endl;
    cout << "mov edx, 1" << endl;
    saida << "mov edx, 1" << endl;
    cout << "mov ebx, 1" << endl;
    saida << "mov ebx, 1" << endl;
    cout << "mov eax, 4" << endl;
    saida << "mov eax, 4" << endl;
    cout << "int 0x80" << endl;
    saida << "int 0x80" << endl;
    cout << "pop ecx" << endl;
    saida << "pop ecx" << endl;
    cout << "leave" << endl;
    saida << "leave" << endl;
    cout << "ret" << endl;
    saida << "ret" << endl;
}
//----------------------------------------------
// INPUT_C
void instrINPUT_C(string label)
{
    cout << "push " << label << endl;
    saida << "push " << label << endl;
    cout << "call _INPUT_C" << endl;
    saida << "call _INPUT_C" << endl;
    cout << "add esp, 4" << endl;
    saida << "add esp, 4" << endl;
}

void functINPUT_C()
{
    cout << "_INPUT_C:" << endl;
    saida << "_INPUT_C:" << endl;
    cout << "enter 0, 0" << endl;
    saida << "enter 0, 0" << endl;
    cout << "push ecx" << endl;
    saida << "push ecx" << endl;
    cout << "mov ecx, [ebp+8]" << endl;
    saida << "mov ecx, [ebp+8]" << endl;
    cout << "mov edx, 1" << endl;
    saida << "mov edx, 1" << endl;
    cout << "mov ebx, 0" << endl;
    saida << "mov ebx, 0" << endl;
    cout << "mov eax, 3" << endl;
    saida << "mov eax, 3" << endl;
    cout << "int 0x80" << endl;
    saida << "int 0x80" << endl;
    cout << "pop ecx" << endl;
    saida << "pop ecx" << endl;
    cout << "leave" << endl;
    saida << "leave" << endl;
    cout << "ret" << endl;
    saida << "ret" << endl;
}

// INPUT_S
void instrINPUT_S(string label, string len)
{
    cout << "push " << label << endl;
    saida << "push " << label << endl;
    cout << "push " << len << endl;
    saida << "push " << len << endl;
    cout << "call _INPUT_S" << endl;
    saida << "call _INPUT_S" << endl;
    cout << "add esp, 8" << endl;
    saida << "add esp, 8" << endl;
}

void functINPUT_S()
{
    cout << "_INPUT_S:" << endl;
    saida << "_INPUT_S:" << endl;
    cout << "enter 0, 0" << endl;
    saida << "enter 0, 0" << endl;
    cout << "push ecx" << endl;
    saida << "push ecx" << endl;
    cout << "mov ecx, [ebp+8]" << endl;
    saida << "mov ecx, [ebp+8]" << endl;
    cout << "mov edx, 1" << endl;
    saida << "mov edx, 1" << endl;
    cout << "mov ebx, 0" << endl;
    saida << "mov ebx, 0" << endl;
    cout << "mov eax, 3" << endl;
    saida << "mov eax, 3" << endl;
    cout << "int 0x80" << endl;
    saida << "int 0x80" << endl;
    cout << "pop ecx" << endl;
    saida << "pop ecx" << endl;
    cout << "leave" << endl;
    saida << "leave" << endl;
    cout << "ret" << endl;
    saida << "ret" << endl;
}
//-------------------------------------------
// ADD
void instrADD(string label)
{
    cout << "add ecx," << label << endl;
    saida << "add ecx," << label << endl;
}
// SUB
void instrSUB(string label)
{
    cout << "sub ecx," << label << endl;
    saida << "sub ecx," << label << endl;
}
// MUL
void instrMUL(string label)
{
    cout << "mov eax, ecx" << endl;
    saida << "mov eax, ecx" << endl;
    cout << "mov ecx, " << label << endl;
    saida << "mov ecx, " << label << endl;
    cout << "imul ecx" << endl;
    saida << "imul ecx" << endl;
    cout << "mov ecx, eax" << endl;
    saida << "mov ecx, eax" << endl;
}
// DIV
void instrDIV(string label)
{
    cout << "mov eax, ecx" << endl;
    saida << "mov eax, ecx" << endl;
    cout << "mov edx, 0" << endl;
    saida << "mov edx, 0" << endl;
    cout << "mov ecx, " << label << endl;
    saida << "mov ecx, " << label << endl;
    cout << "cbw" << endl;
    saida << "cbw" << endl;
    cout << "cmp eax, 0" << endl;
    saida << "cmp eax, 0" << endl;
    cout << "jge div" << endl;
    saida << "jge div" << endl;
    cout << "mov edx, 0" << endl;
    saida << "mov edx, 0" << endl;
    cout << "not edx" << endl;
    saida << "not edx" << endl;
    cout << "idiv ecx" << endl;
    saida << "idiv ecx" << endl;
    cout << "mov ecx, eax" << endl;
    saida << "mov ecx, eax" << endl;
}
// LOAD
void instrLOAD(string label)
{
    cout << "mov ecx, [" << label << "]" << endl;
    saida << "mov ecx, [" << label << "]" << endl;
}
// STORE
void instrSTORE(string label)
{
    cout << "mov [" << label << "] ,ecx" << endl;
    saida << "mov [" << label << "] ,ecx" << endl;
}
// JMP
void instrJMP(string label)
{
    cout << "jmp " << label << endl;
    saida << "jmp " << label << endl;
}
// JMPN
void instrJMPN(string label)
{
    cout << "cmp ecx, 0" << endl;
    saida << "cmp ecx, 0" << endl;
    cout << "jl " << label << endl;
    saida << "jl " << label << endl;
}
// JMPP
void instrJMPP(string label)
{
    cout << "cmp ecx, 0" << endl;
    saida << "cmp ecx, 0" << endl;
    cout << "jg " << label << endl;
    saida << "jg " << label << endl;
}
// JMZ
void instrJMPZ(string label)
{
    cout << "cmp ecx, 0" << endl;
    saida << "cmp ecx, 0" << endl;
    cout << "je " << label << endl;
    saida << "je " << label << endl;
}
// COPY
void instrCOPY(string label1, string label2)
{
    cout << "mov ecx, [" << label2 << "]" << endl;
    saida << "mov ecx, [" << label2 << "]" << endl;
    cout << "mov [" << label1 << "] ,ecx" << endl;
    saida << "mov [" << label1 << "] ,ecx" << endl;
}
// STOP
void instrSTOP(string label)
{
    cout << "mov eax,1" << endl;
    saida << "mov eax,1" << endl;
    cout << "mov ebx,0" << endl;
    saida << "mov ebx,0" << endl;
    cout << "int 80h" << endl;
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
        cout << label << " dd " << arg << endl;
        saida << label << " dd " << arg << endl;
    }
    else
    {
        label = regex_replace(line, regex(":.+$"), "$2");
        arg = regex_replace(line, regex(".+ "), "$2");
        cout << label << " db " << arg << endl;
        saida << label << " db " << arg << endl;
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
                saida << label << ": resd " << size << endl;
    }
    else
    {
        string label;
        label = regex_replace(line, regex(":.*"), "$2");
        cout << label << ": resd 1" << endl;
        saida << label << ": resd 1" << endl;
    }
}

void tradutor()
{
    fstream codigo_base;

    codigo_base.open("preproc.pre", fstream::in);
    saida.open("saida.txt", fstream::out);

    Simbolo temp;
    string line, word;
    smatch var;
    vector<string> consts, spaces;

    cout << ".text" << endl;
    saida << ".text" << endl;
    cout << "global _start" << endl;
    cout << "global _start" << endl;
    saida << "_start:" << endl;
    saida << "_start:" << endl;

    while (getline(codigo_base, line))
    {
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
        else if(regex_search(line,var,regex("JMP")))
        {
            regex_search(line,var,regex("(\\w+$)"));
            instrJMP(var[0]);
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

    cout << "section .bss" << endl;
    saida << "section .bss" << endl;
    for (int i = 0; i < spaces.size(); i++)
        instrSPACE(spaces[i]);
    
    cout << "section .data" << endl;
    saida << "section .data" << endl;
    for (int i = 0; i < consts.size(); i++)
        instrCONST(consts[i]);
    codigo_base.close();
    saida.close();
}
