#include <iostream>
using namespace std;

// Sum up number between a and b
int Sum(int a, int b)
{
    if (a == b)
        return a;

    return a + Sum(a + 1, b);
}

int RecFactorial(int a)
{
    if( a == 1)
        return a;

    return a * RecFactorial(a - 1);
}

int main(int argc, char* argv[])
{
    int res = RecFactorial(100);
    cout << res;

    return 0;
}
