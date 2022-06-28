#include <iostream> // per std::cout, std::cin e std::endl

int main()
{
    // print ("ciao")
    cout << "scrivi numero decimale" << endl;

    int numero1;

    // numero1 = input
    cin >> numero1;

    cout << "Inserire un altro numero decimale" << endl;

    int numero2;
    
    cin >> numero2;

    int differenza = numero1 - numero2;
    cout << differenza << endl;

    return 0;
}
