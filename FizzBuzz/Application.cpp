#include <iostream>
#include <string>

typedef struct FizzStruct {
	int number;
	std::string phrase;
};

int main() {

	int arraySize = 0;
	std::cout << "Insert the size of the dynamiccaly stack allcoated array" << std::endl;
	std::cin >> arraySize;

	FizzStruct* fizzStruct = (FizzStruct*)alloca(sizeof(FizzStruct) * arraySize);

	fizzStruct[0].number = 3;
	fizzStruct[0].phrase = "Fizz";
	fizzStruct[1].number = 5;
	fizzStruct[1].phrase = "Buzz";

	std::string output = "";

	for (unsigned int i = 1; i <= 100; i++) {
		output = "";

		for (int j = 0; j < 10; j++) {
			if (i % fizzStruct[j].number == 0)
				output.append(fizzStruct[j].phrase);
		}

		if (output.length() == 0)
			output.append( std::to_string(i) );

		std::cout << output << std::endl;
	}

	std::cin.get();
	return 0;
}