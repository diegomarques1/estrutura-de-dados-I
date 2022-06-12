// GRUPO:
// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include "Node.h"

Node::Node()
	: m_Data('\0')
	, m_Next(nullptr)
{
}

Node::Node(float data, Node* next)
	: m_Data(data)
	, m_Next(next)
{
}

Node::~Node()
{
	m_Next = nullptr;
}

float Node::GetData() const
{
	return m_Data;
}

void Node::SetData(float data)
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