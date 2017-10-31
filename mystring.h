#include <iostream>
#include <stdio.h>

class StringValue {
private:
    char* data_;
    int refcnt;
public:
    StringValue();
    StringValue(char const *);
    ~StringValue();
    StringValue* copied();
    char* getData();
    int getRefcnt();
    void deincRefcnt();
    size_t length();
};


class MyString {
private:
    StringValue *sv_;
public:
    MyString();
    MyString(char const *);
    MyString(StringValue &&sv);
    ~MyString();
    MyString(MyString const &);
    MyString(MyString &&);
    MyString& operator=(MyString const &);
    MyString& operator=(MyString &&);
    char* getStringValue();
    void setStringValue(char const *);
    MyString& operator+=(MyString const &);
    MyString& operator+(char const *);
    MyString& operator+=(char const *);
    char& operator[](int);
    size_t length();
    bool isEmpty();

    friend std::ostream& operator<<(std::ostream &, MyString &);
    friend std::istream& operator>>(std::istream &, MyString &);
};

MyString&& operator+(MyString &, MyString &);
MyString&& operator+(MyString &&, MyString &);

