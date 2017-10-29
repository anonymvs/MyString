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
    std::cout << "MyString-copy ctor, refcnt: ";
    sv_ = other.sv_->copied();
    if(sv_ != nullptr)
        std::cout << sv_->getRefcnt() << "\n";
}

MyString::MyString(MyString &&other) {
    std::cout << "MyString-move ctor, refcnt: ";
    std::swap(this->sv_, other.sv_);
    other.sv_ = nullptr;
    if(sv_ != nullptr)
        std::cout << sv_->getRefcnt() << "\n";
}

MyString& MyString::operator=(MyString const &rhs) {
    std::cout << "MyString-copy assignement operator, refcnt: ";
    if(this != &rhs) {
        if(sv_ != nullptr) {
            delete sv_;
        }
        sv_ = rhs.sv_->copied();
    }
    return *this;
}

MyString& MyString::operator=(MyString &&rhs) {
    std::cout << "MyString-move assignement operator, refcnt: ";
    std::swap(this->sv_, rhs.sv_);
    rhs.sv_ = nullptr;
    if(sv_ != nullptr)
        std::cout << sv_->getRefcnt() << "\n";
    return *this;
}

MyString::~MyString() {
    std::cout << "MyString-dtor, refcnt: ";
    if(sv_ != nullptr)
        std::cout << sv_->getRefcnt() << "\n";
    if(sv_ != nullptr)
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

