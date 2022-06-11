#ifndef __NODE_H__
#define __NODE_H__

class Node
{
public:
	Node();
	Node(char data, Node* next);
	~Node();

	char GetData() const;
	void SetData(char data);

	Node* GetNext() const;
	void SetNext(Node* next);

private:
	char m_Data;
	Node* m_Next;
};

#endif // __NODE_H__