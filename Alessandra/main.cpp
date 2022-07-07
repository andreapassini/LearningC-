#include <iostream>

int main() {
	int a;
	int i = 0;
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

	while (a == 0)
	{
		std::cin >> a;

		if (a == 1)
		{
			std::cin >> Numero1;
			while (A[i] == 0)
			{
				i = i + 1;
			}
			A[i] = Numero1;
		}

		if (a == 2)
		{
			std::cin >> Numero2;
			while (A[i] == Numero2)
			{
				i = i + 1;
			}
			A[i] = 0;

		}

		if (a == 3)
		{
			do
			{
				std::cout << A[i];
				i = i + 1;

			} while (i < 10)

		}
	}


}