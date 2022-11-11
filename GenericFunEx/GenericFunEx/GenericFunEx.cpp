#include <iostream>
using namespace std;

// Generics using template
template<typename  T>
// You can also use instead of "typename" - "class"
// & => Passing by reference
void Swap (T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int main(int argc, char* argv[])
{
    int a = 5, b = 7;

    cout << a << " - " << b << endl;
    Swap<int>(a, b);
    cout << a << " - " << b << endl;

    char c = 'c', d = 'd';
    cout << c << " - " << d << endl;
    Swap<char>(c, d);
    cout << c << " - " << d << endl;
    
    return 0;
}
