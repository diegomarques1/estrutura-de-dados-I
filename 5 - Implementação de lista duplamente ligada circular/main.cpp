// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

// main.cpp
// TODO: Inserir sua identificação aqui.
#include <iostream>
#include <clocale>
#include "LinkedList.h"

using namespace std;

void Print(const LinkedList* list)
{
	// TODO: Implementar:
	// Percorre todos os nós da lista e imprime os valores de cada nó.
	Node* node = list->head;
	for (int i = 0; i < Count(list); ++i)
	{
		cout << "[" << node->id << "] " << node->name << '\n';
		node = node->next;
	}
	cout << '\n';
}

void PrintReverse(const LinkedList* list)
{
	// TODO: Implementar:
	// Percorre todos os nós da lista em ordem inversa e imprime as informações de cada nó.
	Node* node = list->tail;
	for (int i = 0; i < Count(list); ++i)
	{
		cout << "[" << node->id << "] " << node->name << '\n';
		node = node->previous;
	}
	cout << '\n';
}

void PrintDoubleListInfo(const LinkedList* list)
{
	if (IsEmpty(list))
	{
		cout << "Lista vazia!\n";
	}
	else
	{
		cout << "Lista:\n";
		Print(list);
		cout << "Lista invertida:\n";
		PrintReverse(list);
	}
}

int main()
{
	setlocale(LC_ALL, "pt_BR.UTF-8"); // alteramos aqui pois não estava funcionando com o pt_BR apenas
	cout << "*** Lista Circular Duplamente Ligada/Encadeada (Doubly Circular Linked List)*** \n";

	LinkedList * list = Create();
	PrintDoubleListInfo(list);

	Insert(list, 1, "Carol");
	Insert(list, 2, "Eric");
	Insert(list, 3, "John");
	Append(list, 4, "Leo");
	Append(list, 5, "Julia");
	Append(list, 6, "Lisa");

	PrintDoubleListInfo(list);
	Clear(list);

	PrintDoubleListInfo(list);
	Insert(list, 11, "Paulo");
	Append(list, 22, "Thomas");
	Insert(list, 33, "Olga");
	Append(list, 44, "Bia");
	Insert(list, 55, "Angela");
	Append(list, 66, "Karen");
	Insert(list, 77, "Adauto");
	PrintDoubleListInfo(list);

	Node* temp = RemoveNode(list, 44);
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	delete temp;
	PrintDoubleListInfo(list);

	temp = RemoveHead(list);
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	delete temp;
	PrintDoubleListInfo(list);

	temp = RemoveTail(list);
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	delete temp;
	PrintDoubleListInfo(list);

	Destroy(list);

	cout << "Fim.\n";
}