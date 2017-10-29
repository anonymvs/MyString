#include <iostream>
#include <stdio.h>
#include "mystring.h"


/* std::ostream& operator<<(std::ostream &os, MyString &arg) {
    os << arg.getStringValue();
    return os;
} */

int main() {
    /* std::cout << "-------------separator-------------" << "\n";
    MyString ms1("mystring");

    std::cout << "-------------separator-------------" << "\n";
    MyString ms2 = ms1;

    std::cout << "-------------separator-------------" << "\n";
    MyString ms3(ms1);

    std::cout << "-------------separator-------------" << "\n";
    MyString ms4(ms2);

    std::cout << "-------------separator-------------" << "\n";
    std::cout << ms1 << "\n" << ms2 << "\n" << ms3 << "\n" << ms4 << "\n"; */

   /*  std::cout << "-------------separator-------------" << "\n";
    MyString msa{"kerlek"};
    std::cin >> msa;
    
    std::cout << "-------------separator-------------" << "\n";
    std::cout << msa << "\n"; */

    std::cout << "-------------separator-------------" << "\n";
    MyString a{"a"};
    MyString plus{" + "};
    MyString b{"b"};

    MyString result;
    a += b;
    std::cout << a << "\n";

    std::cout << "-------------separator-------------" << "\n";



    
    

    return 0;
}