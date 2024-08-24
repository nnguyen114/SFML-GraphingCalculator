#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include "token.h"
#include "operator.h"
using namespace std;



class Function: public Operator{
    public: 
    Function(const string& x): Operator("X"){};
    
};




#endif

