#include "PracticalSocket.h"
#include "suit.h"
#include <iostream>
#include <limits>
#include <map>
#include <string>

void resetStream();

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./client <server ip address>" << std::endl;
        return 1;
    }
    std::map<suitType, std::string> suitSymbols;
    suitSymbols[suitType::CLUBS] = "♣";
    suitSymbols[suitType::DIAMONDS] = "♦";
    suitSymbols[suitType::HEARTS] = "♥";
    suitSymbols[suitType::SPADES] = "♠";
    std::map<int, suitType> suitNumbers;
    suitNumbers[1] = suitType::HEARTS;
    suitNumbers[2] = suitType::SPADES;
    suitNumbers[3] = suitType::CLUBS;
    suitNumbers[4] = suitType::DIAMONDS;

    try
    {
        TCPSocket sock(argv[1], 9431);
        int input = 0;
        int i = 1;
        std::cout << "Pick a suit: " << std::endl;
        for (auto it = suitSymbols.begin(); it != suitSymbols.end(); ++it)
        {
            std::cout << i++ << ": " << it->second << std::endl;
        }
        std::cin >> input;
        while (!std::cin || input < 1 || input > 4)
        {
            if (!std::cin)
            {
                resetStream();
            }
            i = 1;
            std::cout << "Pick a suit: " << std::endl;
            for (auto it = suitSymbols.begin(); it != suitSymbols.end(); ++it)
            {
                std::cout << i++ << ": " << it->second << std::endl;
            }
            std::cin >> input;
        }
        suitType suit = suitNumbers[input];
        uint32_t val = static_cast<uint32_t>(suit);
        val = htonl(val);
        sock.send(&val, sizeof(val));
        if (sock.recvFully(&val, sizeof(val)) == sizeof(val))
        {
            val = ntohl(val);
            char *buffer = new char[val + 1];
            if (sock.recvFully(buffer, val) == val)
            {
                buffer[val] = '\0';
                std::cout << "Server Response: " << buffer << suitSymbols[suit] << std::endl;
            }
        }
        sock.close();
    }
    catch (SocketException &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}