#pragma once

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "HttpListener.h"

using boost::asio::ip::tcp;

class HttpListener;

class Request : public boost::enable_shared_from_this<Request>
{
public:
    Request(HttpListener& server);

    void Answer();
    
    boost::shared_ptr<tcp::socket> socket;
private:
    void AfterRead( const boost::system::error_code errorCode, std::size_t bytesTransferred);
    void AfterWrite( const boost::system::error_code& errorCode, std::size_t bytesTransferred);
    
    HttpListener& server;
    boost::asio::streambuf request;
};
