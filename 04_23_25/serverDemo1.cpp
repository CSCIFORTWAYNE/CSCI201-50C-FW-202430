#include "PracticalSocket.h"
#include <iostream>

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
            std::cout << val << std::endl;
            val++;
            val = htonl(val);
            sock->send(&val, sizeof(val));
        }
        delete sock;
    }
}