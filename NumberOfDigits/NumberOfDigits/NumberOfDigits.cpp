#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    // Count the number of digits

    cout << "Insert Number to get digits counted" << endl;
    int num;
    cin >> num;

    // If neg, make it pos
    if(num < 0)
    {
        num *= -1;
    }

    int i = 0;

    // Count the digits by div by 10
    while (num > 0)
    {
        num /= 10;
        i++;
    }

    // Number is 0
    if (i == 0)
    {
        cout << "You have entered 0";
    }
    else
    {
        cout << "Digits: " << i << endl;
    }


    return 0;
}
