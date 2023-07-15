#include "Dota2Game.h"

Dota2Game::Dota2Game()
{
    name = "Dota 2";
    iconPath = std::string(PROJECT_DIR) + "Vendor\\Icons\\dota2.png";
    LoadIcon();
}
