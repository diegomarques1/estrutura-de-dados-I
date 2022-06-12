// GRUPO:
// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gon�alves - TIA: 32074964

#include "StaticDeque.h"

//Create()
//Cria e retorna uma fila dupla vazia.
//
//Pr� - condi��o: N / A.
//P�s - condi��o: Uma nova fila dupla vazia � criada.
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
//Insere o elemento elem no fim da fila dupla deque, se deque n�o estiver cheia.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: O fim de deque cont�m o elemento elem OU erro se deque estiver cheia.
bool InsertBack(StaticDeque& deque, char elem)
{
	if (deque.count == Size(deque))
	{
		return false;
	}

	deque.values[deque.rear] = elem;

	deque.rear = (deque.rear + 1) % Size(deque); // Mant�m deque.rear no intervalo 0 <= deque.rear < Size(deque).
	
	++deque.count; // deque.count += 1

	return true;
}

//InsertFront(deque, elem)
//Insere o elemento elem no in�cio da fila dupla deque, se deque n�o estiver cheia.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: O in�cio de deque cont�m o elemento elem OU erro se deque estiver cheia.
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

	deque.rear = (deque.rear + 1) % Size(deque); // Mant�m deque.rear no intervalo 0 <= deque.rear < Size(deque).

	++deque.count; // deque.count += 1

	return true;
}

//RemoveBack(deque) 
//Remove e retorna o �ltimo elemento da fila dupla deque, se deque n�o estiver vazia.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: Remove e retorna o �ltimo elemento da deque OU erro se deque estiver vazia.
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
//Remove e retorna o primeiro elemento da fila dupla deque, se deque n�o estiver vazia.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: Remove e retorna o primeiro elemento da deque OU erro se deque estiver vazia.
char RemoveFront(StaticDeque& deque)
{
	if (IsEmpty(deque))
	{
		return '\0';
	}

	char value = deque.values[deque.front];
	deque.values[deque.front] = '\0';

	deque.front = (deque.front + 1) % Size(deque); // Mant�m deque.front no intervalo 0 <= deque.front < Size(deque).

	--deque.count; // deque.count -= 1

	return value;
}

//Front(deque) 
//Retorna uma refer�ncia do elemento que est� no come�o da fila dupla (mas n�o o remove), se deque n�o estiver vazia.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: Retorna o primeiro elemento da deque sem remov� - lo OU erro se deque estiver vazia.
char Front(const StaticDeque& deque)
{
	return IsEmpty(deque) ? '\0' : deque.values[deque.front]; // operador tern�rio ?: --> <condi��o> ? true : false;
}

//Back(deque) 
//Retorna uma refer�ncia do elemento que est� no fim da fila dupla (mas n�o o remove), se deque n�o estiver vazia.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: Retorna o �ltimo elemento da deque sem remov� - lo OU erro se deque estiver vazia.
char Back(const StaticDeque& deque)
{
	return IsEmpty(deque) ? '\0' : deque.values[(deque.front + (deque.count - 1)) % Size(deque)];
}

//Size(deque) 
//Retorna a capacidade da fila dupla.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: N / A.
int Size(const StaticDeque& deque)
{
	return sizeof(deque.values) / sizeof(deque.values[0]); // return STATIC_DEQUE_CAPACITY;
}

//Count(deque) 
//Retorna a quantidade de elementos na fila dupla.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: N / A.
int Count(const StaticDeque& deque)
{
	return deque.count;
}

//IsEmpty(deque) 
//Retorna true se a fila dupla estiver vazia ou false, caso contr�rio.
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: N / A.
bool IsEmpty(const StaticDeque& deque)
{
	return deque.count == 0;
}

//Clear(deque) 
//Esvazia a fila dupla(remove todos os elementos da fila).
//
//Pr� - condi��o: A fila dupla deque � v�lida.
//P�s - condi��o: A fila dupla deque est� vazia.
bool Clear(StaticDeque& deque)
{
	while (!IsEmpty(deque))
	{
		RemoveFront(deque);
	}

	return IsEmpty(deque);
}

