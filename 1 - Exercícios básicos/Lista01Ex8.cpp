// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 8:
Escreva um algoritmo que exiba a sequência de Fibonacci com N números, sendo N um número informado pelo usuário. 
A sequência de Fibonacci começa com 1 e 1 e os números subsequentes são obtidos com a soma dos dois números anteriores:
1, 1, 2, 3, 5, 8, 13, ...
*/

#include <iostream>

using namespace std;

int fibonacci(int N)
{
	if (N == 1 || N == 2)
	{
		return 1; // retorna 1 para N = 1 ou N = 2
	}
	else
	{
		return fibonacci(N - 2) + fibonacci(N - 1); // ex: N = 3 --> fibonacci(1) + fibonacci(2) = 1 + 1 = 2
	}
}

int main()
{
	setlocale(LC_ALL, "pt_BR.UTF-8");
	int N;
	cout << "Digite o valor para N: \n";
	cin >> N;
	int fibo = fibonacci(N);
	cout << "Sequência de Fibonacci com " << N << " números: \n" << fibo;
}