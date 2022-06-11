// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 3:
Escreva um programa que usa pilha para verificar e informar se uma expressão
(string) possui a correspondência e ordem correta dos símbolos (), [], {} e <>.
A expressão deve ser informada pelo usuário.
Por exemplo, os símbolos na string “{ ( [ { < > } ] ) }” estão corretos,
enquanto que na string “{ ( [ { < } > ] ) }” o primeiro } e o > estão na ordem errada.
Alguns exemplos que o programa deve informar OK:
“(Hello([{W}o]r))ld!”
“<html>”
“(a && b) || (c && d)”
E alguns exemplos que o programa deve informar erro de correspondência:
“[x + y)”
“<body”
“( ( [ ] ) ) }”
*/

#include <iostream>
#include <string>
#include "stack3.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    cout << "Exercício 03 - Lista de exercícios 02\n";
    string str;
    cout << "Digite uma expressão: \n";
    getline(cin, str);
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    StaticStack stack = Create();
    int cont = 0;
    for (char c : str) // Preenchimento da pilha
    {
        switch (c)
        {
        case '(':
            Push(stack, c);
            break;
        case ')':
            if (Top(stack) == '(')
            {
                Pop(stack);
            }
            else
            {
                ++cont;
            }
            break;
        case '[':
            Push(stack, c);
            break;
        case ']':
            if (Top(stack) == '[')
            {
                Pop(stack);
            }
            else
            {
                ++cont;
            }
            break;
        case '{':
            Push(stack, c);
            break;
        case '}':
            if (Top(stack) == '{')
            {
                Pop(stack);
            }
            else
            {
                ++cont;
            }
            break;
        case '<':
            Push(stack, c);
            break;
        case '>':
            if (Top(stack) == '<')
            {
                Pop(stack);
            }
            else
            {
                ++cont;
            }
            break;
        }
    }
    // VERIFICAÇÃO:
    // cout << "Pilha: " << stack.values << "\n";
    // cout << "Contador: " << cont << '\n';
    if (IsEmpty(stack) && cont == 0)
    {
        cout << "A expressão está correta.";
    }
    else cout << "Erro de correspondência.";
} 