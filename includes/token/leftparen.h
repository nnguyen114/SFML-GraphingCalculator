#ifndef LEFTPAREN_H
#define LEFTPAREN_H
#include <iostream>
#include "constants.h"

using namespace std;

class LeftParen: public Token{
    public:
    LeftParen(): Token("(",3){};
};


#endif