#include <iostream>
using namespace std;

int getMin(int numbers[], int size)
{
    int min = numbers[0];

    for(int i = 1; i < size; i++)
    {
        if(numbers[i] < min)
            min = numbers[i];
    }

    return min;
}
int getMax(int numbers[], int size)
{
    int max = numbers[0];

    for(int i = 1; i < size; i++)
    {
        if(numbers[i] > max)
            max = numbers[i];
    }

    return max;
}
void getMinMax(int numbers[], int size, int* min, int* max)
{
    *min = getMin(numbers, size);

    *max = getMax(numbers, size);
}

int main(int argc, char* argv[])
{
    int numbers[5] = {5, 4, -2, 29, 6};

    int min = numbers[0];
    int max = numbers[0];

    getMinMax(numbers, 5, &min, &max);

    cout << "MIN: " << min << endl;
    cout << "MAX: " << max << endl;

    
    return 0;
}
