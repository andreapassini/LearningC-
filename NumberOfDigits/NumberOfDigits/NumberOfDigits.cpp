#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    // Count the number of digits

    cout << "Insert Number to get digits counted" << endl;
    int num;
    cin >> num;

    int i = 0;

    while (num > 0)
    {
        num /= 10;
        i++;
    }

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
