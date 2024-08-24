#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>

using namespace std;


class Token
{
    //I know what my type is, I know what my face looks like.
    public:
        Token(const string& s="?", int type=0):_token(s), _type(type){}
        friend ostream& operator <<(ostream& outs, const Token& t) {
            outs << t._token << " ";
            return outs;
        }

        virtual int type(){return _type;}
        virtual Token* eval(Token* left, Token* right){}
        string token(){return _token;}

        
    private:
    int _type;
    string _token;
};


/*

    3 + 8  ---->[Shunting Yard ]---> 3 8 +  ------> [RPN] ------->11





*/

#endif