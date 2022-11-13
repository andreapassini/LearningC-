#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int n = 5;
    cout << &n << endl;

    int* ptr = &n;
    // Print the address of the cell
    cout << ptr << endl;
    // Print the value of that cell
    cout << *ptr << endl;

    *ptr = 10;
    cout << *ptr << endl;
    cout << n << endl;

    int v;
    int* prt2 = &v;
    *prt2 = 7;
    cout << prt2 << " = " << *prt2 << endl;

    system("pause>0");
    return 0;
}
