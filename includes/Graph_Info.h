#ifndef GRAPH_INFO
#define GRAPH_INFO
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;


struct Graph_Info{
string equation;
sf::Vector2f Screen_Size = Vector2f(1400,800);
sf::Vector2f Window_Size = Vector2f(1400*4/5,800);
sf::Vector2f origin= Vector2f (Window_Size.x/2,400);
sf::Vector2f scale = Vector2f (1,10.0);
sf::Vector2f domain = Vector2f (5,5);
sf::Vector2f Side_Bar=Vector2f(1400*4/5,800);

int points = 3000;
};

#endif