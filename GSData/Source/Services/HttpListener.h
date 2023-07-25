#pragma once

#include "Request.h"

using boost::asio::ip::tcp;

class Request;

class HttpListener 
{
public:
    HttpListener(unsigned int port);
    ~HttpListener();

    void Run();

    boost::asio::io_service ioService;

private:
    void threadMain();
    void startAccept();
    void handleAccept(const boost::shared_ptr<Request>& request, const boost::system::error_code& errorCode);
    
    tcp::acceptor acceptor;
    boost::shared_ptr<boost::asio::detail::thread> sThread;
};
