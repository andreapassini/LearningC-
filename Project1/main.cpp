#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>

typedef struct Result {
	int* ptr;
	int size;
};

template <typename T>
Result funArr(int inputArr[], int size, T t) {
	int* arrTemp;
	arrTemp = (int*)malloc(size * sizeof(inputArr[0]));

	memcpy(arrTemp, inputArr, size * sizeof(inputArr[0]));

	inputArr = (int*)malloc((size + 1) * sizeof(inputArr[0]));

	memcpy(inputArr, arrTemp, size * sizeof(inputArr[0]));

	free(arrTemp);
	arrTemp = nullptr;

	inputArr[size] = t;
	size++;

	Result r;
	r.size = size;
	r.ptr = inputArr;

	return r;
}

template <typename T, typename... Args>
Result funArr(int inputArr[], int size, T t, Args... args) {
	int* arrTemp;
	arrTemp = (int*)malloc(size * sizeof(inputArr[0]));

	memcpy(arrTemp, inputArr, size * sizeof(inputArr[0]));

	inputArr = (int*)malloc((size + 1) * sizeof(inputArr[0]));

	memcpy(inputArr, arrTemp, size * sizeof(inputArr[0]));

	free(arrTemp);
	arrTemp = nullptr;

	inputArr[size] = t;

	size++;

	return funArr(inputArr, size, args...);
}


Result addArr(int* inputArr, int size) {

	for (int i = 0; i < size; i++) {
		int* arrTemp;
		arrTemp = (int*)malloc(i * sizeof(inputArr[0]));

		memcpy(arrTemp, inputArr, i * sizeof(inputArr[0]));

		inputArr = (int*)malloc((i + 1) * sizeof(inputArr[0]));

		memcpy(inputArr, arrTemp, i * sizeof(inputArr[0]));

		free(arrTemp);
		arrTemp = nullptr;

		inputArr[i] = i;
	}

	Result r;
	r.size = size;
	r.ptr = inputArr;

	return r;
}

void Add(int** inArr, int size, int value) {

	std::cout << "Adding: " << value << std::endl; 

	*inArr = (int*)realloc(inArr , (size + 1) * sizeof(int));

	(*inArr)[size] = value;

	for (int i = 0; i < size + 1; i++) {
		std::cout <<"\t\t- " << inArr[i] << std::endl;
	}
}

int main() {  

	std::cout << "args" << std::endl;

	float deltaTime = 0.0f;

	std::cout << "Size: ";
	int size;
	std::cin >> size;


	std::cout << "Iteration: ";
	int iteration;
	std::cin >> iteration;

	for (int j = 0; j < iteration; j++) {
		auto startTime = std::chrono::high_resolution_clock::now();

		int* arr{};

		Result r = funArr(arr, 0, 1, 2, 3, 4, 5, 5, 5);

		auto endTime = std::chrono::high_resolution_clock::now();
		deltaTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
	}

	std::cout << "Dynamic array var-args delta time: " << deltaTime/iteration << " ms" << std::endl << std::endl;


	for (int j = 0; j < iteration; j++) {
		auto startTime = std::chrono::high_resolution_clock::now();

		int* arr{};
		for (int i = 0; i < size; i++) {
			Result r = addArr(arr, i+j);
			arr = r.ptr;
		}


		auto endTime = std::chrono::high_resolution_clock::now();
		deltaTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
	}

	std::cout << "Dynamic array delta time: " << deltaTime / iteration << " ms" << std::endl << std::endl;



	for (int j = 0; j < iteration; j++) {
		auto startTime = std::chrono::high_resolution_clock::now();

		std::vector<int> vec;

		for (int i = 0; i < size; i++) {
			vec.push_back(i + j);
		}

		auto endTime = std::chrono::high_resolution_clock::now();
		deltaTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
	}

	std::cout << "Vector delta time: " << deltaTime / iteration << " ms" << std::endl << std::endl;



	std::ofstream myFileW("ffff.txt");

	myFileW << "writing with stream";

	myFileW.close();


	std::ifstream myFileR("ffff.txt");
	std::string strOut{};
	while (std::getline (myFileR, strOut))
	{	
		std::cout << strOut << std::endl;
	}

	myFileR.close();

	std::flush(myFileW);

	std::remove("ffff.txt");

	if (!std::ifstream("ffff.txt")) {
		std::cout << "error, no such file or directory";
	}

	return 0;
}