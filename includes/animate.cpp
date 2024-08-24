#include "animate.h"
#include "constants.h"
#include <iostream>
using namespace std;
#include "system.h"


animate::animate()
//sidebar(WORK_PANEL)

{
    _info = new Graph_Info();
    cout<<"animate CTOR: TOP"<<endl;

    window.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will
    
   
    sidebar= Sidebar(_info); //creating a new sidebar
    system =new System(_info); // since System is a pointer, have to create it with new
    window.setFramerateLimit(60);

    mouseIn = true;
    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Blue); // these lines are for the cursor

    cout<<"Geme CTOR. preparing to load the font."<<endl;


    cout<<"animate instantiated successfully."<<endl;
}

void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    
    inputtext= system->Draw(window);  //displaying ur equation youre typing 
    system->Draw(window);             // displaying the big draw in system, so zoom pan and such 
    sidebar.draw(window);            //displaying the side bar
    sidebar.text_font(window, inputtext); //displaying the equation on to the sidebar
    sidebar.equation_history(window);   //equation history 
    sidebar.text_box(window);          ///displaying all the draw functions 
    
    if (mouseIn){
        window.draw(mousePoint);
    }

    

    // //- - - - - - - - - - - - - - - - - - -
    // //getPosition() gives you screen coords, getPosition(window) gives you window coords
    // cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    // //- - - - - - - - - - - - - - - - - - -

    // //drawing Test: . . . . . . . . . . . .
    // //This is how you draw text:)
    // window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}




void animate::render(){
      window.clear();     
       Draw();
       window.display();
}


void animate::processEvents(){
   sf::Event event;
   float mouseX, mouseY;
   while (window.pollEvent(event))//or waitEvent
       {
       // check the type of the event...
           switch (event.type){
           // window closed
           case sf::Event::Closed:
               window.close();   // closing the sfml 
               break;

           case sf::Event::TextEntered:
                system->keyinput(event); //to recognize when we are typing 
                break;

           case sf::Event::MouseEntered:
               mouseIn = true;
               break;


           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

           case sf::Event::MouseMoved:
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                break;
            
           case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                            mouse_pos_string(window);

                }
                else{
                    sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                            mouse_pos_string(window);
                }
                break;

           // key pressed
           case sf::Event::KeyPressed:
            switch(event.key.code){
                case sf::Keyboard::Up:
                   cout<<"Up was Pressed"<<endl;
                   sidebar[SB_KEY_PRESSED] = "Zoom In"; // zoom and pan 
                   command = 3;
                   system->Step(command, _info);
                   break;

               case sf::Keyboard::Down:
                   sidebar[SB_KEY_PRESSED] = "Zoom Out";
                   command = 4;
                   system->Step(command, _info);
                   cout<<"scale: "<< _info->scale.y<<endl;
                   break;

               case sf::Keyboard::Right:
                   sidebar[SB_KEY_PRESSED] = "Right";
                   command=1;
                   system->Step(command, _info);
                   break;
               
               case sf::Keyboard::Left:
                   sidebar[SB_KEY_PRESSED] = "Left";
                   command=2;
                   system->Step(command, _info);
                   break;

                case sf::Keyboard::Enter:
                    system->Clear_Equation_History();
                    break;
               }
               default:
                   break;
           }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sidebar.graphbox.getGlobalBounds().contains(mousePos.x, mousePos.y)) //grab the size of the box and then allow it to click around that coordinate
                {
                    sidebar.graphbox.setFillColor(sf::Color::Green);
                    system->graph_box();
                }
                else
                {
                    sidebar.graphbox.setFillColor(sf::Color::White);
                }
            }

       }
}

  
void animate::update(){
    command=0;
    system->Step(command,_info);
     if (mouseIn){
        
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);

    }

}

void animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}
