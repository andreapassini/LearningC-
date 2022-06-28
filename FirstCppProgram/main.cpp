#include <iostream>

int main(){
    
    // Data una sequenza inserita dall'utente, 0 termina la sequenza
    // Stampare il numero minore

    std::cout << "Insert Number 1" << std::endl;
    
    int min;

    std::cin >> min;

    int a;

    do
    {
        std::cout << "Insert Number" << std::endl;
        std::cin >> a;

        if(a < min && a != 0)
        {
            min = a;
        }

    } while (a != 0);
    

    std::cout << "Min " << min << std::endl;

    return 0;
}