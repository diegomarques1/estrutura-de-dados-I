// GRUPO:
// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#ifndef __NODE_H__
#define __NODE_H__

class Node
{
public:
	Node();
	Node(float data, Node* next);
	~Node();

	float GetData() const;
	void SetData(float data);

	Node* GetNext() const;
	void SetNext(Node* next);

private:
	float m_Data;
	Node* m_Next;
};

#endif // __NODE_H__