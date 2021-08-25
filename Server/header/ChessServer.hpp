#include <iostream>
using namespace std;

#include <SFML/Network.hpp>
#include "server.hpp"



class ChessServer : public Server
{
public:
    std::string name;
    uint32_t maxClients;

private:
    virtual void onServerReady() override
    {
        std::cout << "Server has started on port" << port << std::endl;
    }

    virtual void onServerShutdown() override
    {
        std::cout << "Server has been stopped" << std::endl;
    }

    virtual void onClientConnect(sf::TcpSocket& client) override
    {
        std::cout << "A new connection from " << client.getRemoteAddress() << ":" << client.getRemoteAddress() << "has established";
    }
};