// Diego Souza Lima Marques - TIA: 32039921

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
	list = nullptr;
}

//Insert(list, elem) ou AddFront(list, elem)
//Insere um nó com o elemento elem no início da lista list.
//
//Pré-condição: A lista list é válida.
//Pós-condição: O início da lista contém o nó com o elemento elem.
void Insert(LinkedList* list, int id, std::string name)
{
	Node* node = new Node;

	node->id = id;

	node->name = name;

	node->previous = list->tail;

	node->next = list->head;

	if (IsEmpty(list))
	{
		list->tail = node;
	}
	else
	{
		list->head->previous = node;
	}

	list->head = node;

	// Circular.
	list->tail->next = list->head;

	++list->count;
}

// InsertBefore(list, beforeId, id, name)
// Cria um nó contendo id(número inteiro) e name(string) e insere o novo nó antes do nó que contém o id beforeId, exceto:
// - Se a fila estiver vazia, não insere o novo nó na lista e retorna false.
// - Se não existe um nó na lista com o id beforeId, não insere o novo nó na lista e retorna false.
//
// Pré-condição: A lista ligada / encadeada list é válida.
// Pós-condição: Se foi possível inserir o novo nó na lista, a lista deve conter o novo nó, na posição correta,
// e a função retorna true (“nó inserido na lista”).
// Caso contrário, a função retorna false (“não foi possível inserir nó na lista”), sem inserir o novo nó na lista
bool InsertBefore(LinkedList* list, int beforeId, int id, std::string name)
{
	// Complexidade do algoritmo: O(n)
	// Todo o conteúdo de if/else é O(1). A chamada de função IsEmpty() também é O(1).
	// Insert() também é O(1), já que não temos qualquer loop dentro.
	// Porém, a chamada da função GetNode() é O(n), por causa da existência do loop do-while em sua implementação.
	// Esta operação é O(n) porque percorre, em seu pior caso, toda a lista (n nós) para encontrar o nó com tal id (beforeId).
	// Portanto, a operação InsertBefore tem complexidade O(n).

	if (IsEmpty(list))
	{
		return false;
	}

	Node* before = GetNode(list, beforeId);
	if (before == nullptr)
	{
		return false;
	}

	if (before == list->head) Insert(list, id, name);
	else
	{
		Node* node = new Node;
		node->id = id;
		node->name = name;

		before->previous->next = node;

		node->previous = before->previous;

		before->previous = node;

		node->next = before;

		++list->count;
	}
	return true;
}

//Append(list, elem) ou AddBack(list, elem)
//Insere um nó com o elemento elem no final da lista list.
//
//Pré-condição: A lista list é válida.
//Pós-condição: O final da lista contém o nó com o elemento elem.
void Append(LinkedList* list, int id, std::string name)
{
	Node* node = new Node;

	node->id = id;

	node->name = name;

	node->previous = list->tail;

	node->next = list->head;

	if (IsEmpty(list))
	{
		list->head = node;
	}
	else
	{
		list->tail->next = node;
	}

	list->tail = node;

	// Circular.
	list->head->previous = list->tail;

	++list->count;
}

//InsertAfter(list, afterId, id, name)
//Cria um nó contendo id(número inteiro) e name(string) e insere o novo nó depois do nó que contém o id afterId, exceto:
// - Se a fila estiver vazia, não insere o novo nó na lista e retorna false.
// - Se não existe um nó na lista com o id afterId, não insere o novo nó na lista e retorna false.
//
// Pré-condição: A lista ligada / encadeada list é válida.
// Pós-condição: Se foi possível inserir o novo nó na lista, a lista deve conter o novo nó, na posição correta,
// e a função retorna true (“nó inserido na lista”).
// Caso contrário, a função retorna false (“não foi possível inserir nó na lista”), sem inserir o novo nó na lista
bool InsertAfter(LinkedList* list, int afterId, int id, std::string name)
{
	// Complexidade do algoritmo: O(n)
	// Chamadas de if/else são todas O(1). IsEmpty() também é O(1). 
	// Append() é O(1) também, pois não temos loop em seu código.
	// Todo o código da operação InsertAfter é O(1), menos a chamada de GetNode, que é O(n).
	// GetNode() percorre, em seu pior caso, n nós (lista inteira) para encontrar o nó com tal id.
	// Logo, a operação InsertAfter() também tem complexidade O(n).

	if (IsEmpty(list))
	{
		return false;
	}

	Node* after = GetNode(list, afterId);
	if (after == nullptr)
	{
		return false;
	}

	if (afterId == list->tail->id) Append(list, id, name);
	else
	{
		Node* node = new Node;
		node->id = id;
		node->name = name;

		after->next->previous = node;

		node->next = after->next;

		after->next = node;

		node->previous = after;

		++list->count;
	}
	return true;
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

		list->head->previous = list->tail;

		list->tail->next = list->head;
	}

	toRemove->previous = toRemove->next = nullptr;

	//diminui tamanho da lista
	list->count--;

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
	
	Node* toRemove = list->tail;

	list->tail = list->tail->previous;

	list->tail->next = list->head;

	list->head->previous = list->tail;

	toRemove->previous = toRemove->next = nullptr;

	// diminui tamanho da lista
	list->count--;

	// retorna toRemove
	return toRemove;
}

//RemoveNode(list, value) 
//Remove o nó com valor value da lista list e retorna uma referência para o nó OU erro se a lista estiver vazia.
//
//Pré-condição: A lista list é válida.
//Pós-condição: Remove e retorna o nó com valor value da lista list OU erro se a lista estiver vazia.
Node* RemoveNode(LinkedList* list, int id)
{
	Node* toRemove = GetNode(list, id);

	if (toRemove == list->head)
	{
		return RemoveHead(list);
	}
	else if (toRemove == list->tail)
	{
		return RemoveTail(list);
	}
	else if (toRemove != nullptr)
	{
		toRemove->previous->next = toRemove->next;
		toRemove->next->previous = toRemove->previous;

		--list->count;

		toRemove->previous = toRemove->next = nullptr;
		return toRemove;
	}

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
//Pós-condição: Retorna o nó com valor value da lista list sem removê-lo OU erro se a lista estiver vazia.
Node* GetNode(const LinkedList* list, int id)
{
	// cria nó node que aponta para head
	Node* node = list->head;

	do
	{
		// se node tem valor value
		if (node->id == id)
		{
			// retorna node
			return node;
		}
		// node aponta para node->next
		node = node->next;
	} while (node != list->head);

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

	for (int i = 0; i < Count(list); ++i)
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