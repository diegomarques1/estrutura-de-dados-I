// Diego Souza Lima Marques - TIA: 32039921

#ifndef __DOUBLY_CIRCULAR_LINKED_LIST_H__
#define __DOUBLY_CIRCULAR_LINKED_LIST_H__

#include <string>

struct Node
{
	int id;
	std::string name;
	Node* previous;
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
void Insert(LinkedList* list, int id, std::string name);

// InsertBefore(list, beforeId, id, name)
// Cria um n� contendo id(n�mero inteiro) e name(string) e insere o novo n� antes do n� que cont�m o id beforeId, exceto:
// - Se a fila estiver vazia, n�o insere o novo n� na lista e retorna false.
// - Se n�o existe um n� na lista com o id beforeId, n�o insere o novo n� na lista e retorna false.
//
// Pr�-condi��o: A lista ligada / encadeada list � v�lida.
// P�s-condi��o: Se foi poss�vel inserir o novo n� na lista, a lista deve conter o novo n�, na posi��o correta,
// e a fun��o retorna true (�n� inserido na lista�).
// Caso contr�rio, a fun��o retorna false (�n�o foi poss�vel inserir n� na lista�), sem inserir o novo n� na lista
bool InsertBefore(LinkedList* list, int beforeId, int id, std::string name);

//InsertAfter(list, afterId, id, name)
//Cria um n� contendo id(n�mero inteiro) e name(string) e insere o novo n� depois do n� que cont�m o id afterId, exceto:
// - Se a fila estiver vazia, n�o insere o novo n� na lista e retorna false.
// - Se n�o existe um n� na lista com o id afterId, n�o insere o novo n� na lista e retorna false.
// Pr�-condi��o: A lista ligada / encadeada list � v�lida.
// P�s-condi��o: Se foi poss�vel inserir o novo n� na lista, a lista deve conter o novo n�, na posi��o correta,
// e a fun��o retorna true (�n� inserido na lista�).
// Caso contr�rio, a fun��o retorna false (�n�o foi poss�vel inserir n� na lista�), sem inserir o novo n� na lista
bool InsertAfter(LinkedList* list, int afterId, int id, std::string name);

//Append(list, elem) ou AddBack(list, elem)
//Insere um n� com o elemento elem no final da lista list.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: O final da lista cont�m o n� com o elemento elem.
void Append(LinkedList* list, int id, std::string name);

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
Node* RemoveNode(LinkedList* list, int id);

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
Node* GetNode(const LinkedList* list, int id);

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

#endif // __DOUBLY_CIRCULAR_LINKED_LIST_H__