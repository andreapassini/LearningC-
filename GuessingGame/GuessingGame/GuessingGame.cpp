#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int hostUserNum, guestUserNum;
    cout << "Host: ";
    cin >> hostUserNum;

    system("cls");

    int max = 2;

    for(int i = 0; i <= max; i++)
    {
        cout << "Guest (" << i + 1 << " out of " << max + 1 << " ) :";
        cin >> guestUserNum;

        // Ternary Op
        if (hostUserNum == guestUserNum)
        {
            cout << "Correct!" << endl;
            i = max + 1;
        }
        else
            cout << "Failed" << endl;
    }

    
    return 0;
}
