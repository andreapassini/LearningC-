#include <iostream>

int* MultiplyArrays(int* inArr1, int sizeInArr1, int* inArr2, int sizeInArr2) {

	int* outArr = (int*)calloc(sizeInArr1 * sizeInArr2, sizeof(int));

	for (int i = 0; i < sizeInArr1; i++) {
		for (int j = 0; j < sizeInArr2; j++) {
			outArr[(i * sizeInArr2) + j] = inArr1[i] * inArr2[j];
		}
	}

	return outArr;
}

void PrintArray(const int* const arrayToPrint, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arrayToPrint[i] << std::endl;
	}
}

int main() {

	int a[5]{ 1, 2, 3, 4, 5 };
	int b[2]{ 10, 20 };

	int* res = MultiplyArrays(a, 5, b, 2);

	PrintArray(res, (5 * 2));

	delete[] res;

	std::cout << "Second section " << std::endl << std::endl;

	int* data = new int[5];

	for (int i = 0; i < 5; i++)
		*(data + i) = i * 2;

	for (int i = 0; i <= 4; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;

	delete[] data;
}