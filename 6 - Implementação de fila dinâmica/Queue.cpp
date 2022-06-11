#include "Queue.h"
#include <sstream>

Queue::Queue()
	: m_List(new LinkedList)
{
}

Queue::~Queue()
{
	delete m_List;
}

void Queue::Enqueue(char value)
{
	m_List->Append(value);
}

char Queue::Dequeue()
{
	Node* temp = m_List->RemoveHead();
	if (temp == nullptr)
	{
		return '\0';
	}

	char value = temp->GetData();
	delete temp;
	return value;
}

char Queue::Front() const
{
	Node* temp = m_List->GetHead();
	if (temp == nullptr)
	{
		return '\0';
	}

	return temp->GetData();
}

int Queue::Count() const
{
	return m_List->Count();
}

bool Queue::IsEmpty() const
{
	return m_List->IsEmpty();
}

bool Queue::Clear()
{
	m_List->Clear();

	return IsEmpty();
}

std::string Queue::ToString() const
{
	std::ostringstream oss;

	for (Node* node = m_List->GetHead(); node != nullptr; node = node->GetNext())
	{
		oss << node->GetData() << ' ';
	}

	return oss.str();
}
