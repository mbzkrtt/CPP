#include <iostream>
#include <string>


Exercice 1-1

int main()
{
    std::cout << "Hello World !" << std::endl;

    return 0;
}

Exercice 1-2

void print_string(std::string text)
{
    std::cout << text << std::endl;
}

int main()
{
    print_string("Hello World !");

    return 0;
}


Exercice 1-3

main.h

#include <string>

void print_string(const std::string& text);


main.cpp

#include "main.h"

void print_string(const std::string& text)
{
    std::cout << text << std::endl;
}

int main()
{
    print_string("Hello World !");

    return 0;
}

Exercice 1-4




class my_class
{
private:
    std::string my_element;

public:
    my_class();
    my_class(const std::string& value);

    void print_my_element();
};




my_class::my_class()
{
    my_element = "";
}

my_class::my_class(const std::string& value)
{
    my_element = value;
}

void my_class::print_my_element()
{
    std::cout << my_element << std::endl;
}



int main()
{
    my_class object1;
    my_class object2("Hello World !");

    object1.print_my_element();
    object2.print_my_element();

    return 0;
}