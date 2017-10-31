#include <iostream>
#include <stdio.h>
#include <string.h>
#include "mystring.h"


int StringValue::getRefcnt() {
    return refcnt;
}

void StringValue::deincRefcnt() {
    refcnt--;
}

StringValue::StringValue() : data_{nullptr}, refcnt{-1} {}

StringValue::StringValue(char const *str) : refcnt{0} {
    data_ = new char[strlen(str) + 1];
    strcpy(data_, str);   
}

StringValue::~StringValue() {
    if(data_ != nullptr) {
        delete[] data_;
    }
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
