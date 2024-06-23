#include <iostream>

struct Node
{
	int Index = -1;
	Node* Child = nullptr;
};

class List
{
public:
	Node* m_RootNode = nullptr;
	int m_Size = 0;
public:
	void AddNode(Node* nodeToAdd)
	{
		Node* lastNode = nullptr;

		nodeToAdd->Index = m_Size;
		m_Size++;

		if (!m_RootNode)
		{
			m_RootNode = nodeToAdd;
			return;
		}
		
		lastNode = m_RootNode;

		while (lastNode->Child)
		{
			lastNode = lastNode->Child;
		}

		lastNode->Child = nodeToAdd;
	}
	void Print() const
	{
		Node* lastNode = m_RootNode;
		while (lastNode)
		{
			std::cout << " - " << lastNode->Index << std::endl;
			lastNode = lastNode->Child;
		}
	}
};

int main()
{
	List list;
	Node node1;
	list.AddNode(&node1);
	std::cout << list.m_RootNode->Index << std::endl;
	Node node2;
	list.AddNode(&node2);
	Node node3;
	list.AddNode(&node3);

	list.Print();
}