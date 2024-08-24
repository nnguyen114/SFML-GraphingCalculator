#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>
#include "token.h"
using namespace std;


class Integer:public Token{
    public:
    //integer type is 1: these are enums!
        Integer( double i=0):Token(to_string(i), 1),_value(i){}
        Integer(const string& n="0.0"):Token(n, 1), _value(stod(n)){
            //or stod
        }
    double int_only(){ return _value;}
    private:
        double _value;
};

#endif