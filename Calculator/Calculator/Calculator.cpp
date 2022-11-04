#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    float num1, num2;
    char operation;

    cout << "Calculator" << endl;
    cin >> num1 >> operation >> num2;

    // SwitchCase Statement
    switch (operation)
    {
    case '-':
        cout << num1 << operation << num2 << " = "
            << num1 - num2;
        break;
    case '+':
        cout << num1 << operation << num2 << " = "
            << num1 + num2;
        break;
    case '*':
        cout << num1 << operation << num2 << " = "
            << num1 * num2;
        break;
    case '/':
        cout << num1 << operation << num2 << " = "
            << num1 / num2;
        break;
    case "%":
        // Check Int or float
        bool isNum1Int, isNum2Int;
        ((int)num1==num1)? isNum1Int = true: isNum1Int = false;
        ((int)num2==num2)? isNum2Int = true: isNum2Int = false;

        if(isNum1Int && isNum2Int)
        {
            cout << num1 << operation << num2 << " = "
            << (int)num1 % (int)num2;
            break;
        }
    }

    return 0;
}
