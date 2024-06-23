#include <iostream>

void PrintA(int valueToPrint)
{
	std::cout << "Value: " << valueToPrint << std::endl;
	std::cout << "Ref: " << &valueToPrint << std::endl;
	std::cout << std::endl;
}

void Multi(int valueToPrint)
{
	valueToPrint *= 2;
	PrintA(valueToPrint);
}

// On ptr
void PrintAPtr(int* valueToPrint)
{
	std::cout << "Value: " << *valueToPrint << std::endl;
	std::cout << "Ref: " << valueToPrint << std::endl;
	std::cout << std::endl;
}

void MultiPtr(int* ptrVar)
{
	(*ptrVar) *= 2;
	PrintAPtr(ptrVar);
}


struct MyStruct
{
	int a;
	int b;
	int c;
	int d;

	bool myBool;
	int MyArr[5];
};

struct Node
{
	int color = -1;
	Node* next = nullptr;
};

class List
{
public:
	int dim = 0;
	void AddNode(Node* node)
	{

	}
	void PrintList()
	{

	}
private:
	Node* root = nullptr;
};



int main()
{
	{
		//int a = 5;

		//Multi(a);

		//MultiPtr(&a);

		//std::cout << "Ref: " << &a << std::endl;
		//std::cout << "Value: " << a << std::endl;
	}

	List myList;

	Node myNode1;
	//myList.root = &myNode1;
	myList.AddNode(&myNode1);

	Node myNode2;
	//myNode1.next = &myNode2;
	myList.AddNode(&myNode2);

	//int array[5] = { 1, 2, 3, 4, 5 };
	//array[2] = 7'000;

	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << "Arr[" << i << "] : " << array[i] << std::endl;
	//}

	//std::cout << std::endl;

	//std::cout << "Arr " << array << std::endl;

	//std::cout << std::endl;

	//2[array] = 8'000;

	//std::cout << std::endl;

	//std::cout << "2[array] " << &2[array] << std::endl;

	//std::cout << std::endl;

	//std::cout << std::endl;

	//std::cout << "&Arr[6]" << &array[6] << std::endl;
	//std::cout << "Arr[6]" << array[6] << std::endl;

	//std::cout << std::endl;

	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << "Arr[" << i << "] : " << array[i] << std::endl;
	//}

	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << "&Arr[" << i << "] : " << &array[i] << std::endl;
	//}

	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(bool) << std::endl;
	std::cout << sizeof(float) << std::endl;

	bool arrayBool[5];
	for (int i = 0; i < 5; i++)
	{
		std::cout << "&Arr[" << i << "] : " << &arrayBool[i] << std::endl;
	}


	std::cout << " " << INT32_MAX << std::endl;

}