#include <iostream>
#include "StaticStack.h"

using namespace std;

int main()
{
	StaticStack stack = Create();
	cout << "Pilha vazia? " << IsEmpty(stack) << '\n';

	Push(stack, 'A');
	cout << "Pilha vazia? " << IsEmpty(stack) << '\n';
	cout << "Topo da pilha: " << Top(stack) << '\n';

	Push(stack, 'B');
	cout << "Topo da pilha: " << Top(stack) << '\n';

	Push(stack, 'C');
	cout << "Topo da pilha: " << Top(stack) << '\n';

	char temp = Pop(stack);
	cout << "Retorno do pop: " << temp << '\n';

	cout << "Topo da pilha: " << Top(stack) << '\n';

	bool empty = Clear(stack);
	cout << "Limpou a pilha? " << empty << '\n';

	cout << "Capacidade da pilha: " << Size(stack) << '\n';
	cout << "Elementos empilhados: " << Count(stack) << '\n';
	cout << "Topo da pilha: " << Top(stack) << '\n';
	cout << "Pilha vazia? " << IsEmpty(stack) << '\n';

	bool success = false;
	for (int i = 0; i < STATIC_STACK_CAPACITY + 1; ++i)
	{
		success = Push(stack, 65 + i);
		if (success)
		{
			cout << Top(stack) << '\n';
		}
		else
		{
			cout << "Pilha cheia!\n";
		}
	}

	// Imprime o vetor da pilha.
	for (char c : stack.values)
		cout << c << ' ';
}

