// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 12:
Escreva uma função Min() que recebe dois parâmetros numéricos e retorna o menor valor entre eles.
*/

#include <iostream>

using namespace std;

float Min(float n1, float n2) // função para retornar o menor valor entre dois parâmetros
{
    if (n1 < n2)
    {
        return n1;
    }
    else // n1 >= n2
    {
        return n2;
    }
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    float parameter1, parameter2;
    cout << "Primeiro parâmetro: \n";
    cin >> parameter1;
    cout << "Segundo parâmetro: \n";
    cin >> parameter2;
    float minimum = Min(parameter1, parameter2);
    cout << "O menor valor entre eles é: " << minimum;
}


