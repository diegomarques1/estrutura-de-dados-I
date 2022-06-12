// GRUPO:
// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gon�alves - TIA: 32074964

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
//Pr� - condi��o: N / A.
//P�s - condi��o: Uma nova fila dupla vazia � criada.
StaticDeque Create();

//InsertBack(deque, elem)
//Insere o elemento elem no fim da fila dupla deque, se deque n�o estiver cheia.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: O fim de deque cont�m o elemento elem OU erro se deque estiver cheia.
bool InsertBack(StaticDeque& deque, char elem);

//InsertFront(deque, elem)
//Insere o elemento elem no in�cio da fila dupla deque, se deque n�o estiver cheia.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: O in�cio de deque cont�m o elemento elem OU erro se deque estiver cheia.
bool InsertFront(StaticDeque& deque, char elem);

//RemoveBack(deque) 
//Remove e retorna o �ltimo elemento da fila dupla deque, se deque n�o estiver vazia.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: Remove e retorna o �ltimo elemento da deque OU erro se deque estiver vazia.
char RemoveBack(StaticDeque &deque);

// RemoveFront(deque)
//Remove e retorna o primeiro elemento da fila dupla deque, se deque n�o estiver vazia.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: Remove e retorna o primeiro elemento da deque OU erro se deque estiver vazia.
char RemoveFront(StaticDeque& deque);

//Front(deque) 
//Retorna uma refer�ncia do elemento que est� no come�o da fila dupla (mas n�o o remove), se deque n�o estiver vazia.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: Retorna o primeiro elemento da deque sem remov� - lo OU erro se deque estiver vazia.
char Front(const StaticDeque &deque);

//Back(deque) 
//Retorna uma refer�ncia do elemento que est� no fim da fila dupla (mas n�o o remove), se deque n�o estiver vazia.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: Retorna o �ltimo elemento da deque sem remov� - lo OU erro se deque estiver vazia.
char Back(const StaticDeque& deque);

//Size(deque) 
//Retorna a capacidade da fila dupla.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: N / A.
int Size(const StaticDeque &deque);

//Count(deque) 
//Retorna a quantidade de elementos na fila dupla.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: N / A.
int Count(const StaticDeque &deque);

//IsEmpty(deque) 
//Retorna true se a fila dupla estiver vazia ou false, caso contr�rio.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: N / A.
bool IsEmpty(const StaticDeque &deque);

//Clear(deque) 
//Esvazia a fila dupla(remove todos os elementos da fila).
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: A fila dupla deque est� vazia.
bool Clear(StaticDeque &deque);

#endif // __STATIC_DEQUE_H__