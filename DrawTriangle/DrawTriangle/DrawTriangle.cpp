#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
    // Draw a Rec Triangle
    int base, height;
    // cout << "Set Base of the triangle" << endl;
    // cin >> base;
    cout << "Set Height of the triangle" << endl;
    cin >> height;

    char symbol = '*';

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << setw(3) << symbol;
        }

        cout << endl;
    }

    cout << endl;
    
    for(int i = 0; i < height; i++)
    {
        for (int j = height - i; j > 0; j--)
        {
            cout << setw(3) << symbol;
        }

        cout << endl;
    }
    
    return 0;
}
