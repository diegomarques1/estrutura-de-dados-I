// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 13:
Escreva uma função Max() que recebe dois parâmetros numéricos e retorna o maior valor entre eles.
*/

#include <iostream>

using namespace std;

float Max(float n1, float n2) // função que retorna o maior valor entre dois parâmetros
{
    if (n1 > n2)
    {
        return n1;
    }
    else // n1 <= n2
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
    float maximum = Max(parameter1, parameter2);
    cout << "O maior valor entre eles é: " << maximum;
}


