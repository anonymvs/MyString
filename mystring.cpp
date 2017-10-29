#include <iostream>
#include <stdio.h>
#include <cstring>
#include "mystring.h"

MyString::MyString() : sv_{nullptr}{
    std::cout << "MyString-def ctor" << "\n";
}

MyString::MyString(char const *str) {
    std::cout << "MyString-ctor with param" << "\n";
    sv_ = new StringValue{str};
}

MyString::MyString(MyString const &other) {
    std::cout << "MyString-copy ctor" << "\n";
    sv_ = other.sv_->copied();
}

MyString::MyString(MyString &&other) {
    std::cout << "MyString-move ctor" << "\n";
    std::swap(this->sv_, other.sv_);
    other.sv_ = nullptr;
}

MyString& MyString::operator=(MyString const &rhs) {
    std::cout << "MyString-copy assignement operator" << "\n";
    if(this != &rhs) {
        delete sv_;
        sv_ = rhs.sv_->copied();
    }
    return *this;
}

MyString& MyString::operator=(MyString &&rhs) {
    std::cout << "MyString-move assignement operator" << "\n";
    std::swap(this->sv_, rhs.sv_);
    rhs.sv_ = nullptr;
    return *this;
}

MyString::~MyString() {
    std::cout << "MyString-dtor" << "\n";
    delete sv_;
}

char* MyString::getStringValue() {
    if(sv_ == nullptr) {
        std::cout << "StringValue not yet initialized\n";
        return nullptr;
    }
    return sv_->getData();
}

void MyString::setStringValue(char const *arg) {
    if(sv_ != nullptr)
        delete sv_;
    sv_ = new StringValue{arg};
}

MyString& MyString::operator+(MyString const &rhs) {
    char* str = strcat(sv_->getData(), rhs.sv_->getData());
    StringValue* tmp = new StringValue{str};
    if(sv_ != nullptr) {
        delete sv_;
    }
    sv_ = tmp;
    return *this;
}

MyString& MyString::operator+=(MyString const & rhs) {
    //std::cout << "+= operator: " << sv_->getData() << rhs.sv_->getData();
    char* str = strcat(sv_->getData(), rhs.sv_->getData());
    StringValue* tmp = new StringValue{str};
    if(sv_ != nullptr) {
        delete sv_;
    }
    sv_ = tmp;
    return *this;
}

MyString& MyString::operator+(char const *rhs) {
    //std::cout << "+= operator: " << sv_->getData() << rhs.sv_->getData();
    char* str = strcat(sv_->getData(), rhs);
    StringValue* tmp = new StringValue{str};
    if(sv_ != nullptr) {
        delete sv_;
    }
    sv_ = tmp;
    return *this;
}
    
MyString& MyString::operator+=(char const *rhs) {
    //std::cout << "+= operator: " << sv_->getData() << rhs << "\n";
    char* str = strcat(sv_->getData(), rhs);
    StringValue* tmp = new StringValue{str};
    if(sv_ != nullptr) {
        delete sv_;
    }
    sv_ = tmp;
    return *this;
}

char& MyString::operator[](int i) {
    return sv_->getData()[i];
}

size_t MyString::length() {
    return sv_->length();
}

std::ostream& operator<<(std::ostream &os, MyString &arg) {
    if(arg.getStringValue() != nullptr)
        os << arg.getStringValue();
    return os;
}
std::istream& operator>>(std::istream &is, MyString &arg) {
    char s[1000];
    is >> s;
    arg.setStringValue(s);
    return is;
}

