#include <iostream>

int Add(int a, int b){
    int sum = a+b;

    return sum;
}

int main(){
    
    int first {13};
    int second {7};

    std::cout << "Number 1 " << first << std::endl;
    std::cout << "Number 2 " << second << std::endl;

    int sum = Add(first, second);

    std::cout << "Sum " << sum << std::endl;

    return 0;
}