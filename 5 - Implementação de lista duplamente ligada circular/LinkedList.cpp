// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gon�alves - TIA: 32074964

#include "LinkedList.h"

//Create() 
//Cria e retorna uma lista vazia.
//
//Pr�-condi��o: N / A.
//P�s-condi��o: Uma nova lista vazia � criada.
LinkedList* Create()
{
	// cria / aloca mem�ria para uma nova lista
	LinkedList* list = new LinkedList;

	// tamanho da lista come�a com zero
	list->count = 0;

	// head come�a com valor nulo
	list->head = nullptr;

	// tail come�a com valor nulo
	list->tail = nullptr;

	// retorna a nova lista
	return list;
}

//Destroy(list) 
//Libera a mem�ria que foi alocada para a lista list.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: A lista list � liberada da mem�ria.
void Destroy(LinkedList* list)
{
	// esvazia a lista(Clear())
	Clear(list);

	// libera mem�ria alocada para a lista
	delete list;
	list = nullptr;
}

//Insert(list, elem) ou AddFront(list, elem)
//Insere um n� com o elemento elem no in�cio da lista list.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: O in�cio da lista cont�m o n� com o elemento elem.
void Insert(LinkedList* list, int id, std::string name)
{
	// cria / aloca novo n� node
	Node* node = new Node;

	// node->id = id
	node->id = id;

	// node->name = name
	node->name = name;

	// se lista estiver vazia
	if (IsEmpty(list))
	{
		// tail aponta para node
		list->tail = list->head = node;
	}

	list->head->previous = node;

	list->tail->next = node;

	// node � o primeiro n� da lista, ent�o node->next aponta para head
	node->next = list->head;

	// atualizar o previous (circular)
	node->previous = list->tail;

	// head aponta para node
	list->head = node;

	// aumenta o tamanho da lista
	list->count++;
}

//Append(list, elem) ou AddBack(list, elem)
//Insere um n� com o elemento elem no final da lista list.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: O final da lista cont�m o n� com o elemento elem.
void Append(LinkedList* list, int id, std::string name)
{
	// cria / aloca novo n� node
	Node* node = new Node;

	// node->id = id
	node->id = id;

	// node->name = name
	node->name = name;

	// node � o �ltimo n� da lista, ent�o node->next aponta para head (circular)
	node->next = list->head;

	node->previous = list->tail;

	// se lista estiver vazia
	if (IsEmpty(list))
	{
		// head e tail apontam para node
		list->head = list->tail = node;
	}
	// sen�o
	else
	{
		// tail.next aponta para node
		list->tail->next = node;

		list->head->previous = node;

		// tail aponta para node
		list->tail = node;
	}

	// aumenta o tamanho da lista
	list->count++;
}

//RemoveHead(list) ou RemoveFront(list)
//Remove o n� do in�cio da lista list e retorna uma refer�ncia para o n� OU erro se a lista estiver vazia.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: Remove e retorna o n� do in�cio da lista list OU erro se a lista estiver vazia.
Node* RemoveHead(LinkedList* list)
{
	if (IsEmpty(list))
	{
		return nullptr;
	}

	//cria n� toRemove que aponta para head
	Node* toRemove = list->head;

	//se existe s� um n� na lista(head � igual � tail)
	if (list->head == list->tail)
	{
		//n�o h� mais n�s na lista(head e tail viram nulo)
		list->head = list->tail = nullptr;
	}
	else //sen�o
	{
		//head agora aponta para o segundo n�(head->next)
		list->head = list->head->next;

		list->head->previous = list->tail;
	}

	toRemove->previous = toRemove->next = nullptr;

	//diminui tamanho da lista
	list->count--;

	//retorna toRemove
	return toRemove;
}

//RemoveTail(list) ou RemoveBack(list)
//Remove o n� do final da lista list e retorna uma refer�ncia para o n� OU erro se a lista estiver vazia.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: Remove e retorna o n� do final da lista list OU erro se a lista estiver vazia.
Node* RemoveTail(LinkedList* list)
{
	// se existe s� um n� na lista
	if (list->head == list->tail)
	{
		// remove e retorna n� usando RemoveHead()
		return RemoveHead(list);
	}
	
	Node* toRemove = list->tail;

	list->tail = list->tail->previous;

	list->tail->next = list->head;

	toRemove->previous = toRemove->next = nullptr;

	// diminui tamanho da lista
	list->count--;

	// retorna toRemove
	return toRemove;
}

//RemoveNode(list, value) 
//Remove o n� com valor value da lista list e retorna uma refer�ncia para o n� OU erro se a lista estiver vazia.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: Remove e retorna o n� com valor value da lista list OU erro se a lista estiver vazia.
Node* RemoveNode(LinkedList* list, int id)
{
	// cria n� toRemove que come�a em head
	Node* toRemove = list->head;

	// cria n� previous que come�a como nulo
	Node* previous = nullptr;

	int cont = 0;

	while (cont < Count(list) && toRemove->id != id)
	{
		// previous aponta para toRemove
		previous = toRemove;

		// toRemove aponta para o pr�ximo n� da lista(toRemove->next)
		toRemove = toRemove->next;

		cont++;
	}

	// se toRemove for head, remove e retorna n� usando RemoveHead()
	if (toRemove == list->head) return RemoveHead(list);

	// se toRemove for tail, remove e retorna n� usando RemoveTail()
	else if (toRemove == list->tail) return RemoveTail(list);

	// se toRemove for diferente de nulo
	else if (toRemove != nullptr)
	{
		toRemove->previous->next = toRemove->next;

		toRemove->next->previous = toRemove->previous;

		toRemove->next = toRemove->previous = nullptr;

		// diminui tamanho da lista
		list->count--;

		// retorna toRemove
		return toRemove;
	}

	// se toRemove for nulo, retorna nulo
	return nullptr;
}

//GetHead(list) ou GetFront(list)
//Retorna uma refer�ncia para o n� do in�cio da lista list OU erro se a lista estiver vazia.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: Retorna o n� do in�cio da lista list sem remov�-lo OU erro se a lista estiver vazia.
Node* GetHead(const LinkedList* list)
{
	// retorna n� head
	return list->head;
}

//GetTail(list) ou GetBack(list)
//Retorna uma refer�ncia para o n� do final da lista list OU erro se a lista estiver vazia.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: Retorna o n� do final da lista list sem remov�-lo OU erro se a lista estiver vazia.
Node* GetTail(const LinkedList* list)
{
	// retorna n� tail
	return list->tail;
}

//GetNode(list, value) 
//Retorna uma refer�ncia para o n� com valor value da lista list OU erro se a lista estiver vazia.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: Retorna o n� com valor value da lista list sem remov�-lo OU erro se a lista estiver vazia.
Node* GetNode(const LinkedList* list, int id)
{
	// cria n� node que aponta para head
	Node* node = list->head;

	for (int i = 0; i < Count(list); ++i)
	{
		// se node tem valor value
		if (node->id == id)
		{
			// retorna node
			return node;
		}
		// node aponta para node->next
		node = node->next;
	}

	// retorna nulo, j� que n� com valor value n�o foi encontrado
	return nullptr;
}

//Count(list) 
//Retorna a quantidade de n�s na lista list.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: N/A.
int Count(const LinkedList* list)
{
	return list->count;
}

//IsEmpty(list) 
//Retorna true se a lista list estiver vazia ou falso, caso contr�rio.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: N/A.
bool IsEmpty(const LinkedList* list)
{
	return list->head == nullptr && list->tail == nullptr;
}

//Clear(list) 
//Esvazia a lista list (remove todos os n�s da lista).
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: A lista list est� vazia.
void Clear(LinkedList* list)
{
	// cria n� node que come�a em head
	Node* node = list->head;

	// cria n� next que come�a como nulo
	Node* next = nullptr;

	for (int i = 0; i < Count(list); ++i)
	{
		// next aponta para node->next
		next = node->next;

		// libera mem�ria alocada para node
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