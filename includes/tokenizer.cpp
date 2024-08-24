#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "tokenizer.h"
#include "token/integer.h"
#include "token/operator.h"
#include "token/function.h"
#include "Graph_Info.h"
#include "token/rightparen.h"
#include "token/leftparen.h"
#include "queue/MyQueue.h"
#include "vector/vector_class.h"
#include <iostream>

using namespace std;

    Tokenize::Tokenize(){

    }

    Tokenize::Tokenize(Graph_Info* infos){
        info=infos;
    }

    Queue<Token*> Tokenize::token(Graph_Info*& infos){
        for (int i=0 ; i < infos->equation.length();i++){
            char term= infos->equation.at(i);
            string s(1,term);
            
            if (isdigit(term)){
                double number= double (term-48);
                _infix.push(new Integer(number));
            }
            else {
                switch (term){
                     case '+':
                    _infix.push(new Operator("+"));
                    break; 

                    case '-':
                    _infix.push(new Operator("-"));
                    break; 

                    case '*':
                    _infix.push(new Operator("*"));
                    break; 

                    case '/':
                    _infix.push(new Operator("/"));
                    break; 

                    case '(':
                    _infix.push(new LeftParen());
                    break; 

                    case ')':
                    _infix.push(new RightParen());
                    break; 

                    case '^':
                    _infix.push(new Operator("^"));
                    break;

                    case 'X':
                    _infix.push(new Function("X"));
                    break;
                   
                    case 's':
                    i+=2;
                    _infix.push(new Operator("sin"));
                    break;

                    case 'c':
                    i+=2;
                    _infix.push(new Operator("cos"));
                    break;

                    case 't':
                     i+=2;
                    _infix.push(new Operator("tan"));
                    break;
                }
            }
        } return _infix;
    }
    

    Queue<Token*> Tokenize::operator()(Graph_Info*& infos){
        return token(infos);
}