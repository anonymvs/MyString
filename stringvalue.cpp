#include <iostream>
#include <stdio.h>
#include <string.h>
#include "mystring.h"


int StringValue::getRefcnt() {
    return refcnt;
}

StringValue::StringValue() : data_{nullptr}, refcnt{-1} {
    std::cout << "StringValue: def ctor, refcnt: " << refcnt << "\n";
}

StringValue::StringValue(char const *str) : refcnt{0} {
    std::cout << "StringValue: def ctor with param, refcnt: " << refcnt << "\n";
    if(data_ != nullptr) { 
        delete[] data_;
    }
    data_ = new char[strlen(str)];
    strcpy(data_, str);   
}

StringValue::~StringValue() {
    std::cout << "StringValue-dtor: refcnt: " << refcnt << "\n\n";
    if(refcnt == 0) {
        if(data_ != nullptr) {
            delete[] data_;
            std::cout << "StringValue deleted\n";
        }
        return;
    } 
    refcnt--;
}

StringValue* StringValue::copied() {
    refcnt++;
    std::cout << "StringValue::copied() -- refcnt: " << refcnt << "\n";
    return this;
}

char* StringValue::getData() {  
    return data_;
}

size_t StringValue::length() {
    return strlen(data_);
}