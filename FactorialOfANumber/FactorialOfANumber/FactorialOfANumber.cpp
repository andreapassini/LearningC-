#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    // Fac of a number

    cout << "Insert a number" << endl;
    int num, result = 1;
    cin >> num;

    for(int i=1; i <= num; i++)
    {
        result *= i;
    }

    cout << "Factorial of " << num << " is: " << result;
    
    return 0;
}
