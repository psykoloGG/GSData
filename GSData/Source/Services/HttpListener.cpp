#include "HttpListener.h"

#include <boost/bind.hpp>
#include<boost/make_shared.hpp>

HttpListener::HttpListener(unsigned int port) : acceptor(ioService, tcp::endpoint(tcp::v4(), port))
{
}

HttpListener::~HttpListener()
{
    if (sThread)
    {
        sThread->join();
    }
}

void HttpListener::Run()
{
    sThread.reset(new boost::asio::detail::thread(boost::bind(&HttpListener::threadMain, this)));
}

void HttpListener::threadMain()
{
    startAccept();
    ioService.run();
}

void HttpListener::startAccept()
{
    boost::shared_ptr<Request> request = boost::make_shared<Request>(*this);
    acceptor.async_accept(*request->socket,
                          boost::bind(&HttpListener::handleAccept, this, request, boost::asio::placeholders::error));
}

void HttpListener::handleAccept(const boost::shared_ptr<Request>& request, const boost::system::error_code& errorCode)
{
    if (!errorCode)
    {
        request->Answer();
    }
    startAccept();
}
