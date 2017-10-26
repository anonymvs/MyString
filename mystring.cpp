#include <iostream>
#include <stdio.h>

class StringValue {
private:
    char* data_;
    int refcnt;

    size_t strlen(char const *str) {
        int i = 0;
        while(str[i] != '\0') {
            i++;
        }
        return i;
    }
public:

    StringValue() : data_{nullptr}, refcnt{0} {
        std::cout << "StringValue: def ctor" << "\n";
    }

    StringValue(char const *str) : refcnt{0} {
        //std::cout << "StringValue: ctor --> data_: ";
        data_ = new char[strlen(str)];
        for(size_t i = 0; i < strlen(str); i++) {
            data_[i] = str[i];
        }    
    }

    ~StringValue() {
        std::cout << "StringValue-dtor: " << refcnt << "\n";
        refcnt--;
        if(refcnt == 0) {
            std::cout << "---------signal --------------" << "\n";
            delete[] data_;
        }
    }

    StringValue* copy() {
        std::cout << "StringValue.refcnt:  " << refcnt << "\n";
        refcnt++;
        return this;
    }

    char* getData() {  
        return data_;
    }
};

class MyString {
private:
    StringValue *sv_;

public:
    
    MyString() {
        std::cout << "MyString-def ctor" << "\n";
        sv_ = new StringValue{};
    }

    MyString(char const *str) {
        std::cout << "MyString-ctor with param" << "\n";
        sv_ = new StringValue{str};
    }

    MyString(MyString const &other) {
        std::cout << "MyString-copy ctor" << "\n";
        sv_ = other.sv_->copy();
    }

    MyString(MyString &&other) {
        std::cout << "MyString-move ctor" << "\n";
        sv_ = other.sv_;
    }

    MyString& operator=(MyString const &rhs) {
        std::cout << "MyString-copy assignement operator" << "\n";
        if(this != &rhs) {
            delete sv_;
            sv_ = rhs.sv_->copy();
        }
        return *this;
    }

    MyString& operator=(MyString &&rhs) {
        std::cout << "MyString-move assignement operator" << "\n";
        std::swap(sv_, rhs.sv_);
        return *this;
    }

    ~MyString() {
        std::cout << "MyString-dtor" << "\n";
        delete sv_;
    }

    char* getStringValue() {
        //std::cout << "MyString->StringValue->getData(): " << sv_->getData() << "\n";
        return sv_->getData();
    }

    MyString& operator+(MyString const &rhs) const {
        //TODO
    }

    MyString& operator+=(MyString const & rhs) const {
        //TODO
    }

    MyString& operator+(char const &rhs) const {
        //TODO
    }
        
    MyString& operator+=(char const & rhs) const {
        //TODO
    }

    MyString& operator[](int i) {
        //TODO
    }

    size_t lenght() {
        //TODO
    }
};

std::ostream& operator<<(std::ostream &os, MyString &arg) {
    os << arg.getStringValue();
    return os;
}

int main() {
    MyString ms("is this the real world?");
    MyString ms_copy(ms);
    MyString ms_rval(MyString("another"));
    MyString ms_rval_pls = MyString("and another one");
    ms_rval = ms;
    ms_rval_pls = ms_copy;
    std::cout << ms << "\n" << ms_copy << "\n" << ms_rval << "\n";


    return 0;
}