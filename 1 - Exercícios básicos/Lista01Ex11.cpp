// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 11:
Escreva uma função MulViaAdd() que recebe dois números como parâmetros.
O primeiro parâmetro pode ser um número real e o segundo parâmetro deve ser um número inteiro.
A função deve retornar a multiplicação entre os parâmetros, porém, a multiplicação deve ser feita usando apenas a operação de adição.
*/

#include <iostream>

using namespace std;

float MulViaAdd(float n1, int n2)
{
	float finalAdd = 0;
	for (int qtde = 0; qtde < n2; ++qtde)
	{
		finalAdd += n1; // multiplicação é somar um fator em uma quantidade de vezes de acordo com o outro fator
	}
	return finalAdd;
}

int main()
{
	setlocale(LC_ALL, "pt_BR.UTF-8");
	float parameter1;
	int parameter2;
	cout << "Primeiro parâmetro: \n";
	cin >> parameter1;
	cout << "Segundo parâmetro: \n";
	cin >> parameter2;
	float mult = MulViaAdd(parameter1, parameter2);
	cout << "Multiplicação = " << parameter1 << " x " << parameter2 << " = " << mult;
}
