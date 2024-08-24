#ifndef PLOT_H
#define PLOT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Graph_Info.h"
#include "token/rightparen.h"
#include "token/leftparen.h"
#include "token/token.h"
#include "shunting_yard/shunting_yard.h"
#include "rpn/rpn.h"
#include "token/token.h"
#include "queue/MyQueue.h"
#include "token/function.h"
#include "coord_translation.h"
#include "tokenizer.h"

#include <iostream>

using namespace std;
using namespace sf;

class Plot
{ 
    public: 
    Plot();
    Plot(Graph_Info* infos): _info(infos){
        Tokenize token(infos);
        _infix=token(infos);
    };
    void set_info(Graph_Info *infos);
    vector<sf::Vector2f> operator()();

    private: 
    Graph_Info* _info;
    Queue<Token*> _postfix;
    Queue<Token*> _infix;
    vector<sf::Vector2f> screen_coor;
};
#endif
