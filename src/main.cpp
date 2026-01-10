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

    pieceID getPiece(int x, int y);
    void renderBoard(sf::RenderWindow &window);

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
    
    //should put piece loading in a function after i finish
    sf::Texture bPAWNTexture("assets/b_pawn.png");
    sf::Sprite bPAWNSprite(bPAWNTexture);
    bPAWNSprite.setScale({ 5.0f, 5.0f });
       
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {

            //event handler
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }



        }
        //game logic here

        board.boardState[0][0];



        //rendering logic here
        window.clear();
        
        

        board.renderBoard(window);






        window.display();
    }
}


pieceID Board::getPiece(int x, int y) {
    return this->boardState[y][x];
}

void Board::renderBoard(sf::RenderWindow &window){
    window.draw(boardSprite);
    /*
        Loop through all 64 squares
        switch(piece):
            case bROOK:
                window.draw(bRookTexture, x*100, y*100)
                break
            case bKNIGHT:
                etc etc etc



    */


}





