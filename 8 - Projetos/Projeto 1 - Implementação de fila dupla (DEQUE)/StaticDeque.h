// GRUPO:
// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#ifndef __STATIC_DEQUE_H__
#define __STATIC_DEQUE_H__

// Estrutura de dados do tipo Fila Dupla (Deque).
const int STATIC_DEQUE_CAPACITY = 10;

struct StaticDeque
{
	int front;
	int rear;
	int count;
	char values[STATIC_DEQUE_CAPACITY];
};

//Create()
//Cria e retorna uma fila dupla vazia.
//
//Pré - condição: N / A.
//Pós - condição: Uma nova fila dupla vazia é criada.
StaticDeque Create();

//InsertBack(deque, elem)
//Insere o elemento elem no fim da fila dupla deque, se deque não estiver cheia.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: O fim de deque contém o elemento elem OU erro se deque estiver cheia.
bool InsertBack(StaticDeque& deque, char elem);

//InsertFront(deque, elem)
//Insere o elemento elem no início da fila dupla deque, se deque não estiver cheia.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: O início de deque contém o elemento elem OU erro se deque estiver cheia.
bool InsertFront(StaticDeque& deque, char elem);

//RemoveBack(deque) 
//Remove e retorna o último elemento da fila dupla deque, se deque não estiver vazia.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: Remove e retorna o último elemento da deque OU erro se deque estiver vazia.
char RemoveBack(StaticDeque &deque);

// RemoveFront(deque)
//Remove e retorna o primeiro elemento da fila dupla deque, se deque não estiver vazia.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: Remove e retorna o primeiro elemento da deque OU erro se deque estiver vazia.
char RemoveFront(StaticDeque& deque);

//Front(deque) 
//Retorna uma referência do elemento que está no começo da fila dupla (mas não o remove), se deque não estiver vazia.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: Retorna o primeiro elemento da deque sem removê - lo OU erro se deque estiver vazia.
char Front(const StaticDeque &deque);

//Back(deque) 
//Retorna uma referência do elemento que está no fim da fila dupla (mas não o remove), se deque não estiver vazia.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: Retorna o último elemento da deque sem removê - lo OU erro se deque estiver vazia.
char Back(const StaticDeque& deque);

//Size(deque) 
//Retorna a capacidade da fila dupla.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: N / A.
int Size(const StaticDeque &deque);

//Count(deque) 
//Retorna a quantidade de elementos na fila dupla.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: N / A.
int Count(const StaticDeque &deque);

//IsEmpty(deque) 
//Retorna true se a fila dupla estiver vazia ou false, caso contrário.
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: N / A.
bool IsEmpty(const StaticDeque &deque);

//Clear(deque) 
//Esvazia a fila dupla(remove todos os elementos da fila).
//
//Pré - condição: A fila dupla deque é válida.
//Pós - condição: A fila dupla deque está vazia.
bool Clear(StaticDeque &deque);

#endif // __STATIC_DEQUE_H__