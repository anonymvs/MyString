#include <iostream>
#include <stdio.h>

class StringValue {
private:
    char* data_;
    int refcnt;
    size_t strlen(char const *);
public:
    StringValue();
    StringValue(char const *);
    ~StringValue();
    StringValue* copied();
    char* getData();
    size_t length();
};


class MyString {
private:
    StringValue *sv_;
public:
    MyString();
    MyString(char const *);
    ~MyString();
    MyString(MyString const &);
    MyString(MyString &&);
    MyString& operator=(MyString const &);
    MyString& operator=(MyString &&);
    char* getStringValue();
    void setStringValue(char const *);
    MyString& operator+(MyString const &);
    MyString& operator+=(MyString const &);
    MyString& operator+(char const *);
    MyString& operator+=(char const *);
    char& operator[](int);
    size_t length();

    friend std::ostream& operator<<(std::ostream &, MyString &);
    friend std::istream& operator>>(std::istream &, MyString &);
};

