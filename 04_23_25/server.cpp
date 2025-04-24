#include "PracticalSocket.h"
#include "suit.h"
#include <string>
#include <iostream>
#include <map>
// lecture activity part b change the suit colors
// https://en.wikipedia.org/wiki/ANSI_escape_code
std::string getFormatStr(suitType suit);

int main(int argc, char *argv[])
{
    TCPServerSocket serverSock(9431);
    for (;;)
    {
        TCPSocket *sock = serverSock.accept();
        uint32_t val;
        if (sock->recvFully(&val, sizeof(val)) == sizeof(val))
        {
            std::cout << "incoming client: " << std::endl;
            val = ntohl(val);
            std::cout << "receiving " << val << std::endl;
            suitType suit = static_cast<suitType>(val);
            std::string response = getFormatStr(suit);
            val = htonl(response.length());
            sock->send(&val, sizeof(val));
            sock->send(response.c_str(), response.length());
        }
        delete sock;
    }
}

std::string getFormatStr(suitType suit)
{
    static std::map<suitType, std::string> suitColors = {{suitType::HEARTS, "\033[1m\033[107;31m"}, {suitType::DIAMONDS, "\033[1m\033[107;31m"}, {suitType::CLUBS, "\033[1m\033[107;30m"}, {suitType::SPADES, "\033[1m\033[107;30m"}};

    return suitColors[suit];
}
