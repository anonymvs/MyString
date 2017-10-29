#include <iostream>
#include <stdio.h>
#include "mystring.h"


std::ostream& operator<<(std::ostream &os, MyString &arg) {
    os << arg.getStringValue();
    return os;
}

int main() {
    std::cout << "-------------separator-------------" << "\n";
    MyString ms1("mystring");
    std::cout << "-------------separator-------------" << "\n";
    MyString ms2 = ms1;
    std::cout << "-------------separator-------------" << "\n";
    MyString ms3(ms1);
    std::cout << "-------------separator-------------" << "\n";
    MyString ms4(ms2);
    std::cout << "-------------separator-------------" << "\n";


    return 0;
}