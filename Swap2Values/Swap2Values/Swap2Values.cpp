#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int a = 6, b = 8;
    cout << a << " " << b << endl;
    
    // With 3 values
    int c = 0;
    c = a;
    a = b;
    b = c;

    cout << a << " " << b << endl;

    system("cls");

    a = 6;
    b = 8;
    cout << a << " " << b << endl;

    a += b;
    b = a - b;
    a = a - b;

    cout << a << " " << b << endl;
    
    return 0;
}
