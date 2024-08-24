#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <SFML/Graphics.hpp>
#include "token/token.h"
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

class Tokenize
{
    public: 
    Tokenize();
    Tokenize(Graph_Info* infos);

    Queue<Token*> token(Graph_Info*& infos);
    Queue<Token*> operator()(Graph_Info*& infos);


    private: 
    Graph_Info* info;
    Queue<Token*> _infix;
};
#endif