#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    //BMI Calculator
    //weight(kg) / height * height(m)
    // Underweight < 18.5
    // Normal 18.5 - 24.9
    // Overweight > 25

    float weight;
    float height;

    cout << "Welcome to the B.M.I. Calculator" << endl <<
        "Insert your weight in Kg" << endl;

    cin >> weight;

    cout << "Insert your Height in cm " << endl;

    cin >> height;
    height /= 100;

    float BMI = weight / (height*height);
    cout << "Your BMI is: " << BMI << endl;

    if(BMI < 18.5)
    {
        cout << "Underweight";
    }
    else if(BMI >= 18.5 && BMI < 24.9)
    {
        cout << "Normal";
    }
    else if(BMI >= 25)
    {
        cout << "Overweight";
    }
    
    return 0;
}
