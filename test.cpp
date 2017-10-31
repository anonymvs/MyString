#include <iostream>
#include <stdio.h>
#include "mystring.h"

//tests from 1 to 5
#define TEST 1

int main() {

    #if TEST == 1
    MyString ms1("sample text");
    MyString ms2 = ms1;
    MyString ms3(ms1);
    MyString ms4(ms2);
    MyString ms5;
    ms5 = ms4;
    std::cout <<"ms1: " << ms1 << "\n" << "ms2: " << ms2 << "\n" << "ms3: "
         << ms3 << "\n" << "ms4: " << ms4 << "\n" << "ms5: " << ms5 << "\n" << "\n";
    #endif

    #if TEST == 2
    std::cout << "--------------------------" << "\n";
    MyString inputstr{};
    std::cin >> inputstr;
    std::cout << "user's input: " << inputstr << "\n";
    #endif

    #if TEST == 3
    std::cout << "--------------------------" << "\n";
    MyString a{"a"};
    MyString plus{" + "};
    MyString b{"b"};
    MyString result;
    result = a + plus + b;
    std::cout << result << "\n";
    result += " + c";  //?
    std::cout << result << "\n";
    #endif

    #if TEST == 4
    std::cout << "--------------------------" << "\n";
    MyString index_test{"012345"};
    index_test[3] = 'a';
    std::cout << index_test << "\n";  
    #endif

    #if TEST == 5
    std::cout << "--------------------------" << "\n"; 
    MyString something{"length"};
    std::cout << "the length of the word 'length': " << something.length() << "\n";
    #endif
 
    std::cout << "--------------------------" << "\n"; 

    return 0;
}