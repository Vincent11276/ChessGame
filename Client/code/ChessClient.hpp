#include <iostream>
using namespace std;

#include "SFMLClient.hpp"


class ChessClient : public SFMLClient
{
public:
    sf::IpAddress   serverIP    = sf::IpAddress::getLocalAddress();
    unsigned short  serverPort  = 53000;

    ChessClient()
    {

    }

    void start()
    {
        this->run(serverIP, serverPort);
    }
private:
    void onConnect(sf::TcpSocket &server) override
    {
        std::cout << "Succesfully connected to the server " << "(" << server.getRemoteAddress() << ")!" << std::endl;
    }
};