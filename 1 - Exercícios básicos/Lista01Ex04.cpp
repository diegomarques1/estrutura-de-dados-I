// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 4:
Escreva um algoritmo que leia um número e indique se o número é par ou ímpar.
*/

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int number;
    cout << "Digite um número: \n";
    cin >> number;
    if ((number % 2) == 0) // resto da divisão por 2 é igual a 0 --> par
    {
        cout << "O número é par.\n";
    }
    else // resto da divisão por 2 é diferente de 0 (no caso, igual a 1) --> ímpar
    {
        cout << "O número é ímpar.\n";
    }
}


