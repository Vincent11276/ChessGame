#pragma once

#include <iostream>
#include <SFML/Network.hpp>
#include <thread>
using namespace std;



class SFMLClient
{
private:
    sf::TcpSocket server;
    sf::IpAddress serverIpAddr;
    unsigned short serverPort;

    bool connect(sf::IpAddress &ipAddr, unsigned short port, sf::Time timeout = sf::Time::Zero)
    {
        if (server.connect(ipAddr, port, timeout) == sf::Socket::Done)
        { 
            this->onConnect(server);
            return true;
        }
        return false;
    }

    void managePackets()
    {
        while (this->isRunning)
        {
            sf::Packet packet;

            switch (server.receive(packet))
            {
            case sf::Socket::Done:
                this->onPacketReceived(server, packet);
                std::cout << "server has received a packet" << std::endl;
                break;

            case sf::Socket::Disconnected:
                this->onConnectionLost(server);
                std::cout << "client has disconnected" << std::endl;
                break;

            case sf::Socket::Error:
                std::cout << "An error occured" << std::endl;
                break;
            }
        } 
    }
    
public:
    bool isRunning;

    SFMLClient()
    {
        // default..
    }

    ~SFMLClient()
    {
        this->disconnect();
        this->onDestruct();
    }

    void run(sf::IpAddress &ipAddr, unsigned short port, sf::Time timeout = sf::Time::Zero)
    {
        this->isRunning = true;
        this->connect(ipAddr, port, timeout);
        std::thread mngePcksThread(&SFMLClient::managePackets, this);
        mngePcksThread.join();
        this->onRun();
    }


    void stop()
    {
        this->isRunning = false;
        this->onStop();
    }

    void disconnect()
    {   
        server.disconnect();
        this->onDisconnect();
    }

    void sendPacket(sf::Packet &packet)
    {
        if (server.send(packet) != sf::Socket::Done)
            { std::cout << "An error occured while sending data" << std::endl; return;};
        this->onPacketSent(packet);
    }

protected:
    virtual void onCreate(){}
    virtual void onDestruct(){}
    virtual void onRun(){}
    virtual void onStop(){}
    virtual void onConnect(sf::TcpSocket &server){}
    virtual void onDisconnect(){}
    virtual void onPacketReceived(sf::TcpSocket &server, sf::Packet &packet){};
    virtual void onPacketSent(sf::Packet &packet){};
    virtual void onConnectionLost(sf::TcpSocket &server){};
};