#include "HTTPRequest.hpp"
#include <iostream>

int main()
{
    try
    {
        http::Request request{"http://acme.com/onemonth/"};
        const http::Response response = request.send("GET");
        std::cout << std::string(response.body.begin(), response.body.end()) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }
}