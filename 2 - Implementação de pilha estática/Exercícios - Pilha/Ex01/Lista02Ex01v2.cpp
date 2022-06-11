// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 1:
Escreva um programa que leia uma string e indique se o texto informado é ou não é um palíndromo.
Seu programa deve usar uma pilha para auxiliar na verificação do palíndromo.
Por exemplo, “Mussum” e “A sacada da casa” são palíndromos, mas “Bolton” e “Hello World” não são.
Considere a string vazia (“”) como palíndromo.

Dica: Assumindo uma variável string str = "Hello World";
Você pode incluir o #include <string>
E usar o código str.erase(remove(str.begin(), str.end(), ' '), str.end());
Para remover espaços em branco da string (repare que str é o nome da variável).
*/

#include <iostream>
#include <string>
#include "stack1.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    cout << "Exercício 01 - Lista de exercícios 02\n";
    string str;
    cout << "Digite uma string de até 100 caracteres: \n";
    getline(cin, str);
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); // considerando que ele não irá digitar caracteres especiais ou vírgula
    int length = str.length();
    StaticStack stack = Create();
    for (int i = 0; i < (length / 2); ++i) // Preenchimento da pilha
    {
        Push(stack, toupper(str[i]));
        if (toupper(str[i]) == toupper(str[length - 1 - i])) // Compara o 1º com o último elemento da string
        {
            Pop(stack);
        }
    }
    if (IsEmpty(stack))
    {
        cout << "A string digitada é um palíndromo.";
    }
    else
    {
        cout << "A string digitada não é um palíndromo.";
    }
    // cout << "\n" << "VERIFICAÇÃO: \n";
    // cout << "Tamanho: " << (length / 2) << "\n";
    // cout << "Pilha: " << stack.values;    
}


