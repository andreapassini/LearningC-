#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

int PrimeNumbersClassic(int maxValue)
{
    // Output the first 1000 numbers

    // Starting Time
    auto start = high_resolution_clock::now();
    
    for(int i =0; i < maxValue; i++)
    {
        bool isPrime = true;
        for(int j = 2; j < i; j++)
        {
            if(i%j == 0)
            {
                isPrime = false;
                j = i+1; // To exit the for loop
            }
        }

        if(isPrime)
        {
            cout << i << " is Prime" << endl;
        }
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop-start);

    // To get the value of duration use the count()
    // member function on the duration object
    //cout << duration.count() << endl;

    return duration.count();
}

void InitArray(int array[], int lenght)
{
    for (int k = 0; k < lenght; k++)
    {
        array[k] = -1;
    }
}

int LastIndexOfContent(int array[], int length, int empty)
{
    int lastIndex = 0;
    
    for(int k = 0; k < length; k++)
    {
        if(array[k] == empty)
        {
            lastIndex = k;
            return lastIndex - 1;
        }
    }
    
    return length;
}

int PrimeNumberOptimized(int maxValue)
{
    // Output the first 100'000'000 numbers
    int* primes = new int[maxValue];
    InitArray(primes, maxValue);

    // Starting Time
    auto start = high_resolution_clock::now();

    for(int i = 2; i < maxValue; i++)
    {
        bool isPrime = true;
        for(int j = 0; i/primes[j] > sqrt(i) && isPrime; j++)
        {
            if(i % primes[j] == 0)
            {
                isPrime = false;
            }
        }

        if(isPrime)
        {
            // We can add them into an array and then test with it
            primes[LastIndexOfContent(primes, maxValue, -1) + 1] = i;

            cout << i << " is Prime" << endl;
        }
        
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop-start);

    // To get the value of duration use the count()
    // member function on the duration object
    return duration.count();
}

int main(int argc, char* argv[])
{
    
    cout << PrimeNumberOptimized(1'000);
    
    return 0;
}
