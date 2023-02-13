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


int main(int argc, char const *argv[])
{
    fstream codigo_base;
    codigo_base.open("teste.asm", fstream::in);
    string line, word;
    smatch var;

    while (getline(codigo_base, line))
    {
        istringstream iss(line);
        // cout << line << endl;

        // cout << word << " " << (int)regex_match(word, regex("ADD")) << endl;

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
        // else if(regex_search(line,var,regex("INPUT")))
        // {
        //     // cout << var[0] << endl;
        //     regex_search(line,var,regex("(\\w+$)"));
        //     // cout << '[' << var[0] << ']' << endl;
        //     instrINPUT(var[0]);
        // }
        // else if(regex_search(line,var,regex("OUTPUT")))
        // {
        //     // cout << var[0] << endl;
        //     regex_search(line,var,regex("(\\w+$)"));
        //     // cout << '[' << var[0] << ']' << endl;
        //     instrOUTPUT(var[0]);
        // }
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
    }

    return 0;
}
