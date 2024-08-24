
#include "coord_translation.h"
#include "token/token.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "vector/vector_class.h"
using namespace std;
using namespace sf; 

coord_translation::coord_translation(){
   //ctor
}

coord_translation::coord_translation(Graph_Info* infos){
    _info=infos; //setting to infos 
}

vector<Vector2f> coord_translation:: translate(vector<Vector2f>graph_points){
    
  
    for(int i = 0; i < graph_points.size();i++){ // for i less than the amount of poiints i ++ 
        double x = (graph_points[i].x + _info->origin.x); // add the original x and to the origin so that it proportionally correct
        double y = (_info->origin.y - (graph_points[i].y*_info->scale.y) ); //else it would be inverted 
    
        coordinate.push_back(Vector2f(x,y)); //create a vector, pushback and add it in 
    }
    return coordinate; // return the x,y
}

vector<Vector2f> coord_translation:: operator ()(vector<Vector2f>graph_points){
     return translate (graph_points);
    }

