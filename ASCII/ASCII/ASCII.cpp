#include <iostream>
#include <ostream>
using namespace std;

int main(int argc, char* argv[])
{
    // Output the ascii number of the letter
    // cout << (int)'a' << endl;
    // cout << int('a') << endl;
    //
    // cout << int('A') << endl;
    //
    // cout << (char)65 << endl;

    char c1, c2, c3, c4, c5;
    cout << "Enter 5 letters" << endl;
    cin >> c1 >> c2 >> c3 >> c4 >> c5;

    cout << "ASCII mes " << (int)c1 << " " << (int)c2 << " " << (int)c3 << " " << (int)c4 << " " << (int)c5;
    
    return 0;
}
