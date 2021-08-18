#pragma once

#include <iostream>
#include <SFML/Network.hpp>
using namespace std;



class Client
{
private:
    sf::TcpSocket server;

public:
    Client()
    {
        
    }

    void connect(sf::IpAddress ipAddr, unsigned short port, sf::Time timeout = sf::Time::Zero)
    {
        if (server.connect(ipAddr, port, timeout) != sf::Socket::Done)
            { std::cout << "An error occured whilst connecting to to the server" << std::endl; return;};
    }

    void disconnect()
    {
        server.disconnect();
    }
};