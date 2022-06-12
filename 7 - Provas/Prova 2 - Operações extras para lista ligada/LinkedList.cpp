// Diego Souza Lima Marques - TIA: 32039921

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
// Cria um n� contendo id(n�mero inteiro) e name(string) e insere o novo n� antes do n� que cont�m o id beforeId, exceto:
// - Se a fila estiver vazia, n�o insere o novo n� na lista e retorna false.
// - Se n�o existe um n� na lista com o id beforeId, n�o insere o novo n� na lista e retorna false.
//
// Pr�-condi��o: A lista ligada / encadeada list � v�lida.
// P�s-condi��o: Se foi poss�vel inserir o novo n� na lista, a lista deve conter o novo n�, na posi��o correta,
// e a fun��o retorna true (�n� inserido na lista�).
// Caso contr�rio, a fun��o retorna false (�n�o foi poss�vel inserir n� na lista�), sem inserir o novo n� na lista
bool InsertBefore(LinkedList* list, int beforeId, int id, std::string name)
{
	// Complexidade do algoritmo: O(n)
	// Todo o conte�do de if/else � O(1). A chamada de fun��o IsEmpty() tamb�m � O(1).
	// Insert() tamb�m � O(1), j� que n�o temos qualquer loop dentro.
	// Por�m, a chamada da fun��o GetNode() � O(n), por causa da exist�ncia do loop do-while em sua implementa��o.
	// Esta opera��o � O(n) porque percorre, em seu pior caso, toda a lista (n n�s) para encontrar o n� com tal id (beforeId).
	// Portanto, a opera��o InsertBefore tem complexidade O(n).

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
//Insere um n� com o elemento elem no final da lista list.
//
//Pr�-condi��o: A lista list � v�lida.
//P�s-condi��o: O final da lista cont�m o n� com o elemento elem.
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
//Cria um n� contendo id(n�mero inteiro) e name(string) e insere o novo n� depois do n� que cont�m o id afterId, exceto:
// - Se a fila estiver vazia, n�o insere o novo n� na lista e retorna false.
// - Se n�o existe um n� na lista com o id afterId, n�o insere o novo n� na lista e retorna false.
//
// Pr�-condi��o: A lista ligada / encadeada list � v�lida.
// P�s-condi��o: Se foi poss�vel inserir o novo n� na lista, a lista deve conter o novo n�, na posi��o correta,
// e a fun��o retorna true (�n� inserido na lista�).
// Caso contr�rio, a fun��o retorna false (�n�o foi poss�vel inserir n� na lista�), sem inserir o novo n� na lista
bool InsertAfter(LinkedList* list, int afterId, int id, std::string name)
{
	// Complexidade do algoritmo: O(n)
	// Chamadas de if/else s�o todas O(1). IsEmpty() tamb�m � O(1). 
	// Append() � O(1) tamb�m, pois n�o temos loop em seu c�digo.
	// Todo o c�digo da opera��o InsertAfter � O(1), menos a chamada de GetNode, que � O(n).
	// GetNode() percorre, em seu pior caso, n n�s (lista inteira) para encontrar o n� com tal id.
	// Logo, a opera��o InsertAfter() tamb�m tem complexidade O(n).

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

		list->tail->next = list->head;
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

	list->head->previous = list->tail;

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