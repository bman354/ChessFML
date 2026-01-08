#include <SFML/Graphics.hpp>

const int TILE_SIZE = 64;

enum pieceID {
    EMPTY,
    wPAWN,
    wKING,
    wQUEEN,
    wROOK,
    wBISHOP,
    wKNIGHT,
    bPAWN,
    bKING,
    bQUEEN,
    bROOK,
    bBISHOP,
    bKNIGHT,
};


class Board {
public:
    pieceID boardState[8][8] = {

    { bROOK, bKNIGHT, bBISHOP, bQUEEN, bKING, bBISHOP, bKNIGHT, bROOK },
    { bPAWN, bPAWN, bPAWN, bPAWN, bPAWN, bPAWN, bPAWN, bPAWN },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { wPAWN, wPAWN, wPAWN, wPAWN, wPAWN, wPAWN, wPAWN, wPAWN },
    { wROOK, wKNIGHT, wBISHOP, wQUEEN, wKING, wBISHOP, wKNIGHT, wROOK }

    };

};




int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u, 800u}), "ChessFML");
    window.setFramerateLimit(69);
    
    //init game board
    Board board;
    
    sf::Texture boardTexture("assets/board.png");
    sf::Sprite boardSprite(boardTexture);
    boardSprite.setScale({ 5.0f, 5.0f });
    
   
       
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {

            //event handler
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            //game logic here


        }

        //these render everything
        window.clear();
        window.draw(boardSprite);
        window.display();
    }
}








