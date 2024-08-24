#include "sidebar.h"
#include "constants.h"

Sidebar::Sidebar(){

}

Sidebar::Sidebar(Graph_Info* infos):_info(infos){
    cout<<"Sidebar CTOR: TOP"<<endl;
    items.reserve(50);
    rect.setFillColor(sf::Color(204,225,151)); //(192,192,192)); //silver
    rect.setPosition(sf::Vector2f( _info->Side_Bar.x, 0));
    rect.setSize(sf::Vector2f(_info->Side_Bar.x, _info->Side_Bar.y));
    cout<<"Sidebar CTOR: about to load font."<<endl;
    
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    //the font file must be in the "working directory"
    // check projects->run->working directory
    //      [Make sure it's not pointing to the app file]
     
    textbox.setFillColor(sf::Color(211, 211, 211));
    textbox.setPosition(sf::Vector2f(1150, 5)); //equation box 
    textbox.setSize(sf::Vector2f(220, 40));

    graphbox.setFillColor(sf::Color::White);
    graphbox.setPosition(sf::Vector2f(1150, 395)); //graph here box 
    graphbox.setSize(sf::Vector2f(220, 40));

    equationbox.setFillColor(sf::Color(153, 204, 255));
    equationbox.setPosition(sf::Vector2f(1150, -20)); //box history 
    equationbox.setSize(sf::Vector2f(220, 400));

    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout<<"Sidebar CTOR: loaded font."<<endl;

    //. . . . . text / font problems: . . . . . . . .
    //initializing text object in this way caused problems
    // (hangs!)
    //only when sb_text was a private member and worked fine
    //when it was a public member. Probably not releavant,
    //but still strange!
    //
    //sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout<<"Sidebar CTOR: Text object initialized."<<endl;
    sb_text.setFont(font);
    sb_text.setCharacterSize(20);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setFillColor(sf::Color::Yellow);

    ////this is how you would position text on screen:
    //sb_text.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-sb_text.getLocalBounds().height-5));

    items.push_back("sidebar sample text");
    //Fill the items vector with empty strings so that we can use [] to read them:
    for (int i=0 ; i<30; i++){
        items.push_back("");
    }
    cout<<"Sidebar: CTOR: Exit."<<endl;
}

void Sidebar::draw(sf::RenderWindow& window){
    const double VERTICAL_LINE_SPACING = 5.0;
    const double LEFT_MARGIN = 10.0;
    window.draw(rect);
    window.draw(equationbox);
    window.draw(textbox);
    window.draw(graphbox);
    float height = 10;
}

void Sidebar::text_font(sf::RenderWindow& window, sf::Text &text){
    window.draw(text); //eqation input 
}

void Sidebar::equation_history(sf::RenderWindow& window){
        sf::Font font;
        sf::Text text;
        font.loadFromFile("arial.ttf");

        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);

        ifstream myfile;
        myfile.open("equation_history.txt");
        string line;
        int i = 0;
        while (getline(myfile, line))
        {
            text.setString(line);
            text.setPosition(_info->Screen_Size.x - 160, 50 + i * 30 );  //write out the string in that position 
            window.draw(text);
            i++;
        }
        myfile.close();
}

string& Sidebar::operator [](int index){
    return items[index];
}


void Sidebar:: text_box(sf::RenderWindow& window){
    sf::Font font;
    sf::Text text;
    font.loadFromFile("arial.ttf");

    text.setFont(font);
    text.setCharacterSize(20);        // just the text 
    text.setFillColor(sf::Color::Black);

    text.setString("Graph Here!");
    text.setPosition(_info->Side_Bar.x+90, 400);
    window.draw(text);
}