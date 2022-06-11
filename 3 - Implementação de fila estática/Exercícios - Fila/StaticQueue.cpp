// Diego Souza Lima Marques
// TIA: 32039921

#include "StaticQueue.h"
#include <ctime>

Product StartProduct()
{
	Product prod =
	{
		'\0',
		0,
		0,
		0,
		0
	};

	return prod;
}

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
//Pós - condição: O final da fila contém o elemento elem OU erro se a fila estiver cheia.
bool EnqueueA(StaticQueue& queue, Product elem)
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

bool EnqueueB(StaticQueue& queue, Product elem)
{
	if (queue.count == Size(queue))
	{
		return false;
	}

	queue.values[queue.rear] = elem;

	queue.rear = (queue.rear + 1) % Size(queue);

	++queue.count;

	return true;
}

//Dequeue(queue)
//Remove e retorna o primeiro elemento da fila queue, se a fila não estiver vazia.
//
//Pré - condição: A fila queue é válida.
//Pós - condição: Remove e retorna o primeiro elemento da fila OU erro se a fila estiver vazia.
Product DequeueA(StaticQueue& queueA)
{
	if (IsEmpty(queueA))
	{
		return StartProduct();
	}

	Product value = queueA.values[queueA.front];
	queueA.values[queueA.front] = StartProduct();

	queueA.front = (queueA.front + 1) % Size(queueA); // Mantém queue.front no intervalo 0 <= queue.front < Size(queue).

	--queueA.count; // queue.count -= 1

	return value;
}

Product DequeueB(StaticQueue& queueB)
{
	if (IsEmpty(queueB))
	{
		return StartProduct();
	}

	Product value = queueB.values[queueB.front];
	queueB.values[queueB.front] = StartProduct();

	queueB.front = (queueB.front + 1) % Size(queueB);

	--queueB.count;

	return value;
}

Product DequeueAny(StaticQueue& queueA, StaticQueue& queueB)
{
	if (IsEmpty(queueA) && IsEmpty(queueB))
	{
		return StartProduct();
	}

	if (IsEmpty(queueA))
	{

		return DequeueB(queueB);
	}

	if (IsEmpty(queueB))
	{
		return DequeueA(queueA);
	}

	else
	{
		if (Front(queueA).date > Front(queueB).date)
		{
			return DequeueB(queueB);
		}
		else return DequeueA(queueA);
	}
}

//Front(queue)
//Retorna uma referência do elemento que está no começo da fila(mas não o remove), se a fila não estiver vazia.
//
//Pré - condição: A fila queue é válida.
//Pós - condição: Retorna o primeiro elemento da fila sem removê - lo OU erro se a fila estiver vazia.
Product Front(const StaticQueue& queue)
{
	// operador ternário ?: --> <condição> ? true : false;
	return IsEmpty(queue) ? StartProduct() : queue.values[queue.front];
}

//Size(queue)
//Retorna a capacidade da fila.
//
//Pré - condição: A fila queue é válida.
//Pós - condição: N / A.
int Size(const StaticQueue& queue)
{
	return sizeof(queue.values) / sizeof(queue.values[0]); // return STATIC_QUEUE_CAPACITY;
}

//Count(queue)
//Retorna a quantidade de elementos na fila.
//
//Pré - condição: A fila queue é válida.
//Pós - condição: N / A.
int Count(const StaticQueue& queue)
{
	return queue.count;
}

//IsEmpty(queue)
//Retorna true se a fila estiver vazia ou falso, caso contrário.
//
//Pré - condição: A fila queue é válida.
//Pós - condição: N / A.
bool IsEmpty(const StaticQueue& queue)
{
	return queue.count == 0;
}

//Clear(queue)
//Esvazia a fila(remove todos os elementos da fila).
//
//Pré - condição: A fila queue é válida.
//Pós - condição: A fila queue está vazia.
bool ClearA(StaticQueue& queueA)
{
	while (!IsEmpty(queueA))
	{
		DequeueA(queueA);
	}

	return IsEmpty(queueA);
}

bool ClearB(StaticQueue& queueB)
{
	while (!IsEmpty(queueB))
	{
		DequeueA(queueB);
	}

	return IsEmpty(queueB);
}

