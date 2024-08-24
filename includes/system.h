#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include "Graph_Info.h"
#include "graph.h"
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace std;
class System
{
public:
    System();
    System(Graph_Info* infos);
    void Step(int command, Graph_Info* infos);
    void set_info(Graph_Info *infos);
    sf::Text Draw(sf::RenderWindow& window);
    void keyinput(sf::Event& event);
    void Equation_History(string equation);
    void Clear_Equation_History();
    void graph_box();
   
private:

    Graph_Info* _info;
    sf::RectangleShape xaxis;
    sf::RectangleShape yaxis;
    Graph* _graph;
    sf::Font font;
    sf::Text inputtext; 
    string input_equation;
    string input;
};

#endif 


