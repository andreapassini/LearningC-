#include <iostream>



int Square(int& n) {
	return n * n;
}

int main() {
	int num = 10;

	Square(num);
	Square(10);	// can't refernce an R-Value

	int x;
	x1 = 100;		// 100 R-Value
	(100 + 20) = x1; // (100+20) R-Value (compile Err)

	std::string name{ "Andrea" };	// "Andrea" R-Value
	"Frank" = name;					// "Frank" R-Value (compile Err)

	int max_num = std::max(10, 20);	// std::max(10, 20) R-Value 

	int y = 0;
	int x = 19;

	y = 100;	// R-Value 100 assigned to L-Value y
	x = x + y;	// R-Value (x+y) assigned to L-Value x

	int a = 100;

	int& ref1 = x;	// ref1 is a ref to L-Value
	ref1 = 1000;

	int& ref2 = 100; // err, 100 is an R-Value
}
