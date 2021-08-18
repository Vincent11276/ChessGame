#include <iostream>
#include <vector>
#include <thread>
#include <SFML/Network.hpp>

#define PORT        53000
#define VISIBILITY  true

class Server
{
public:
    unsigned short port;
    bool isRunning;
    bool isOpen;

    sf::Packet lastPacketReceived;

private:
    std::vector<std::unique_ptr<sf::TcpSocket>> clients;
    sf::SocketSelector selector;
    sf::TcpListener listener;

public:
    Server(unsigned short port=PORT, bool isOpen=VISIBILITY)
    {
        this->port = port;
        this->isOpen = isOpen;
    }

    void run()
    {
        this->onServerReady();
        this->isRunning = true;

        std::thread connThread(&Server::connectClients, this);
        //std::thread mngePcksThread(&Server::managePackets, this);

        connThread.join();
        //mngePcksThread.join();
    }

    void shuttdown()
    {
        this->onServerShutdown();
        this->isRunning = false;
    }

    void connectClient(std::unique_ptr<sf::TcpSocket> client)
    {         
        this->onClientConnect(*client.get());
        this->selector.add(*client.get());
        this->clients.push_back(std::move(client));
    }

    void disconnectClient(std::unique_ptr<sf::TcpSocket> client)
    {
        this->onClientDisconnect(*client.get());
        this->selector.remove(*client.get());
    }

private:
    void checkClientDisconnect()
    {
        
    }
    void connectClients()
    {
        if (this->listener.listen(this->port) != sf::Socket::Done) return;

        while (this->isOpen)
        {
            std::cout << "searchia" << std::endl;
            auto newClient = std::make_unique<sf::TcpSocket>();

            if (listener.accept(*newClient) != sf::Socket::Done)
            { 
                std::cout << "An error occured while accepting the client" << std::endl;
            }
            else connectClient(std::move(newClient));   
        }
        this->listener.close();
    }

    void managePackets()
    {
        while (this->isRunning)
        {
            if (selector.wait())
            {
                auto client = getPreparedClient();

                switch (client->receive(lastPacketReceived))
                {
                case sf::Socket::Done:
                    this->onPacketReceived(*client.get(), lastPacketReceived);
                    std::cout << "server has received a packet" << std::endl;
                    break;

                case sf::Socket::Disconnected:
                    this->onClientDisconnect(*client.get());
                    std::cout << "client has disconnected" << std::endl;
                    break;

                case sf::Socket::Error:
                    std::cout << "An error occured" << std::endl;
                    break;
                }
            }
        }
    }

    std::unique_ptr<sf::TcpSocket> getPreparedClient()
    {
        for (auto &client: this->clients)
        {
            if (this->selector.isReady(*client.get()))
            {
                return std::move(client);
            }
        }
    }

protected:
    // built-in events for overriding
    virtual void onServerReady(){};
    virtual void onServerShutdown(){};
    virtual void onClientConnect(sf::TcpSocket& client){};
    virtual void onClientDisconnect(sf::TcpSocket& client){};
    virtual void onPacketReceived(sf::TcpSocket& client, sf::Packet &packet){};
};