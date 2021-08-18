#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "ChessServer.hpp"



int main()
{
    ChessServer server;
    server.run();
    
    std::cin.get();

    return EXIT_SUCCESS;
}
