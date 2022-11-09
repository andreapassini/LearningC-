#include <iostream>
using namespace std;

int money = 10000;

int showMenu()
{
    cout << "\n MENU " << endl;
    cout << "1 - Check balance" << endl;
    cout << "2 - Withdraw" << endl;
    cout << "3 - Deposit" << endl;
    cout << "0 - Terminate" << endl;
    int choice = 0;

    cin >> choice;

    return choice;
}

void CheckBalance()
{
    cout << "Your balance is: " << money;
}

void Withdraw(int amount)
{
    if (amount >= money)
    {
        cout << "Withdraw not possible" << endl;
        cout << "Your balance is " << money;
        cout << "Your withdraw request was " << amount << endl;
        return;
    } else
    {
        money -= amount;
    }

}

void Deposit(int amount)
{
    money += amount;
}

int main(int argc, char* argv[])
{
    // ATM
    // Menu, Check balance, withdraw, deposit

    int choice = 0;
    int a = 0, amm = 0;

    do
    {
        choice = showMenu();

        switch (choice)
        {
        default:
            cout << "Invalid" << endl;
            break;
        case 0:
            cout << "Terminating" << endl;
            break;
        case 1:
            cout << "Checking Balance" << endl;
            CheckBalance();
            break;
        case 2:
            cout << "Withdraw" << endl;
            cout << "Amount to withdraw: ";
            cin >> a;
            Withdraw(a);
            break;
        case 3:
            cout << "Deposit";
            cout << "Amount to Deposit: ";
            cin >> amm;
            Deposit(amm);
            break;
        }
    }
    while (choice != 0);

    return 0;
}
