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

    /* std::cout << "-------------separator-------------" << "\n";
    MyString a{"a"};
    MyString plus{" + "};
    MyString b{"b"};

    MyString result;

    std::cout << "-------------separator-------------" << "\n";

    result = a + plus + b;
    //a += "c";
    std::cout << result << "\n"; */

/*     std::cout << "-------------separator-------------" << "\n";
    MyString index_test{"012345"};
    index_test[3] = 'a';
    std::cout << index_test << "\n";    
    std::cout << "-------------separator-------------" << "\n"; */


    MyString something{"valami"};
    std::cout << something.length() << "\n";

    return 0;
}