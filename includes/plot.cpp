#include "plot.h"

void Plot::set_info(Graph_Info* infos){
   _info=infos; //setting info to info 
   Tokenize token(infos); //pass info into the tokenizer
   _infix=token(infos);  //infix = to info 

//    while(!_infix.empty()){
//    cout << _infix.pop()->token() << " ";///to check 
//     }
}

vector<sf::Vector2f> Plot::operator()(){
    ShuntingYard sy(_infix); //perform shunting yard with _infix
    _postfix=sy.postfix(); //set that equal to our private postfix 
    RPN rpn(_postfix); //perform rpn 
    
    sf::Vector2f coords; //one thing at a time 
    vector<sf::Vector2f> point_coor; // the array to store
    for (int i = -_info->origin.x; i < _info->points; i++){ // while i is on the very left of the graph moves to the right n graph 
        coords.x= i;
        coords.y= rpn(coords.x);
        point_coor.push_back(coords);
        cout<< " X: "<<coords.x<< "||"<< "Y: "<<coords.y<<endl;
    }
    coord_translation trans(_info); //pass plot into the cords translation 
    screen_coor= trans.translate(point_coor);
    return screen_coor;

}