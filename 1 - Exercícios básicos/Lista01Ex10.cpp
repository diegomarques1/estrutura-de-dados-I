// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 10:
Escreva um algoritmo que usa um vetor para armazenar 6 números inteiros informados pelo usuário. 
Em seguida, ordene os elementos do vetor em ordem crescente. 
Por exemplo, caso o vetor contenha os números { 7, 3, 10, 5, 2, 6 } (nessa ordem),
ao final do código o vetor deve armazenar { 2, 3, 5, 6, 7, 10 } (números em ordem crescente).
*/

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int vet[6];
    for (int number = 0; number < 6; ++number) // armazenando os valores do usuário em um vetor
    {
        cout << "Digite o " << number + 1 << "º número: \n";
        cin >> vet[number];
    }
    for (int i = 0; i < 6; ++i) // for mais externo para repetir o for interno para cada posição
    {
        for (int j = 0; j < 5; ++j) // for mais interno para comparar os dois valores subsequentes
        {
            if (vet[j] > vet[j + 1]) // se o número é maior que o subsequente, trocam de lugar por meio de variável temporária
            {
                int temp;
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
    cout << "Vetor na ordem crescente: \n";
    for (int k = 0; k < 6; ++k) // imprimir os valores do vetor
    {
        cout << vet[k] << " ";
    }
}