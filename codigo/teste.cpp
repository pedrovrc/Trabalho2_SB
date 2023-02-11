#include <bits/stdc++.h>
using namespace std;

// INPUT
void instrINPUT(string label, int size)
{

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
void instrOUTPUT_S(string label, int len)
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
void instrINPUT_S(string label, int len)
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
// MUL
void instrMUL(string label)
{
    cout << "mov eax, " << label << endl;
    cout << "mul ecx" << endl;
    cout << "mov ecx, eax" << endl;
}
// DIV
void instrMUL(string label)
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
// STOP
void instrSTOP(string label)
{
    cout << "mov eax,1" << endl;
    cout << "mov ebx,0" << endl;
    cout << "int 80h" << endl;
}


int main(int argc, char const *argv[])
{
    

    return 0;
}
