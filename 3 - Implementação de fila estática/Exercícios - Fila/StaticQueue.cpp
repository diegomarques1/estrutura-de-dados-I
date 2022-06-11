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
//Pr� - condi��o: N / A.
//P�s - condi��o : Uma nova fila vazia � criada.
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
//Insere o elemento elem no fim da fila queue, se a fila n�o estiver cheia.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: O final da fila cont�m o elemento elem OU erro se a fila estiver cheia.
bool EnqueueA(StaticQueue& queue, Product elem)
{
	if (queue.count == Size(queue))
	{
		return false;
	}

	queue.values[queue.rear] = elem;
	
	queue.rear = (queue.rear + 1) % Size(queue); // Mant�m queue.rear no intervalo 0 <= queue.rear < Size(queue).
	// A linha acima equivale �:
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
//Remove e retorna o primeiro elemento da fila queue, se a fila n�o estiver vazia.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: Remove e retorna o primeiro elemento da fila OU erro se a fila estiver vazia.
Product DequeueA(StaticQueue& queueA)
{
	if (IsEmpty(queueA))
	{
		return StartProduct();
	}

	Product value = queueA.values[queueA.front];
	queueA.values[queueA.front] = StartProduct();

	queueA.front = (queueA.front + 1) % Size(queueA); // Mant�m queue.front no intervalo 0 <= queue.front < Size(queue).

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
//Retorna uma refer�ncia do elemento que est� no come�o da fila(mas n�o o remove), se a fila n�o estiver vazia.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: Retorna o primeiro elemento da fila sem remov� - lo OU erro se a fila estiver vazia.
Product Front(const StaticQueue& queue)
{
	// operador tern�rio ?: --> <condi��o> ? true : false;
	return IsEmpty(queue) ? StartProduct() : queue.values[queue.front];
}

//Size(queue)
//Retorna a capacidade da fila.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: N / A.
int Size(const StaticQueue& queue)
{
	return sizeof(queue.values) / sizeof(queue.values[0]); // return STATIC_QUEUE_CAPACITY;
}

//Count(queue)
//Retorna a quantidade de elementos na fila.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: N / A.
int Count(const StaticQueue& queue)
{
	return queue.count;
}

//IsEmpty(queue)
//Retorna true se a fila estiver vazia ou falso, caso contr�rio.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: N / A.
bool IsEmpty(const StaticQueue& queue)
{
	return queue.count == 0;
}

//Clear(queue)
//Esvazia a fila(remove todos os elementos da fila).
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: A fila queue est� vazia.
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

