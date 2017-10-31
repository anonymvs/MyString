#include <iostream>
#include <stdio.h>
#include <cstring>
#include "mystring.h"

MyString::MyString() : sv_{nullptr}{}

MyString::MyString(char const *str) {
    sv_ = new StringValue{str};
}

MyString::MyString(MyString const &other) {
    sv_ = other.sv_->copied();
}

MyString::MyString(MyString &&other) {
    std::swap(this->sv_, other.sv_);
    other.sv_ = nullptr;
    delete &other;
}

MyString& MyString::operator=(MyString const &rhs) {
    if(this != &rhs) {
        if(sv_ != nullptr) {
            delete sv_;
        }
        sv_ = rhs.sv_->copied();
    }
    return *this;
}

MyString& MyString::operator=(MyString &&rhs) {
    if(sv_ != nullptr) 
        delete sv_;
    std::swap(this->sv_, rhs.sv_);
    delete &rhs;
    return *this;
}

MyString::~MyString() {
    if(sv_ != nullptr) {
        if(sv_->getRefcnt() == 0) {   
            delete sv_;
        } else {
            sv_->deincRefcnt();
        }
    }
}

char* MyString::getStringValue() {
    if(sv_ == nullptr) {
        return nullptr;
    }
    return sv_->getData();
}

void MyString::setStringValue(char const *arg) {
    if(sv_ != nullptr)
        delete sv_;
    sv_ = new StringValue{arg};
}

MyString& MyString::operator+=(MyString const & rhs) {
    if(rhs.sv_ == nullptr) 
        return *this;

    char *str;

    if(this->sv_ != nullptr) {
        str = new char[strlen(sv_->getData()) + strlen(rhs.sv_->getData()) + 1];
        strcpy(str, sv_->getData());
        delete sv_;
    } else {
        str = new char[strlen(rhs.sv_->getData()) + 1];
    }
    strcat(str, rhs.sv_->getData());
    StringValue *ret = new StringValue{str};
    sv_ = ret;
    return *this;
}

MyString&& operator+(MyString &lhs, MyString &rhs) {
    char *str;
    if(!lhs.isEmpty() && !rhs.isEmpty()) {
        str = new char[strlen(lhs.getStringValue()) + strlen(rhs.getStringValue()) + 1];
        strcpy(str, lhs.getStringValue());
        strcat(str, rhs.getStringValue());
        MyString *ret = new MyString{std::move(str)};
        delete[] str;
        return std::move(*ret);
    } else {
        if(lhs.isEmpty()) {
            return std::move(rhs);
        } else {
            return std::move(lhs);
        }
    } 
}


MyString&& operator+(MyString &&lhs, MyString &rhs) {
    char *str;
    if(!lhs.isEmpty() && !rhs.isEmpty()) {
        str = new char[strlen(lhs.getStringValue()) + strlen(rhs.getStringValue()) + 1];
        strcpy(str, lhs.getStringValue());
        strcat(str, rhs.getStringValue());
        MyString *ret = new MyString{std::move(str)};
        delete[] str;
        delete &lhs;
        return std::move(*ret);
    } else {
        if(lhs.isEmpty()) {
            return std::move(rhs);
        } else {
            return std::move(lhs);
        }
    }
}

MyString& MyString::operator+=(char const *rhs) {
    char *str = nullptr;
    if(this->sv_ != nullptr) {
        str = new char[strlen(sv_->getData()) + strlen(rhs) + 1];
        strcpy(str, sv_->getData());
        delete sv_;
    } else {
        str = new char[strlen(rhs) + 1];
    }
    strcat(str, rhs);
    StringValue *ret = new StringValue{str};
    sv_ = ret;
    delete[] str;
    return *this;
}

MyString& MyString::operator+(char const *rhs) {
    *this += rhs;
    return *this;
}

char& MyString::operator[](int i) {
    return sv_->getData()[i];
}

size_t MyString::length() {
    return sv_->length();
}

bool MyString::isEmpty() {
    if(sv_ == nullptr)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream &os, MyString &arg) {
    os << arg.getStringValue();
    return os;
}
std::istream& operator>>(std::istream &is, MyString &arg) {
    char c = '\n';
    bool b = true;
    while(b) {
        is.get(c);
        if(c == '\n') 
            break;
        arg += &c;
    }
    return is;
}

