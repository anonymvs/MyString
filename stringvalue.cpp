#include <iostream>
#include <stdio.h>
#include <string.h>
#include "mystring.h"


int StringValue::getRefcnt() {
    return refcnt;
}

StringValue::StringValue() : data_{nullptr}, refcnt{-1} {}

StringValue::StringValue(char const *str) : refcnt{0} {
    if(data_ != nullptr) { 
        delete[] data_;
    }
    data_ = new char[strlen(str)];
    strcpy(data_, str);   
}

StringValue::~StringValue() {
    if(refcnt == 0) {
        if(data_ != nullptr) {
            delete[] data_;
        }
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