#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int yearOfBirth = 1998;
    char gender = 'm';
    bool isOlderThan18 = true;
    float averageGrade = 4.5;
    double balance = 453353634535;

    // SIZE
    cout << "Size of Int " << sizeof(int) << " bytes\n";
    cout << "Min of Int" << INT_MIN << endl; // first bit for sign
    cout << "Max Int " << INT_MAX << endl; // Include 0

    // Datatype overflow
    int a = INT_MAX;
    cout << a + 1; // Goes to min value

    // Unsigned Int
    cout << "Size Unsigned int " << sizeof(unsigned int) << "bytes\n";
    cout << "Uint max " << UINT_MAX << endl;

    // Char
    cout << "Size Char " << sizeof(char) << "bytes\n";
    cout << "Char max " << CHAR_MAX << " and MIN " <<
        CHAR_MIN << endl;

    // Bool
    cout << "Size Bool " << sizeof(bool) << "bytes\n";
    
    // Float
    cout << "Size Float " << sizeof(float) << "bytes\n";
    
    // Double
    cout << "Size Double " << sizeof(double) << "bytes\n";
    
    return 0;
}
