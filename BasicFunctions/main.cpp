#include <iostream>

int Add(int a, int b){
    int sum = a+b;

    return sum;
}

int findMin(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}

int findMin(int arr[], int length)
{
    int min = arr[0];

    for (int i = 0; i < length; i++)
    {
        min = findMin(min, arr[i]);
    }

    return min;
}

int main(){

    // Dichiaro e riempio l'array
    int v[10] = {888, 4, 6, 2, 3, 99, 44, 77, 90, 3};
    
    // Trovo la lunghezza dell'array 
    //  (sizeof mi ritorna i byte, quindi devo dividere per la lunghezza del tipo)
    int length = sizeof(v)/sizeof(int);

    // trovo il minore chiamando la funzione
    int min = findMin(v, length);
    
    std::cout << "Min " << min << std::endl;

    return 0;
}