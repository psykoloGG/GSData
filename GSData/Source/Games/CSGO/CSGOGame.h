#pragma once

#include "HttpListener.h"
#include "../BaseGame.h"

class CSGOGame : public BaseGame
{
public:
    CSGOGame();
private:
    HttpListener* listener;
};
