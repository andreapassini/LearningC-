#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int hostUserNum, guestUserNum;
    cout << "Host: ";
    cin >> hostUserNum;

    system("cls");
    
    cout << "Guest :";
    cin >> guestUserNum;

    // Ternary Op
    (hostUserNum == guestUserNum)? cout << "Correct!" << endl
        : cout << "Failed" << endl;
    
    return 0;
}
