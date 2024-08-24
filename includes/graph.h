// must have set_info function
#ifndef GRAPH_H
#define GRAPH_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Graph_Info.h"
#include "plot.h"
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

// obj, get graph to draw y = x on the screen through hard coding
class Graph
{
public:
    Graph(){
        
        _info = nullptr;
    
    }
    Graph(Graph_Info *graph_info, string _input){
       
            _info=graph_info; // setting infos info
            _info->equation = _input; //setting the new equation input
            Plot _plotter(_info); //give plotter the info 
            _points = _plotter();  //set the points to whatever plotter returns 
        

    }
  
    void update(Graph_Info* graph_info) {
        _info=graph_info;
        Plot _plotter(_info);//update new user input
        _points = _plotter();

    }

    void draw(sf::RenderWindow &window){  
        for (int i = 0; i < _info->points; i++)
        {
            sf::CircleShape point;
            point.setRadius(3);
            point.setFillColor(sf::Color(105,190,40)); //creating the dots , plots
            point.setPosition(_points[i]);
            window.draw(point);
        }
        for (int i = 0; i < _info->Window_Size.x; i=i+50+_info->domain.x )
        {
            sf::RectangleShape grid(sf::Vector2f(1, _info->Window_Size.y)); // creating the grid 
            grid.setPosition(i+20, 0);
            grid.setFillColor(sf::Color(64, 64, 64 ));
            window.draw(grid);
        }
        for (int i = 0; i < _info->Window_Size.y; i=i+50+_info->domain.y)
        {
            sf::RectangleShape grid(sf::Vector2f(_info->Window_Size.x, 1));
            grid.setPosition(0, i+13);
            grid.setFillColor(sf::Color(64, 64, 64 ));
            window.draw(grid);
        }
        window.draw(xaxis);
        window.draw(yaxis);
    }// draw calls graph draw()
  


   

private:
    sf::RectangleShape xaxis;
    sf::RectangleShape yaxis;
    Graph_Info *_info;
    string input;
    vector<sf::Vector2f> _points; 
    vector<sf::Vector2f> xyaxis;
    vector<sf::Vector2f> grid;
    sf::Font font;                // font stuff ?
    int command; // command to send to system
    /* data */
};


#endif