// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 6:
Escreva um algoritmo que calcule e exiba o fatorial de um número informado pelo usuário.
*/

#include <iostream>

using namespace std;

int fatorial(int num) // função recursiva para calcular o fatorial
{
    if (num == 0) // passo-base: 0! = 1 e 1! = 1 (mas dá para calcular 1! no else)
    {
        return 1;
    }
    else
    {
        return num * fatorial(num - 1); // ex: 3! --> 3*fatorial(2) --> 2! --> 2*fatorial(1) --> 2*1 = 2 --> 3*2 = 6
    }
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int number, fat;
    cout << "Digite um número: \n";
    cin >> number;
    fat = fatorial(number); // chamada da função fatorial
    cout << number << "! = " << fat << "\n";
}


