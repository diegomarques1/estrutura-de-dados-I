// Diego Souza Lima Marques
// TIA: 32039921
// P1 - Estrutura de Dados I

#ifndef __STATIC_QUEUE_H__
#define __STATIC_QUEUE_H__

#include "StaticStack.h"

namespace DataStructures
{
namespace Queue
{
	struct StaticQueue
	{
		Stack::StaticStack stackAux;
	};

	//Create()
	//Cria e retorna uma fila vazia.
	//
	//Pré - condição: N / A.
	//Pós - condição : Uma nova fila vazia é criada.
	DataStructures::Queue::StaticQueue Create();

	//Enqueue(queue, elem)
	//Insere o elemento elem no fim da fila queue, se a fila não estiver cheia.
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : O final da fila contém o elemento elem OU erro se a fila estiver cheia.
	bool Enqueue(DataStructures::Queue::StaticQueue& queue, char elem);

	//Dequeue(queue)
	//Remove e retorna o primeiro elemento da fila queue, se a fila não estiver vazia.
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : Remove e retorna o primeiro elemento da fila OU erro se a fila estiver vazia.
	char Dequeue(DataStructures::Queue::StaticQueue& queue);

	//Front(queue)
	//Retorna uma referência do elemento que está no começo da fila(mas não o remove), se a fila não estiver vazia.
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : Retorna o primeiro elemento da fila sem removê - lo OU erro se a fila estiver vazia.
	char Front(const DataStructures::Queue::StaticQueue& queue);

	//Size(queue)
	//Retorna a capacidade da fila.
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : N / A.
	int Size(const DataStructures::Queue::StaticQueue& queue);

	//Count(queue)
	//Retorna a quantidade de elementos na fila.
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : N / A.
	int Count(const DataStructures::Queue::StaticQueue& queue);

	//IsEmpty(queue)
	//Retorna true se a fila estiver vazia ou falso, caso contrário.
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : N / A.
	bool IsEmpty(const DataStructures::Queue::StaticQueue& queue);

	//Clear(queue)
	//Esvazia a fila(remove todos os elementos da fila).
	//
	//Pré - condição: A fila queue é válida.
	//Pós - condição : A fila queue está vazia.
	bool Clear(DataStructures::Queue::StaticQueue& queue);

} // namespace Queue
} // namespace DataStructures

#endif // __STATIC_QUEUE_H__