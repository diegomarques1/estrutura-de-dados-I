// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 14:
Escreva uma função VowelsCount() que recebe uma string como parâmetro e retorna a quantidade de vogais encontradas na string. 
Considere que a string é um vetor de caracteres e use o [] para acessar cada caractere (elemento do vetor).
*/

#include <iostream>
#include <string>

using namespace std;

int VowelsCount(string str)
{
    int counter = 0;
    for (char c : str)
    {
        if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u')
        { // não usei o toupper porque não estava funcionando para converter uma frase inteira com o getline()
            counter += 1;
        }
    }
    return counter;
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    string charVet;
    cout << "String: ";
    getline(cin, charVet);
    int vowels = VowelsCount(charVet);
    cout << "Quantidade de vogais na string: " << vowels;
}


