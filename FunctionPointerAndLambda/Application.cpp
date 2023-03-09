#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void PrintValue(int value) 
{
	std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int)) 
{
	for (int value : values)
		func(value);
}

void HelloWorld() 
{
	std::cout << "Hello World! from auto" << std::endl;
}

void HelloWorldFun()
{
	std::cout << "Hello World! from typedef " << std::endl;
}

void HelloWorldFun(int a ) 
{
	std::cout << "Hello World! from typedef " << a << std::endl;
}

void ForEachWithLambda(const std::vector<int>& values,
	const std::function<void(int)>& func) {
	for (int value : values)
		func(value);
}

int main(int argc, char* argv[]) 
{
	std::vector<int> values = { 1, 2, 3, 4, 5, 6 };
	ForEach(values, PrintValue);
	std::cout << std::endl;

	auto function = HelloWorld;
	function();
	function();
	function();
	std::cout << std::endl;


	void(*funfun)() = HelloWorldFun;
	funfun();
	funfun();
	funfun();
	std::cout << std::endl;

	typedef void(*HelloWorldFunction)(int);

	HelloWorldFunction functionHelloWorld = HelloWorldFun;

	functionHelloWorld(1);
	functionHelloWorld(2);
	functionHelloWorld(3);
	functionHelloWorld(4);
	std::cout << std::endl;

	// Function pointers and labda
	ForEach(values, [](int value) 
		{
			std::cout << "Value: " << value << std::endl;
		}
	);
	std::cout << std::endl;

	// Function Pointers and Lambda 
	// [=] allow us to use global values passed by value/copy
	// find_if, stop at the first element that makes true the lambda
	auto it = std::find_if(values.begin(), values.end(), [](int value) {
		return value > 3;
		});
	std::cout << *it << std::endl;
	std::cout << std::endl;

	int a = 5;

	auto lambda = [=](int value) {std::cout << "Value: " << a << std::endl; };

	ForEachWithLambda(values, lambda);
	std::cout << std::endl;
-

	std::cin.get();
}