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
	void AddNode()
	{
		Node nodeToAdd;
		Node* lastNode = nullptr;

		nodeToAdd.Index = m_Size;
		m_Size++;

		if (!m_RootNode)
		{
			m_RootNode = &nodeToAdd;
			return;
		}

		lastNode = m_RootNode;

		while (lastNode->Child)
		{
			lastNode = lastNode->Child;
		}

		lastNode->Child = &nodeToAdd;
	}
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
			std::cout << "Node: " << lastNode->Index << "\n\tnext: " << lastNode->Child << std::endl;
			lastNode = lastNode->Child;
		}

		std::cout << std::endl;
	}
};

void PrintArray(int* array, int size)
{
	std::cout << "Array: " << array << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << std::endl;
	}
	std::cout << std::endl;
}


int main()
{
	int size = 20;

	int* heapArray = new int[size];
	int* heapArray = (int*)malloc(size * sizeof(int));
	int* heapArray = (int*)calloc(size, sizeof(int));
}

int main()
{
	//List list;

	//Node node1;
	//list.AddNode(&node1);

	//list.AddNode();

	//{
	//	Node node;
	//	list.AddNode(&node);
	//}

	//{
	//	Node node;
	//	list.AddNode(&node);
	//}

	//list.Print();

	//int stackArray[20];
	//PrintArray(stackArray, 20);

	//int size = 15;
	//int* heapArray = new int[size];

	//// memset
	//memset(heapArray, 0, sizeof(int) * size);
	//PrintArray(heapArray, size);

	//// memcpy
	//int* heapArray2 = new int[size];
	//memcpy(heapArray2, heapArray, sizeof(int) * size);
	//PrintArray(heapArray2, size);

	std::cout << "end" << std::endl;
}