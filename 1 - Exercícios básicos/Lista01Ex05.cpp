// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 5:
Assumindo a equação de reta 3x + y = 8, escreva um algoritmo que leia os valores para x e y e indique se o ponto (x, y) pertence à reta.
*/

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int x, y; 
    cout << "Digite o valor para a coordenada x: \n";
    cin >> x;
    cout << "Digite o valor para a coordenada y: \n";
    cin >> y;
    int line = (3 * x) + y; // equação da reta
    if (line == 8) // igualdade da reta para verificar o ponto
    {
        cout << "O ponto (" << x << ", " << y << ") " << "pertence à reta.\n";
    }
    else // caso line != 8
    {
        cout << "O ponto (" << x << ", " << y << ") " << "não pertence à reta.\n";
    }
}
