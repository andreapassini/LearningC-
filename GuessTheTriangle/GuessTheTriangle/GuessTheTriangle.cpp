#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    // User in 3 lenght of the triangle
    // Guess if it is equilateral, isosceles or scalene;

    int a, b, c;
    
    cout << "Insert 3 lenght of the Triangle" << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    if(a == b && b == c)
    {
        cout << "Equilateral";
    }
    else if( a == b || a == c || b == a || b == c )
    {
        cout << "Isosceles";
    } else
    {
        cout << "Scalene";
    }
    
    return 0;
}
