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
    StringValue(StringValue &);
    StringValue(StringValue &&);
    StringValue& operator=(StringValue const &);
    StringValue& operator=(StringValue &&);
    char* getData();
    bool operator!=(StringValue const &) const;
};


class MyString {
private:
    StringValue *sv_;
public:
    MyString();
    MyString(char const *);
    ~MyString();
    MyString(MyString &);
    MyString(MyString &&);
    MyString& operator=(MyString const &);
    MyString& operator=(MyString &&);
    char* getStringValue();
    MyString& operator+(MyString const &) const;
    MyString& operator+=(MyString const &) const;
    MyString& operator-(MyString const &) const;
    MyString& operator+(char const &) const;
    MyString& operator+=(char const &) const;
    MyString& operator[](int);
    size_t length();
};
