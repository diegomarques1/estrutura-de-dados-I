// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 7:
Escreva um algoritmo que leia 10 números inteiros e, após a leitura dos números, informe qual é o maior e qual é o menor.
*/

#include <iostream>

using namespace std;

int maxNumber(int v[10]) // função que retorna o maior valor do vetor de 10 inteiros
{
    int maximum = v[0];
    for (int i = 1; i < 10; ++i)
    {
        if (v[i] > maximum) // se tem algum valor maior que v[0], ele se torna maximum
        {
            maximum = v[i];
        }
    }
    return maximum;
}

int minNumber(int v[10]) // função que retorna o menor valor do vetor de 10 inteiros
{
    int minimum = v[0];
    for (int i = 1; i < 10; ++i)
    {
        if (v[i] < minimum) // se tem algum valor menor que v[0], ele se torna minimum
        {
            minimum = v[i];
        }
    }
    return minimum;
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int vetor[10];
    for (int i = 0; i < 10; ++i)
    {
        cout << "Digite o número " << i + 1 << ": \n";
        cin >> vetor[i];
    }
    int max = maxNumber(vetor);
    int min = minNumber(vetor);
    cout << "Maior número do vetor: " << max << "\n";
    cout << "Menor número do vetor: " << min << "\n";
}

// Poderia ter utilizado alguma função max ou min, mas não consegui entender muito bem como funcionavam
