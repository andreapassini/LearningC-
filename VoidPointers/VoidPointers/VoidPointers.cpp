#include <iostream>
using namespace std;

void PrintNumber(int* numberPtr)
{
    cout << *numberPtr << endl;
}

void PrintLetter(char* charPtr)
{
    cout << *charPtr << endl;
}

// Void pointer
void Print(void* ptr, char type)
{
    switch (type)
    {
    case 'i': //Int prt
        // cast to int pointer
        cout << *((int*)ptr) << endl;
        break;
    case 'c':
        cout << *((char*)ptr) << endl;
        break;
    }
}

int main(int argc, char* argv[])
{
    int number = 5;
    char letter = 'a';
    Print(&letter, 'c');
    
    return 0;
}
