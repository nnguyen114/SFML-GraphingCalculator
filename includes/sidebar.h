#ifndef SIDEBAR_H
#define SIDEBAR_H
#include "system.h"
#include <SFML/Graphics.hpp>
#include "Graph_Info.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Sidebar
{
public:
    Sidebar();
    Sidebar(Graph_Info* infos);
    void draw(sf::RenderWindow& window);
    void text_font(sf::RenderWindow& window,sf::Text& text );
    void equation_history(sf::RenderWindow& window);
    void text_box(sf::RenderWindow& window);
    string& operator [](int index);
    
    sf::RectangleShape graphbox;
private:
    
    sf::RectangleShape equationbox;
    sf::RectangleShape textbox;
    System* _system;
    Graph_Info* _info;
    sf::RectangleShape rect;            //sidebar rectangle
    vector<string> items;               //strings to place on the sidebar
    sf::Font font;                      //used to draw text
    sf::Text sb_text; 
                      //used to draw strings on the window object

};

#endif // SIDEBAR_H
