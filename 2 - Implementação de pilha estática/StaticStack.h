#ifndef __STATIC_STACK_H__
#define __STATIC_STACK_H__

// Define uma stack usando vetor (array).
const int STATIC_STACK_CAPACITY = 8;

struct StaticStack
{
	int current; // Quantidade de elementos na pilha (topo == current - 1).
	char values[STATIC_STACK_CAPACITY]; // Vetor com os elementos empilhados.
};

//Create()
//Cria e retorna uma pilha vazia.
//
//Pr� - condi��o : N / A.
//P�s - condi��o : Uma nova pilha vazia � criada.
StaticStack Create();

//Push(stack, elem)
//Insere o elemento elem no topo da pilha stack.
//
//Pr� - condi��o: A pilha stack � v�lida.
//P�s - condi��o : O topo da pilha cont�m o elemento elem OU erro se a pilha estiver cheia.
bool Push(StaticStack &stack, char elem);

//Pop(stack)
//Remove o elemento do topo da pilha stack, se a pilha n�o estiver vazia.
//
//Pr� - condi��o: A pilha stack � v�lida.
//P�s - condi��o : Remove e retorna o elemento do topo da pilha OU erro se pilha estiver vazia.
char Pop(StaticStack &stack);

//Top(stack)
//Retorna uma refer�ncia do elemento que est� no topo da pilha(mas n�o o remove), se a pilha n�o estiver vazia.
//
//Pr� - condi��o : A pilha stack � v�lida.
//P�s - condi��o : Retorna o elemento do topo da pilha, sem remov� - lo OU erro se pilha estiver vazia.
char Top(const StaticStack &stack);

//Size(stack)
//Retorna a capacidade da pilha.
//
//Pr� - condi��o : A pilha stack � v�lida.
//P�s - condi��o : N / A.
int Size(const StaticStack &stack);

//Count(stack)
//Retorna a quantidade de elementos na pilha.
//
//Pr� - condi��o : A pilha stack � v�lida.
//P�s - condi��o : N / A.
int Count(const StaticStack& stack);

//IsEmpty(stack)
//Retorna true se a pilha estiver vazia ou falso, caso contr�rio.
//
//Pr� - condi��o : A pilha stack � v�lida.
//P�s - condi��o : N / A.
bool IsEmpty(const StaticStack &stack);

//Clear(stack)
//Esvazia a pilha(remove todos os elementos da pilha).
//
//Pr� - condi��o : A pilha stack � v�lida.
//P�s - condi��o : A pilha stack est� vazia.
bool Clear(StaticStack &stack);

#endif // __STATIC_STACK_H__