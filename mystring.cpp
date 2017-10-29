#include <iostream>
#include <stdio.h>
#include "mystring.h"



size_t StringValue::strlen(char const *str) {
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }
    return i;
}


StringValue::StringValue() : data_{nullptr}, refcnt{0} {
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
    refcnt--;
    if(refcnt == 0) {
        std::cout << "---------signal --------------" << "\n";
        delete[] data_;
    }
}

StringValue::StringValue(StringValue &other) : StringValue{other.data_} {
    refcnt = other.refcnt;
    refcnt++;
    std::cout << "StringValue: copy ctor, refcnt: " << refcnt << "\n";
}

StringValue::StringValue(StringValue && other) {
    refcnt++;
    std::cout << "StringValue: move ctor, refcnt: " << refcnt << "\n";
}

StringValue& StringValue::operator=(StringValue const &rhs) {
    if(this != &rhs) {
        //std::swap(this, *rhs);
        std::cout << "pre refcnt: " << refcnt;
        refcnt++;
        std::cout << " StringValue: copy assingment operator, refcnt: " << refcnt << "\n";
    }
    return *this;
}

StringValue& StringValue::operator=(StringValue && rhs) {
    delete[] data_;
    this->data_ = rhs.data_;
    refcnt++;
    std::cout << "StringValue: move assingment operator, refcnt: " << refcnt << "\n";
    return *this;
}

char* StringValue::getData() {  
    return data_;
}

bool StringValue::operator!=(StringValue const &rhs) const{
    return this->data_ != rhs.data_;
}


MyString::MyString() : sv_{nullptr}{
    std::cout << "MyString-def ctor" << "\n";
}

MyString::MyString(char const *str) {
    std::cout << "MyString-ctor with param" << "\n";
    sv_ = new StringValue{str};
}

MyString::MyString(MyString &other) {
    std::cout << "MyString-copy ctor" << "\n";
    //std::cout << other.sv_->getData() << "\n";
    if(sv_ != other.sv_)
        delete sv_;
    sv_ = new StringValue{*other.sv_};
}

MyString::MyString(MyString &&other) {
    std::cout << "MyString-move ctor" << "\n";
    sv_ = new StringValue{};
    sv_->operator=(*other.sv_);
}

MyString& MyString::operator=(MyString const &rhs) {
    std::cout << "MyString-copy assignement operator" << "\n";
    if(this != &rhs) {
        delete sv_;
        sv_ = new StringValue{};
        sv_->operator=(*rhs.sv_);
    }
    return *this;
}

MyString& MyString::operator=(MyString &&rhs) {
    std::cout << "MyString-move assignement operator" << "\n";
    std::swap(sv_, rhs.sv_);
    return *this;
}

MyString::~MyString() {
    std::cout << "MyString-dtor" << "\n";
    delete sv_;
}

char* MyString::getStringValue() {
    //std::cout << "MyString->StringValue->getData(): " << sv_->getData() << "\n";
    return sv_->getData();
}

MyString& MyString::operator+(MyString const &rhs) const {

}

MyString& MyString::operator+=(MyString const & rhs) const {
    //TODO
}

MyString& MyString::operator+(char const &rhs) const {
    //TODO
}
    
MyString& MyString::operator+=(char const & rhs) const {
    //TODO
}

MyString& MyString::operator[](int i) {
    //TODO
}

size_t MyString::length() {
    //TODO
}
