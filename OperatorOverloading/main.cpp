#include <iostream>
#include "cstring"

class MyString{
private:
    char* str;
public:
    MyString();
    MyString(const char* s);
    MyString(const MyString &source);

    ~MyString();

    void display() const;
    int getLength() const;
    const char* getStr() const;
};

MyString::MyString()
  :str(nullptr){
    str = new char[1];
    *str = '\0';
}

MyString::MyString(const char *s)
  :str(nullptr){
    if(s == nullptr){
        str = new char[1];
        *str = '\0';
    } else {
        str = new char(std::strlen(s)+1);
        std::strcpy(str, s);
    }
}

// Copy Constructor
MyString::MyString(const MyString &source)
  :str(nullptr){
    str = new char(std::strlen(source.str)+1);
    std::strcpy(str, source.str);
}

// Destructor
MyString::~MyString() {
    delete [] str;
}

// Display Method
void MyString::display() const {
    std::cout << str << ":" << getLength() << std::endl;
}

// get Length
int MyString::getLength() const {
    return std::strlen(str);
}

const char *MyString::getStr() const {
    return str;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    MyString empty;
    MyString ciao ("Ciao");
    MyString ciaoCpy = (ciao);

    empty.display();
    ciao.display();
    ciaoCpy.display();

    return 0;
}
