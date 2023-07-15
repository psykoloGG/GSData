#include "CSGOGame.h"

CSGOGame::CSGOGame()
{
    name = "Counter-Strike: Global Offensive";
    iconPath = std::string(PROJECT_DIR) + "Vendor\\Icons\\csgo.jpg";
    LoadIcon();
}
