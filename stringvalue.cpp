#include <iostream>
#include <stdio.h>
#include <string.h>
#include "mystring.h"


size_t StringValue::strlen(char const *str) {
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }
    return i;
}


StringValue::StringValue() : data_{nullptr}, refcnt{-1} {
    std::cout << "StringValue: def ctor, refcnt: " << refcnt << "\n";
}

StringValue::StringValue(char const *str) : refcnt{0} {
    std::cout << "StringValue: def ctor with param, refcnt: " << refcnt << "\n";
    data_ = new char[strlen(str)];
    for(size_t i = 0; i < strlen(str); i++) {
        data_[i] = str[i];
    }    
}

StringValue::~StringValue() {
    std::cout << "StringValue-dtor: refcnt: " << refcnt << "\n";
    if(refcnt == 0) {
        delete[] data_;
        std::cout << "StringValue deleted\n";
        return;
    } 
    refcnt--;
}

StringValue* StringValue::copied() {
    refcnt++;
    return this;
}

char* StringValue::getData() {  
    return data_;
}

size_t StringValue::length() {
    return strlen(data_);
}