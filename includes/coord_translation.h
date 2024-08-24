#ifndef COORD_H
#define COORD_H

#include "token/token.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Graph_Info.h"
#include <iostream>
#include "vector/vector_class.h"
using namespace std;
using namespace sf; 

class coord_translation
{
    public: 
    coord_translation();
    coord_translation(Graph_Info* infos);

    vector<Vector2f> translate (vector<Vector2f>graph_points);

    vector<Vector2f> operator ()(vector<Vector2f>graph_points);

    private: 
    vector<sf::Vector2f> coordinate;
    Graph_Info* _info;
    vector<sf::Vector2f> _rpn_coord;
    
};

#endif

