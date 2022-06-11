// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 1:
Escreva um algoritmo que leia dois números informados pelo usuário. 
Cada número deve ser salvo em variáveis distintas, por exemplo, valor1 e valor2.
Após ler os dois números, o algoritmo deve trocar o conteúdo das variáveis.
Exemplo: valor1 armazena o valor 30 e valor2 armazena o valor 50. 
Após o algoritmo ser executado, a variável valor1 deve armazenar o valor 50 e a variável valor2 deve armazenar o valor 30.
*/

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8"); // no meu computador, precisei colocar o .UTF-8 para os acentos funcionarem
    int valor1, valor2;
    cout << "Digite o primeiro valor: \n";
    cin >> valor1;
    cout << "Digite o segundo valor: \n";
    cin >> valor2;
    int temp; // variável temporária
    temp = valor1;
    valor1 = valor2;
    valor2 = temp;
    cout << "Verificação dos valores trocados - " << "Valor1 = " << valor1 << " " << "Valor2 = " << valor2 << "\n";
}
