// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 3:
Escreva um algoritmo que leia uma letra e indique se é uma vogal ou consoante.
*/

// Referência para o comando toupper: http://linguagemc.com.br/ctype-h-toupper-tolower-isalpha-isdigit-em-c/

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    char word;
    cout << "Digite uma letra do alfabeto: \n";
    cin >> word;
    word = toupper(word); // caso o usuário digite em letra minúscula, converte para maiúscula
    if (word == 'A' || word == 'E' || word == 'I' || word == 'O' || word == 'U') // condição para ser vogal
    {
        cout << "A letra é uma vogal.\n";
    }
    else
    {
        cout << "A letra é uma consoante.\n";
    }
}

