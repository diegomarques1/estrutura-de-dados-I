// GRUPO:
// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include "Stack.h"
#include <sstream>

Stack::Stack()
	: m_List(new LinkedList)
{
}

Stack::~Stack()
{
	delete m_List;
}

void Stack::Push(float elem)
{
	m_List->Append(elem);
}

float Stack::Pop()
{
	Node* temp = m_List->RemoveTail();
	if (temp == nullptr)
	{
		return -1;
	}

	float value = temp->GetData();
	delete temp;
	return value;
}

float Stack::Top() const
{
	Node* temp = m_List->GetTail();
	if (temp == nullptr)
	{
		return -1;
	}

	return temp->GetData();
}

int Stack::Count() const
{
	return m_List->Count();
}

bool Stack::IsEmpty() const
{
	return m_List->IsEmpty();
}

bool Stack::Clear()
{
	m_List->Clear();

	return IsEmpty();
}

std::string Stack::ToString() const
{
	std::ostringstream oss;

	for (Node* node = m_List->GetHead(); node != nullptr; node = node->GetNext())
	{
		oss << node->GetData() << ' ';
	}

	return oss.str();
}