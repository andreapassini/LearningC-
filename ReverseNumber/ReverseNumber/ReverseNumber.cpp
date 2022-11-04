#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "Insert a Number to be Reversed" << endl;
    int num, reverseNum = 0;
    cin >> num;

    if(num < 0)
    {
        num /= -1;
    }
    
    while (num > 0)
    {
        reverseNum *= 10;
        reverseNum += num % 10;
        num /= 10;
    }
    
    cout << "Reverse Num" << endl << reverseNum;
    
    return 0;
}
