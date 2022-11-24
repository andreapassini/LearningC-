#include <iostream>
using namespace std;

int somma(int a, int b)
{
    int ris;
    ris=a+b;
    return ris;
}

void scambia(int* a, int* b)
{
    int s;
    s=*a;
    *a=*b;
    *b=s;
}

int main(int argc, char* argv[])
{
    int x=5, y=6;

    scambia(&x, &y);
    
    cout << x << " " << y;
    
    return 0;
}
