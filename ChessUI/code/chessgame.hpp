#pragma once

#include <SFML/Graphics.hpp>

#include "application.hpp"
#include "boardstyle.hpp"
#include "piecelayout.hpp"
#include "piecestyle.hpp"
#include "tilemap.hpp"


class ChessGame : public Application
{
public:
    ChessGame()
        : Application(sf::VideoMode(1280, 720), "Chess Game - Beta")
    { }

private
    void awake() override
    {
       
    }

    void handleEvents(sf::Event &event) override
    {
        
    }

    void update(float dt) override
    {

    }

    void draw(sf::RenderWindow &window) override
    {

    }
};


// class ChessGame : public sf::Drawable, public sf::Transformable
// {
// private:
//     BoardStyle boardStyle;

// public:
//     ChessGame()
//     {
        
//     }

//     ChessGame(BoardStyle p_boardStyle, PieceStyle p_pieceStyle, PieceLayout p_layout)
//         : m_tilemap(sf::Vector2i(8, 8), sf::Vector2f(80, 80))
//     {
//         this->setBoardStyle(p_boardStyle);
//         this->setPieceStyle(p_pieceStyle);
//         this->initPieceLayout(p_layout);

//         this->m_tilemap.setPosition(20, 22);
//     }

//     void setBoardStyle(BoardStyle p_boardStyle)
//     {
//         static std::unordered_map<BoardStyle, std::string> fetchedPaths
//         {
//             { BoardStyle::Wood, "Assets/Chess_Artwork/Chess Board/Wood/Chess_Board.png"},
//             { BoardStyle::StoneBlack, "Assets/Chess_Artwork/Chess Board/Stone Black/Chess_Board_Stone.png"},
//             { BoardStyle::StoneBlue, "Assets/Chess_Artwork/Chess Board/Stone Blue/Chess_Board_Stone3.png"},
//             { BoardStyle::StoneGrey, "Assets/Chess_Artwork/Chess Board/Stone Grey/Chess_Board_Stone2.png"},
//             { BoardStyle::WoodNoLabel, "Assets/Chess_Artwork/Chess Board/Wood/Chess_Board_wood_nolabel.png"},
//             { BoardStyle::StoneBlackNoLabel, "Assets/Chess_Artwork/Chess Board/Stone Black/Chess_Board_Stone_nolabel.png"},
//             { BoardStyle::StoneBlueNoLabel, "Assets/Chess_Artwork/Chess Board/Stone Blue/Chess_Board_Stone3_nolabel.png"},
//             { BoardStyle::StoneGreyNoLabel, "Assets/Chess_Artwork/Chess Board/Stone Grey/Chess_Board_Stone2_nolabel.png"}
//         };

//         static sf::Texture texture;

//         if (texture.loadFromFile(fetchedPaths[p_boardStyle]))
//         {
//             this->m_boardSpr.setTexture(texture);
//         }
//     }

//     void setPieceStyle(PieceStyle p_pieceLayout)
//     {
//         static std::unordered_map<PieceStyle, std::string> fetchedPaths
//         {
//             { PieceStyle::StonePiece, "Assets/Chess_Artwork/Chess Pieces/Stone"},
//             { PieceStyle::StoneSymbol, "Assets/Chess_Artwork/Chess Symbols/Stone"},
//             { PieceStyle::WoodPiece, "Assets/Chess_Artwork/Chess Pieces/Wood"},
//             { PieceStyle::WoodSymbol, "Assets/Chess_Artwork/Chess Symbols/Wood"},
//         };
//         this->m_tilemap.loadFromDirectory(fetchedPaths[p_pieceLayout]);
//     }

//     void initPieceLayout(PieceLayout p_layout)
//     {
//         switch (p_layout)
//         {
//         case PieceLayout::Black:
//             this->setBlack();
//             break;
        
//         case PieceLayout::White:
//             this->setWhite();
//             break;

//         default:
//             break;
//         }
//     }

//     void setBlack()
//     {
//         std::vector<std::vector<int>> pieces 
//         {
//             {11,  5, 11,  3,  9, 11,  5, 11},
//             {07, 07, 07, 07, 07, 07, 07, 07},
//             {-1, -1, -1, -1, -1, -1, -1, -1},
//             {-1, -1, -1, -1, -1, -1, -1, -1},
//             {-1, -1, -1, -1, -1, -1, -1, -1},
//             {-1, -1, -1, -1, -1, -1, -1, -1},           
//             {06, 06, 06, 06, 06, 06, 06, 06},
//             {10,  4, 10,  2,  8, 10,  4, 10}
//         };
//         this->m_tilemap.mapCellsFrom(pieces);
//     }

//     void setWhite()
//     {
//         std::vector<std::vector<int>> pieces 
//         {
//             {10,  4, 10,  8,  2, 10,  4, 10}, 
//             { 6,  6,  6,  6,  6,  6,  6,  6},         
//             {-1, -1, -1, -1, -1, -1, -1, -1},
//             {-1, -1, -1, -1, -1, -1, -1, -1},
//             {-1, -1, -1, -1, -1, -1, -1, -1},
//             {-1, -1, -1, -1, -1, -1, -1, -1}, 
//             { 7,  7,  7,  7,  7,  7,  7,  7},                         
//             {11,  5, 11,  9,  3, 11,  5, 11}
//         };
//         this->m_tilemap.mapCellsFrom(pieces);
//     }

//     void handleEvents(sf::Event &p_event)
//     {            
//         switch (p_event.type)
//         {
//         case sf::Event::MouseMoved:
//             this->onMouseMoved(p_event.mouseMove.x, p_event.mouseMove.y);
//             break;

//         case sf::Event::MouseButtonPressed:
//             this->onMousePressed(p_event.mouseButton.button);
//             break;
        
//         case sf::Event::MouseButtonReleased:
//             this->onMouseReleased(p_event.mouseButton.button);
//             break;

//         default:
//             break;
//         }
//     }

// private:

//     sf::Vector2i tileCoords;

//     void onMouseMoved(int x, int y)
//     {
//         sf::Vector2i tilemapPos(this->m_tilemap.getPosition());

//         sf::Vector2i localMouse(this->getLocalMouse(x, y));

//         this->tileCoords = this->m_tilemap.worldToMap(localMouse - tilemapPos);     
//     }

//     void onMousePressed(sf::Mouse::Button button)
//     {
//         this->m_tilemap.remove(tileCoords); 
//     }

//     void onMouseReleased(sf::Mouse::Button button)
//     {

//     }

//     sf::Vector2i getLocalMouse(int x, int y)
//     {
//         return sf::Vector2i(sf::Vector2f(x, y) - this->getPosition());
//     }

//     sf::Sprite m_boardSpr;
//     TileMap m_tilemap;

//     virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
//     {
//         states.transform *= getTransform();

//         target.draw(m_boardSpr, states);

//         target.draw(m_tilemap, states);
//     }
// };