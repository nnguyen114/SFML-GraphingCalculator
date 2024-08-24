#include "system.h"
#include <iostream>
#include "constants.h"
System::System()
{  
    _info=nullptr;
    input="";
}


//------------------------------------------------------------------
//------------------------------------------------------------------
System::System(Graph_Info* infos)
{    
    input="X";
    _info = infos;
    
    font.loadFromFile("arial.ttf");
    inputtext.setFont(font);
    inputtext.setCharacterSize(24);
    inputtext.setFillColor(sf::Color::White);
    inputtext.setPosition(1200, 10);

    xaxis = sf::RectangleShape(sf::Vector2f(2, infos->Window_Size.y));
    yaxis = sf::RectangleShape(sf::Vector2f(infos->Window_Size.x, 2));
    // set position
    xaxis.setPosition(_info->origin.x+2, 0);
    yaxis.setPosition(0, _info->origin.y);
    // set color
    xaxis.setFillColor(sf::Color::Black);
    yaxis.setFillColor(sf::Color::Black);

    _graph = new Graph(_info,input);// pointer, create a new graph everytime something updated 
}


void System::set_info(Graph_Info *infos){
    _info = infos;
}

void System::Step(int command, Graph_Info* infos){
        _info=infos;
        
        if (command == 1){
            _info->origin.x += 50;
            xaxis.setPosition(_info->origin.x+2, 0);
            yaxis.setPosition(0, _info->origin.y);    //command for keyboards
            _graph->update(_info);
        }

        else if (command == 2){
            _info->origin.x -= 50;
             xaxis.setPosition(_info->origin.x+2, 0);
             yaxis.setPosition(0, _info->origin.y);
            _graph->update(_info);
        }

        else if (command == 3){
            
            _info->scale.y *= 0.8;
            _info->domain.y += 2;
            _info->domain.x += 2;
            _graph->update(_info);
        }

        else if (command == 4){

           _info->scale.y *=1.1;
           _info->domain.x -= 2;
           _info->domain.y -= 2;
          
            _graph->update(_info);
        }  

        
    }


sf::Text System::Draw(sf::RenderWindow& window){ // have to make it  text and return text so that we could cll it in sidebar and so that it gets the info from system and make it own equation
    window.clear(sf::Color(211, 211, 211));
    window.draw(inputtext);
    window.draw(xaxis);    //draw and then call draw again in animate for all these to pull up 
    window.draw(yaxis);
    _graph->draw(window);
    return inputtext;
}

void System::keyinput(sf::Event& event)
    {
        if (event.type == sf::Event::TextEntered)
        {
          
            if (event.text.unicode == 8)///backspace
            {
                if (!input_equation.empty())
                {
                    input_equation.pop_back();
                    inputtext.setString(input_equation); //SFML Text Object 
                }
            }
          
            else  ///other keys
            {
                input_equation += event.text.unicode;
                inputtext.setString(input_equation);
            }  
                _graph->update(_info); //update graph 
        }
    }


void System:: graph_box()
    {
        input = input_equation;
        Equation_History(input_equation);
        input_equation.clear();   //create this so that it could grab it in animate 
        inputtext.setString(input_equation);
        _graph = new Graph(_info, input);
        _graph->update(_info);

    }


void System:: Equation_History(string equation)
    {
        ofstream myfile;
        myfile.open("equation_history.txt", ios::app); //pull out the txt 
        if (equation != " ") //if its not empty throw the eqution we just wrote down into the file 
        myfile << equation << "\n";
        myfile.close();
    }

void System:: Clear_Equation_History()
    {
        ofstream myfile;
        myfile.open("equation_history.txt", ios::trunc);
        myfile.close();
    }

