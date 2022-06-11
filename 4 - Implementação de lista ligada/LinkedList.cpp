// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include "LinkedList.h"

//Create() 
//Cria e retorna uma lista vazia.
//
//Pré-condição: N / A.
//Pós-condição: Uma nova lista vazia é criada.
LinkedList* Create()
{
	// cria / aloca memória para uma nova lista
	LinkedList* list = new LinkedList;

	// tamanho da lista começa com zero
	list->count = 0;

	// head começa com valor nulo
	list->head = nullptr;

	// tail começa com valor nulo
	list->tail = nullptr;

	// retorna a nova lista
	return list;
}

//Destroy(list) 
//Libera a memória que foi alocada para a lista list.
//
//Pré-condição: A lista list é válida.
//Pós-condição: A lista list é liberada da memória.
void Destroy(LinkedList* list)
{
	// esvazia a lista(Clear())
	Clear(list);

	// libera memória alocada para a lista
	delete list;
}

//Insert(list, elem) ou AddFront(list, elem)
//Insere um nó com o elemento elem no início da lista list.
//
//Pré-condição: A lista list é válida.
//Pós-condição: O início da lista contém o nó com o elemento elem.
void Insert(LinkedList* list, int elem)
{
	// cria / aloca novo nó node
	Node* node = new Node;

	// node->data = data
	node->data = elem;

	// node é o primeiro nó da lista, então node->next aponta para head
	node->next = list->head;

	// se lista estiver vazia
	if (IsEmpty(list))
	{
		// tail aponta para node
		list->tail = node;
	}

	// head aponta para node
	list->head = node;

	// aumenta o tamanho da lista
	list->count++;
}

//Append(list, elem) ou AddBack(list, elem)
//Insere um nó com o elemento elem no final da lista list.
//
//Pré-condição: A lista list é válida.
//Pós-condição: O final da lista contém o nó com o elemento elem.
void Append(LinkedList* list, int elem)
{
	// cria / aloca novo nó node
	Node* node = new Node;

	// node->data = data
	node->data = elem;

	// node é o último nó da lista, então node->next é nulo(temp->next = nullptr)
	node->next = nullptr;

	// se lista estiver vazia
	if (IsEmpty(list))
	{
		// head e tail apontam para node
		list->head = list->tail = node;
	}
	// senão
	else
	{
		// tail.next aponta para node
		list->tail->next = node;

		// tail aponta para node
		list->tail = node;
	}

	// aumenta o tamanho da lista
	list->count++;
}

//RemoveHead(list) ou RemoveFront(list)
//Remove o nó do início da lista list e retorna uma referência para o nó OU erro se a lista estiver vazia.
//
//Pré-condição: A lista list é válida.
//Pós-condição: Remove e retorna o nó do início da lista list OU erro se a lista estiver vazia.
Node* RemoveHead(LinkedList* list)
{
	if (IsEmpty(list))
	{
		return nullptr;
	}

	//cria nó toRemove que aponta para head
	Node* toRemove = list->head;

	//se existe só um nó na lista(head é igual à tail)
	if (list->head == list->tail)
	{
		//não há mais nós na lista(head e tail viram nulo)
		list->head = list->tail = nullptr;
	}
	else //senão
	{
		//head agora aponta para o segundo nó(head->next)
		list->head = list->head->next;
	}

	//diminui tamanho da lista
	list->count--;

	toRemove->next = nullptr;

	//retorna toRemove
	return toRemove;
}

//RemoveTail(list) ou RemoveBack(list)
//Remove o nó do final da lista list e retorna uma referência para o nó OU erro se a lista estiver vazia.
//
//Pré-condição: A lista list é válida.
//Pós-condição: Remove e retorna o nó do final da lista list OU erro se a lista estiver vazia.
Node* RemoveTail(LinkedList* list)
{
	// se existe só um nó na lista
	if (list->head == list->tail)
	{
		// remove e retorna nó usando RemoveHead()
		return RemoveHead(list);
	}
	// percorre a lista até chegar em tail:

	// cria nó toRemove que começa em head
	Node* toRemove = list->head;

	// cria nó previous que começa como nulo
	Node* previous = nullptr;

	// enquanto toRemove não chegou em tail
	while (toRemove != list->tail)
	{
		// previous aponta para toRemove
		previous = toRemove;

		// toRemove aponta para o próximo nó da lista(toRemove->next)
		toRemove = toRemove->next;
	}

	// previous->next aponta para nulo
	previous->next = nullptr;

	// tail aponta para penúltimo nó (previous)
	list->tail = previous;

	// diminui tamanho da lista
	list->count--;

	toRemove->next = nullptr;

	// retorna toRemove
	return toRemove;
}

//RemoveNode(list, value) 
//Remove o nó com valor value da lista list e retorna uma referência para o nó OU erro se a lista estiver vazia.
//
//Pré-condição: A lista list é válida.
//Pós-condição: Remove e retorna o nó com valor value da lista list OU erro se a lista estiver vazia.
Node* RemoveNode(LinkedList* list, int value)
{
	// cria nó toRemove que começa em head
	Node* toRemove = list->head;

	// cria nó previous que começa como nulo
	Node* previous = nullptr;

	// enquanto toRemove não for nulo e valor de toRemove não é value
	while (toRemove != nullptr && toRemove->data != value)
	{
		// previous aponta para toRemove
		previous = toRemove;

		// toRemove aponta para o próximo nó da lista(toRemove->next)
		toRemove = toRemove->next;
	}

	// se toRemove for head, remove e retorna nó usando RemoveHead()
	if (toRemove == list->head) return RemoveHead(list);

	// se toRemove for tail, remove e retorna nó usando RemoveTail()
	else if (toRemove == list->tail) return RemoveTail(list);

	// se toRemove for diferente de nulo
	else if (toRemove != nullptr)
	{
		// previous->next aponta para toRemove->next
		previous->next = toRemove->next;

		// diminui tamanho da lista
		list->count--;

		toRemove->next = nullptr;

		// retorna toRemove
		return toRemove;
	}

	// se toRemove for nulo, retorna nulo
	return nullptr;
}

//GetHead(list) ou GetFront(list)
//Retorna uma referência para o nó do início da lista list OU erro se a lista estiver vazia.
//
//Pré-condição: A lista list é válida.
//Pós-condição: Retorna o nó do início da lista list sem removê-lo OU erro se a lista estiver vazia.
Node* GetHead(const LinkedList* list)
{
	// retorna nó head
	return list->head;
}

//GetTail(list) ou GetBack(list)
//Retorna uma referência para o nó do final da lista list OU erro se a lista estiver vazia.
//
//Pré-condição: A lista list é válida.
//Pós-condição: Retorna o nó do final da lista list sem removê-lo OU erro se a lista estiver vazia.
Node* GetTail(const LinkedList* list)
{
	// retorna nó tail
	return list->tail;
}

//GetNode(list, value) 
//Retorna uma referência para o nó com valor value da lista list OU erro se a lista estiver vazia.
//
//Pré-condição: A lista list é válida.
//Pós-condição: Retorna o nó do com valor value da lista list sem removê-lo OU erro se a lista estiver vazia.
Node* GetNode(const LinkedList* list, int value)
{
	// cria nó node que aponta para head
	Node* node = list->head;

	// enquanto não chegou ao fim da lista(node não é nulo)
	while (node != nullptr)
	{
		// se node tem valor value
		if (node->data == value)
		{
			// retorna node
			return node;
		}
		// node aponta para node->next
		node = node->next;
	}
	// retorna nulo, já que nó com valor value não foi encontrado
	return nullptr;
}

//Count(list) 
//Retorna a quantidade de nós na lista list.
//
//Pré-condição: A lista list é válida.
//Pós-condição: N/A.
int Count(const LinkedList* list)
{
	return list->count;
}

//IsEmpty(list) 
//Retorna true se a lista list estiver vazia ou falso, caso contrário.
//
//Pré-condição: A lista list é válida.
//Pós-condição: N/A.
bool IsEmpty(const LinkedList* list)
{
	return list->head == nullptr && list->tail == nullptr;
}

//Clear(list) 
//Esvazia a lista list (remove todos os nós da lista).
//
//Pré-condição: A lista list é válida.
//Pós-condição: A lista list está vazia.
void Clear(LinkedList* list)
{
	// cria nó node que começa em head
	Node* node = list->head;

	// cria nó next que começa como nulo
	Node* next = nullptr;

	// enquanto node não for nulo
	while (node != nullptr)
	{
		// next aponta para node->next
		next = node->next;

		// libera memória alocada para node
		delete node;

		// node aponta para next
		node = next;
	}

	// lista vazia = 0 elementos
	list->count = 0;

	// lista vazia = head e tail nulos
	list->head = list->tail = nullptr;
}

// CreateNode(data, next);

// DestroyNode(node);