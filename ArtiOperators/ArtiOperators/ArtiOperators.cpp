#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int counter = 0;
    counter += 6;

    cout << "Counter" << endl;
    cout << counter++ << endl;

    system("cls"); // Clean console

    int a = 5, b = 5;
    cout << "Condition" << endl;
    cout << (a != b); // 1 if Diff, 0 otherwise
    
    return 0;
}
