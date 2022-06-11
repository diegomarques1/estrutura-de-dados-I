// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 9:
Escreva um algoritmo que leia 10 números inteiros e, em seguida, exiba-os na ordem inversa que foram inseridas pelo usuário.
*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt_BR.UTF-8");
    int vetor[10];
    for (int i = 0; i < 10; ++i)
    {
        cout << "Digite o número " << i + 1 << ": \n"; // preencher o vetor com os 10 inteiros do usuário
        cin >> vetor[i];
    }
    for (int j = 0; j < 5; ++j)
    {
        int temp;
        temp = vetor[j]; // criar variável temporária para armazenar o primeiro valor, e assim por diante até a metade (índice 4)
        vetor[j] = vetor[9 - j]; // trocar o primeiro valor com o último, e assim por diante
        vetor[9-j] = temp; // colocar o primeiro valor na última posição, e assim por diante
    }
    cout << "Vetor na ordem inversa: \n";
    for (int k = 0; k < 10; ++k)
    {
        cout << vetor[k] << " "; // printar o vetor em uma linha
    }
    
}
