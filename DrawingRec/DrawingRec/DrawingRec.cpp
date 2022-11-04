#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "Enter Width of the Rectangle" << endl;
    int width, height;
    cin >> width;
    cout << "Enter Width of the Rectangle" << endl;
    cin >> height;
    cout << "Enter symbol of Rectangle" << endl;
    char symbol;
    cin >> symbol;

    // Line
    for (int i = 0; i < height; i++)
    {
        // Column
        for (int j = 0; j < width; j++)
        {
            cout << " " << symbol << " ";
        }
        cout << endl;
    }

    return 0;
}
