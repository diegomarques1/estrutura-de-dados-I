// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

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
//Pré-condição: N / A.
//Pós-condição: Uma nova lista vazia é criada.
LinkedList* Create();

//Destroy(list) 
//Libera a memória que foi alocada para a lista list.
//
//Pré-condição: A lista list é válida.
//Pós-condição: A lista list é liberada da memória.
void Destroy(LinkedList* list);

//Insert(list, elem) ou AddFront(list, elem)
//Insere um nó com o elemento elem no início da lista list.
//
//Pré-condição: A lista list é válida.
//Pós-condição: O início da lista contém o nó com o elemento elem.
void Insert(LinkedList* list, int elem);

//Append(list, elem) ou AddBack(list, elem)
//Insere um nó com o elemento elem no final da lista list.
//
//Pré-condição: A lista list é válida.
//Pós-condição: O final da lista contém o nó com o elemento elem.
void Append(LinkedList* list, int elem);

//RemoveHead(list) ou RemoveFront(list)
//Remove o nó do início da lista list e retorna uma referência para o nó OU erro se a lista estiver vazia.
//
//Pré-condição: A lista list é válida.
//Pós-condição: Remove e retorna o nó do início da lista list OU erro se a lista estiver vazia.
Node* RemoveHead(LinkedList* list);

//RemoveTail(list) ou RemoveBack(list)
//Remove o nó do final da lista list e retorna uma referência para o nó OU erro se a lista estiver vazia.
//
//Pré-condição: A lista list é válida.
//Pós-condição: Remove e retorna o nó do final da lista list OU erro se a lista estiver vazia.
Node* RemoveTail(LinkedList* list);

//RemoveNode(list, value) 
//Remove o nó com valor value da lista list e retorna uma referência para o nó OU erro se a lista estiver vazia.
//
//Pré-condição: A lista list é válida.
//Pós-condição: Remove e retorna o nó com valor value da lista list OU erro se a lista estiver vazia.
Node* RemoveNode(LinkedList* list, int value);

//GetHead(list) ou GetFront(list)
//Retorna uma referência para o nó do início da lista list OU erro se a lista estiver vazia.
//
//Pré-condição: A lista list é válida.
//Pós-condição: Retorna o nó do início da lista list sem removê-lo OU erro se a lista estiver vazia.
Node* GetHead(const LinkedList* list);

//GetTail(list) ou GetBack(list)
//Retorna uma referência para o nó do final da lista list OU erro se a lista estiver vazia.
//
//Pré-condição: A lista list é válida.
//Pós-condição: Retorna o nó do final da lista list sem removê-lo OU erro se a lista estiver vazia.
Node* GetTail(const LinkedList* list);

//GetNode(list, value) 
//Retorna uma referência para o nó com valor value da lista list OU erro se a lista estiver vazia.
//
//Pré-condição: A lista list é válida.
//Pós-condição: Retorna o nó do com valor value da lista list sem removê-lo OU erro se a lista estiver vazia.
Node* GetNode(const LinkedList* list, int value);

//Count(list) 
//Retorna a quantidade de nós na lista list.
//
//Pré-condição: A lista list é válida.
//Pós-condição: N/A.
int Count(const LinkedList* list);

//IsEmpty(list) 
//Retorna true se a lista list estiver vazia ou falso, caso contrário.
//
//Pré-condição: A lista list é válida.
//Pós-condição: N/A.
bool IsEmpty(const LinkedList* list);

//Clear(list) 
//Esvazia a lista list (remove todos os nós da lista).
//
//Pré-condição: A lista list é válida.
//Pós-condição: A lista list está vazia.
void Clear(LinkedList* list);

// CreateNode(data, next);

// DestroyNode(node);

#endif // __LINKED_LIST_H__