// GRUPO:
// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#ifndef __STACK_H__
#define __STACK_H__

#include "LinkedList.h"
#include <string>

class Stack
{
public:
	Stack();
	~Stack();

	void Push(float value);
	float Pop();
	float Top() const;
	int Count() const;
	bool IsEmpty() const;
	bool Clear();

	std::string ToString() const;

private:
	LinkedList* m_List;
};

#endif // __STACK_H__
