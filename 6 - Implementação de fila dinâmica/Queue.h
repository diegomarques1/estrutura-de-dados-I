#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "LinkedList.h"
#include <string>

class Queue
{
public:
	Queue();
	~Queue();

	void Enqueue(char value);
	char Dequeue();
	char Front() const;

	int Count() const;
	bool IsEmpty() const;
	bool Clear();

	std::string ToString() const;

private:
	LinkedList* m_List;
};

#endif // __QUEUE_H__