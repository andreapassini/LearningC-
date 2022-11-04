#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    // Write all numbers between 100-500
    // divisible by 3 and 5

    for(int i = 100; i <= 500; i++)
    {
        if(i % 5 == 0 && i % 3 == 0)
        {
            cout << i << endl;
        }
    }

    cout << "End";
    
    return 0;
}
