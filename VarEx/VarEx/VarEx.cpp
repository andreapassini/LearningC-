#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "Type your annual salary \n";
    float annualSalary;
    cin >> annualSalary;
    
    float monthSalary = annualSalary / 12;
    cout << "Money per month: " << monthSalary;
    cout << "In 10 years: " << annualSalary*10;

    // single quotation marks for char
    char character = 'a';

    
    
    return 0;
}
