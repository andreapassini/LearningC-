#include <iostream>

// Es 2 del 14/03
//	scrivere una funzione che, dati due numeri, ne scambi il valore
//

void Scambia(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a, b;

	std::cout << "Inserisci il primo numero " << std::endl;
	std::cin >> a;
	std::cout << "Inserisci il secondo numero " << std::endl;
	std::cin >> b;

	// TODO
	Scambia(&a, &b);

	std::cout << "Primo numero è: " << a << std::endl;
	std::cout << "Secondo numero è: " << b << std::endl;

	// block execution before ternimating
	std::cin.get();
}