// Diego Souza Lima Marques
// TIA: 32039921
// P1 - Estrutura de Dados I

#include "StaticQueue.h"

namespace DataStructures
{
namespace Queue
{
	//Create()
	//Cria e retorna uma fila vazia.
	//
	//Pré - condição: N / A.
	//Pós - condição : Uma nova fila vazia é criada.
	StaticQueue Create()
	{
		StaticQueue queue = { Stack::Create()};
		return queue;
	}

	//Enqueue(queue, elem)
	//Insere o elemento elem no fim da fila queue, se a fila não estiver cheia.
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : O final da fila contém o elemento elem OU erro se a fila estiver cheia.
	bool Enqueue(DataStructures::Queue::StaticQueue& queue, char elem)
	{
		return DataStructures::Stack::Push(queue.stackAux, elem);
	}

	//Dequeue(queue)
	//Remove e retorna o primeiro elemento da fila queue, se a fila não estiver vazia.
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : Remove e retorna o primeiro elemento da fila OU erro se a fila estiver vazia.
	char Dequeue(DataStructures::Queue::StaticQueue& queue)
	{
		DataStructures::Stack::StaticStack stackTemp = Stack::Create();
		while (!DataStructures::Queue::IsEmpty(queue))
		{
			DataStructures::Stack::Push(stackTemp, Stack::Top(queue.stackAux));
			DataStructures::Stack::Pop(queue.stackAux);
		}
		char value = DataStructures::Stack::Pop(stackTemp);
		while (!DataStructures::Stack::IsEmpty(stackTemp))
		{
			DataStructures::Stack::Push(queue.stackAux, Stack::Top(stackTemp));
			DataStructures::Stack::Pop(stackTemp);
		}
		return value;
	}

	//Front(queue)
	//Retorna uma referência do elemento que está no começo da fila(mas não o remove), se a fila não estiver vazia.
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : Retorna o primeiro elemento da fila sem removê - lo OU erro se a fila estiver vazia.
	char Front(const DataStructures::Queue::StaticQueue& queue)
	{
		Stack::StaticStack stackTemp = queue.stackAux;
		return DataStructures::Queue::IsEmpty(queue) ? '\0' : stackTemp.values[0];
	}

	//Size(queue)
	//Retorna a capacidade da fila.
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : N / A.
	int Size(const DataStructures::Queue::StaticQueue& queue)
	{
		return DataStructures::Stack::Size(queue.stackAux); 
	}

	//Count(queue)
	//Retorna a quantidade de elementos na fila.
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : N / A.
	int Count(const DataStructures::Queue::StaticQueue& queue)
	{
		return DataStructures::Stack::Count(queue.stackAux);
	}

	//IsEmpty(queue)
	//Retorna true se a fila estiver vazia ou falso, caso contrário.
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : N / A.
	bool IsEmpty(const DataStructures::Queue::StaticQueue& queue)
	{
		return DataStructures::Stack::IsEmpty(queue.stackAux);
	}

	//Clear(queue)
	//Esvazia a fila(remove todos os elementos da fila).
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : A fila queue está vazia.
	bool Clear(DataStructures::Queue::StaticQueue& queue)
	{
		return DataStructures::Stack::Clear(queue.stackAux);
	}

} // namespace Queue
} // namespace DataStructures

