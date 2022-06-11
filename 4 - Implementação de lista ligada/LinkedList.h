// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gon�alves - TIA: 32074964

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct Node
{
	int data;
	Node* next;
};

struct LinkedList
{
	int count;
	Node* head;
	Node* tail;
};

//Create() 
//Cria e retorna uma lista vazia.
//
//Pr�-condi��o: N / A.
//P�s-condi��o: Uma nova lista vazia � criada.
LinkedList* Create();

//Destroy(list) 
//Libera a mem�ria que foi alocada para a lista list.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: A lista list � liberada da mem�ria.
void Destroy(LinkedList* list);

//Insert(list, elem) ou AddFront(list, elem)
//Insere um n� com o elemento elem no in�cio da lista list.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: O in�cio da lista cont�m o n� com o elemento elem.
void Insert(LinkedList* list, int elem);

//Append(list, elem) ou AddBack(list, elem)
//Insere um n� com o elemento elem no final da lista list.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: O final da lista cont�m o n� com o elemento elem.
void Append(LinkedList* list, int elem);

//RemoveHead(list) ou RemoveFront(list)
//Remove o n� do in�cio da lista list e retorna uma refer�ncia para o n� OU erro se a lista estiver vazia.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: Remove e retorna o n� do in�cio da lista list OU erro se a lista estiver vazia.
Node* RemoveHead(LinkedList* list);

//RemoveTail(list) ou RemoveBack(list)
//Remove o n� do final da lista list e retorna uma refer�ncia para o n� OU erro se a lista estiver vazia.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: Remove e retorna o n� do final da lista list OU erro se a lista estiver vazia.
Node* RemoveTail(LinkedList* list);

//RemoveNode(list, value) 
//Remove o n� com valor value da lista list e retorna uma refer�ncia para o n� OU erro se a lista estiver vazia.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: Remove e retorna o n� com valor value da lista list OU erro se a lista estiver vazia.
Node* RemoveNode(LinkedList* list, int value);

//GetHead(list) ou GetFront(list)
//Retorna uma refer�ncia para o n� do in�cio da lista list OU erro se a lista estiver vazia.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: Retorna o n� do in�cio da lista list sem remov�-lo OU erro se a lista estiver vazia.
Node* GetHead(const LinkedList* list);

//GetTail(list) ou GetBack(list)
//Retorna uma refer�ncia para o n� do final da lista list OU erro se a lista estiver vazia.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: Retorna o n� do final da lista list sem remov�-lo OU erro se a lista estiver vazia.
Node* GetTail(const LinkedList* list);

//GetNode(list, value) 
//Retorna uma refer�ncia para o n� com valor value da lista list OU erro se a lista estiver vazia.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: Retorna o n� do com valor value da lista list sem remov�-lo OU erro se a lista estiver vazia.
Node* GetNode(const LinkedList* list, int value);

//Count(list) 
//Retorna a quantidade de n�s na lista list.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: N/A.
int Count(const LinkedList* list);

//IsEmpty(list) 
//Retorna true se a lista list estiver vazia ou falso, caso contr�rio.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: N/A.
bool IsEmpty(const LinkedList* list);

//Clear(list) 
//Esvazia a lista list (remove todos os n�s da lista).
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: A lista list est� vazia.
void Clear(LinkedList* list);

// CreateNode(data, next);

// DestroyNode(node);

#endif // __LINKED_LIST_H__