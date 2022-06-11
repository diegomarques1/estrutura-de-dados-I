#include "StaticQueue.h"

//Create()
//Cria e retorna uma fila vazia.
//
//Pré - condição: N / A.
//Pós - condição : Uma nova fila vazia é criada.
StaticQueue Create()
{
	StaticQueue queue =
	{
		0, // front
		0, // rear
		0, // count
		{ 0 } // values
	};

	return queue;
}

//Enqueue(queue, elem)
//Insere o elemento elem no fim da fila queue, se a fila não estiver cheia.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : O final da fila contém o elemento elem OU erro se a fila estiver cheia.
bool Enqueue(StaticQueue& queue, char elem)
{
	if (queue.count == Size(queue))
	{
		return false;
	}

	queue.values[queue.rear] = elem;
	
	queue.rear = (queue.rear + 1) % Size(queue); // Mantém queue.rear no intervalo 0 <= queue.rear < Size(queue).
	// A linha acima equivale à:
	// ++queue.rear;
	// if (queue.rear == Size(queue))
	// {
	//	queue.rear = 0;
	// }

	++queue.count; // queue.count += 1

	return true;
}

//Dequeue(queue)
//Remove e retorna o primeiro elemento da fila queue, se a fila não estiver vazia.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : Remove e retorna o primeiro elemento da fila OU erro se a fila estiver vazia.
char Dequeue(StaticQueue& queue)
{
	if (IsEmpty(queue))
	{
		return '\0';
	}

	char value = queue.values[queue.front];
	queue.values[queue.front] = '\0';

	queue.front = (queue.front + 1) % Size(queue); // Mantém queue.front no intervalo 0 <= queue.front < Size(queue).
	// A linha acima equivale à:
	// ++queue.front;
	// if (queue.front == Size(queue))
	// {
	// 	queue.front = 0;
	// }

	--queue.count; // queue.count -= 1

	return value;
}

//Front(queue)
//Retorna uma referência do elemento que está no começo da fila(mas não o remove), se a fila não estiver vazia.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : Retorna o primeiro elemento da fila sem removê - lo OU erro se a fila estiver vazia.
char Front(const StaticQueue& queue)
{
	// operador ternário ?: --> <condição> ? true : false;
	return IsEmpty(queue) ? '\0' : queue.values[queue.front];
}

//Size(queue)
//Retorna a capacidade da fila.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : N / A.
int Size(const StaticQueue& queue)
{
	return sizeof(queue.values) / sizeof(queue.values[0]); // return STATIC_QUEUE_CAPACITY;
}

//Count(queue)
//Retorna a quantidade de elementos na fila.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : N / A.
int Count(const StaticQueue& queue)
{
	return queue.count;
}

//IsEmpty(queue)
//Retorna true se a fila estiver vazia ou falso, caso contrário.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : N / A.
bool IsEmpty(const StaticQueue& queue)
{
	return queue.count == 0;
}

//Clear(queue)
//Esvazia a fila(remove todos os elementos da fila).
//
//Pré - condição: A fila queue é válida.
//Pós - condição : A fila queue está vazia.
bool Clear(StaticQueue& queue)
{
	while (!IsEmpty(queue))
	{
		Dequeue(queue);
	}

	return IsEmpty(queue);
}

