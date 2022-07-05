#include <iostream>



// FUnzione che trovi un elemento dentro ad un array tornandone l'indice

int TrovaNumero(int a, int A[10]) {
	int i = 0;

	while (A[i] != a)
	{
		i = i + 1;
	}
	return i;
}

int main() {
	int a = -1;
	int Numero1;
	int Numero2;

	int A[10];
	A[0] = 0;
	A[1] = 0;
	A[2] = 0;
	A[3] = 0;
	A[4] = 0;
	A[5] = 0;
	A[6] = 0;
	A[7] = 0;
	A[8] = 0;
	A[9] = 0;

	while (a != 0)
	{

		std::cout << "digitare 1 per inserire un numero, \n digitare 2 per eliminare un numero, \n digitare 3 per visualizzare la rubrica, \n digitare 0 per annullare" << std::endl;
		std::cin >> a;

		if (a == 1)
		{
			int i = 0;

			std::cout << "digitare un numero" << std::endl;
			std::cin >> Numero1;
			int index = TrovaNumero(0, A);
			/*while (A[i] != 0)
			{
				i = i + 1;
			}*/
			A[index] = Numero1;
			std::cout << "numero inserito" << std::endl;
		}

		if (a == 2)
		{
			int i = 0;

			std::cout << "digitare un numero" << std::endl;
			std::cin >> Numero2;
			int index = TrovaNumero(Numero2, A);
			/*while (A[i] != Numero2)
			{
				i = i + 1;
			}*/
			A[index] = 0;
			std:: cout << "numero eliminato";
		}

		if (a == 3)
		{
			int i = 0;

			do
			{
				std::cout << A[i] << std::endl;
				i = i + 1;

			} while (i < 10);

		}
	}

	 
}


