// GRUPO:
// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include "StaticDeque.h"

//Create()
//Cria e retorna uma fila dupla vazia.
//
//Pré - condição: N / A.
//Pós - condição: Uma nova fila dupla vazia é criada.
StaticDeque Create()
{
	StaticDeque deque =
	{
		0, // front
		0, // rear
		0, // count
		{ 0 } // values
	};

	return deque;
}


//InsertBack(deque, elem)
//Insere o elemento elem no fim da fila dupla deque, se deque não estiver cheia.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: O fim de deque contém o elemento elem OU erro se deque estiver cheia.
bool InsertBack(StaticDeque& deque, char elem)
{
	if (deque.count == Size(deque))
	{
		return false;
	}

	deque.values[deque.rear] = elem;

	deque.rear = (deque.rear + 1) % Size(deque); // Mantém deque.rear no intervalo 0 <= deque.rear < Size(deque).
	
	++deque.count; // deque.count += 1

	return true;
}

//InsertFront(deque, elem)
//Insere o elemento elem no início da fila dupla deque, se deque não estiver cheia.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: O início de deque contém o elemento elem OU erro se deque estiver cheia.
bool InsertFront(StaticDeque& deque, char elem)
{
	if (deque.count == Size(deque))
	{
		return false;
	}

	for (int i = deque.rear - 1; i >= deque.front; --i)
	{
		char temp = deque.values[i + 1];
		deque.values[i + 1] = deque.values[i];
		deque.values[i] = temp;
	}

	deque.values[deque.front] = elem;

	deque.rear = (deque.rear + 1) % Size(deque); // Mantém deque.rear no intervalo 0 <= deque.rear < Size(deque).

	++deque.count; // deque.count += 1

	return true;
}

//RemoveBack(deque) 
//Remove e retorna o último elemento da fila dupla deque, se deque não estiver vazia.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: Remove e retorna o último elemento da deque OU erro se deque estiver vazia.
char RemoveBack(StaticDeque& deque)
{
	if (IsEmpty(deque))
	{
		return '\0';
	}
		
	if (deque.rear == 0)
	{
		deque.rear = (deque.front + deque.count - 1) % Size(deque);
		char valor = deque.values[deque.rear];
		deque.values[deque.rear] = '\0';
		--deque.count; // deque.count -= 1
		return valor;
	}
	else
	{
		char valor = deque.values[deque.rear - 1];
		deque.values[deque.rear - 1] = '\0';
		--deque.count; // deque.count -= 1
		deque.rear = (deque.front + deque.count) % Size(deque);
		return valor;
	}
}

//RemoveFront(deque)
//Remove e retorna o primeiro elemento da fila dupla deque, se deque não estiver vazia.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: Remove e retorna o primeiro elemento da deque OU erro se deque estiver vazia.
char RemoveFront(StaticDeque& deque)
{
	if (IsEmpty(deque))
	{
		return '\0';
	}

	char value = deque.values[deque.front];
	deque.values[deque.front] = '\0';

	deque.front = (deque.front + 1) % Size(deque); // Mantém deque.front no intervalo 0 <= deque.front < Size(deque).

	--deque.count; // deque.count -= 1

	return value;
}

//Front(deque) 
//Retorna uma referência do elemento que está no começo da fila dupla (mas não o remove), se deque não estiver vazia.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: Retorna o primeiro elemento da deque sem removê - lo OU erro se deque estiver vazia.
char Front(const StaticDeque& deque)
{
	return IsEmpty(deque) ? '\0' : deque.values[deque.front]; // operador ternário ?: --> <condição> ? true : false;
}

//Back(deque) 
//Retorna uma referência do elemento que está no fim da fila dupla (mas não o remove), se deque não estiver vazia.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: Retorna o último elemento da deque sem removê - lo OU erro se deque estiver vazia.
char Back(const StaticDeque& deque)
{
	return IsEmpty(deque) ? '\0' : deque.values[(deque.front + (deque.count - 1)) % Size(deque)];
}

//Size(deque) 
//Retorna a capacidade da fila dupla.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: N / A.
int Size(const StaticDeque& deque)
{
	return sizeof(deque.values) / sizeof(deque.values[0]); // return STATIC_DEQUE_CAPACITY;
}

//Count(deque) 
//Retorna a quantidade de elementos na fila dupla.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: N / A.
int Count(const StaticDeque& deque)
{
	return deque.count;
}

//IsEmpty(deque) 
//Retorna true se a fila dupla estiver vazia ou false, caso contrário.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: N / A.
bool IsEmpty(const StaticDeque& deque)
{
	return deque.count == 0;
}

//Clear(deque) 
//Esvazia a fila dupla(remove todos os elementos da fila).
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: A fila dupla deque está vazia.
bool Clear(StaticDeque& deque)
{
	while (!IsEmpty(deque))
	{
		RemoveFront(deque);
	}

	return IsEmpty(deque);
}

