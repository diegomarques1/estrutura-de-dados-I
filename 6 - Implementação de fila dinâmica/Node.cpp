#include "Node.h"

Node::Node()
	: m_Data('\0')
	, m_Next(nullptr)
{
}

Node::Node(char data, Node* next)
	: m_Data(data)
	, m_Next(next)
{
}

Node::~Node()
{
	m_Next = nullptr;
}

char Node::GetData() const
{
	return m_Data;
}

void Node::SetData(char data)
{
	m_Data = data;
}

Node* Node::GetNext() const
{
	return m_Next;
}

void Node::SetNext(Node* next)
{
	m_Next = next;
}