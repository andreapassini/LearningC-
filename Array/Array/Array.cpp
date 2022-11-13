#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int luckyNumbers[5];
    // cout << luckyNumbers << endl;
    // cout << &luckyNumbers[0] << endl;
    // //[] Dereference the pointer as *
    // cout << luckyNumbers[2] << endl; 
    // cout << *(luckyNumbers+2) << endl;

    for(int i = 0; i < 5; i++)
    {
        cout << "Number: ";
        cin >> luckyNumbers[i];
    }

    for(int i = 0; i < 6; i++)
    {
        cout << *(luckyNumbers + i) << endl;
        // 6th is someone else memory 
    }
    
    return 0;
}
