#include "Request.h"

#include <iostream>
#include <boost/bind.hpp>

Request::Request(HttpListener& server) : server(server)
{
    socket.reset(new tcp::socket(server.ioService));
}

void Request::Answer()
{
    if (!socket)
    {
        return;
    }

    async_read_until(*socket, request, "\r\n\r\n",
                                  boost::bind(&Request::AfterRead, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Request::AfterRead(const boost::system::error_code errorCode, std::size_t bytesTransferred)
{
    //Gamestate data in raw form
    const auto data = boost::asio::buffer_cast<const char*>(request.data());
    
    socket->close();
}
