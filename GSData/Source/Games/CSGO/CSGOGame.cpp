#include "CSGOGame.h"

#include <iostream>

CSGOGame::CSGOGame()
{
    name = "Counter-Strike: Global Offensive";
    iconPath = std::string(PROJECT_DIR) + "Vendor\\Icons\\csgo.jpg";
    LoadIcon();

    std::cout << "started";

    //For testing
    listener = new HttpListener(3000);
    listener->Run();
}
