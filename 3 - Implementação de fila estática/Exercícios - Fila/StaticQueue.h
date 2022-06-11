// Diego Souza Lima Marques
// TIA: 32039921

#ifndef __STATIC_QUEUE_H__
#define __STATIC_QUEUE_H__
#include <ctime>

// Estrutura de dados do tipo Fila.
const int STATIC_QUEUE_CAPACITY = 8;

struct Product
{
	char brand;
	time_t date;
	int rack;
	int shelf;
	int drawer;
};

struct StaticQueue
{
	int front;
	int rear;
	int count;
	Product values[STATIC_QUEUE_CAPACITY];
};

Product StartProduct();

// Sintaxe da fun��o:
// <tipo do retorno> <nome da fun��o>(<par�metros, caso exista>);

//Create()
//Cria e retorna uma fila vazia.
//
//Pr� - condi��o: N / A.
//P�s - condi��o: Uma nova fila vazia � criada.
StaticQueue Create();

//Enqueue(queue, elem)
//Insere o elemento elem no fim da fila queue, se a fila n�o estiver cheia.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: O final da fila cont�m o elemento elem OU erro se a fila estiver cheia.
bool EnqueueA(StaticQueue& queue, Product elem);

bool EnqueueB(StaticQueue& queue, Product elem);

//Dequeue(queue)
//Remove e retorna o primeiro elemento da fila queue, se a fila n�o estiver vazia.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: Remove e retorna o primeiro elemento da fila OU erro se a fila estiver vazia.
Product DequeueA(StaticQueue& queue);

Product DequeueB(StaticQueue& queue);

Product DequeueAny(StaticQueue& queueA, StaticQueue& queueB);

//Front(queue)
//Retorna uma refer�ncia do elemento que est� no come�o da fila(mas n�o o remove), se a fila n�o estiver vazia.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: Retorna o primeiro elemento da fila sem remov� - lo OU erro se a fila estiver vazia.
Product Front(const StaticQueue &queue);

//Size(queue)
//Retorna a capacidade da fila.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: N / A.
int Size(const StaticQueue &queue);

//Count(queue)
//Retorna a quantidade de elementos na fila.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: N / A.
int Count(const StaticQueue &queue);

//IsEmpty(queue)
//Retorna true se a fila estiver vazia ou falso, caso contr�rio.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: N / A.
bool IsEmpty(const StaticQueue &queue);

//Clear(queue)
//Esvazia a fila(remove todos os elementos da fila).
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o: A fila queue est� vazia.
bool ClearA(StaticQueue &queueA);

bool ClearB(StaticQueue& queueB);

#endif // __STATIC_QUEUE_H__