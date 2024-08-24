#ifndef OPERATOR_H
#define OPERATOR_H
#include <iostream>
#include "token.h"
#include "integer.h"
#include <cmath>
using namespace std;

class Operator:public Token{
    public:
    //integer type is 1: these are enums!

        Operator(const string& op):Token(op, 2){
            //or stod

            _prec = get_prec(op);
        }
        int get_prec(const string& op){
            if (token() == "+"){
                return 1;
            }
        else if  (token() == "-"){
                return 1;
            }
        else if (token() == "*"){
                return 2;
            }
        else if (token() == "/"){
                return 2;
            }
        else if(token() == "^"){
                return 3;
            }
        else if(token() == "("){
                return 4;
            }
        else if(token() == ")"){
                return 5;
            }

        else if (token() == "X"){
                return 6;
            }
        else if (token() == "sin"){
                cout<<"hello form OP";
                return 7;
            }
        else if (token() == "cos"){
                return 7;
            }
        else if (token() == "tan"){
                return 7;
    
            }

            return 99;
        }

        Token* eval( double left, double right){
            double result;
            Token* answer;
            switch (token()[0]){
                case '+':
                result=left+right;
                break;

                case '-':
                result=left-right;
                break;

                case '*':
                result=left*right;
                break;

                case '/':
                result=left/right;
                break;

                case '^':
                result=pow(left,right);
                break;

            }
         answer = new Integer(result);
         return answer;
        }

        Token* eval_trig( double term){
            double result;
            Token* answer;
            switch(token()[0]){
                case 's':
                result=sin(term);
                break;

                case 'c':
                result=cos(term);
                break;

                case 't':
                result=tan(term);
                break;
            }
        answer = new Integer(result);
        return answer;
        }


        int Prece_Type(){//check prec before in oush
            return _prec;
        }

    private:
        int _prec;
};

#endif