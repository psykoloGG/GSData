#pragma once
#include <array>

#include "Games/BaseGame.h"

class Application
{
public:
    Application();
    void RenderUI();

private:
    void RenderGamesDropdown();
    void RenderMainLayout();

    //Supported games will be hardcoded, maybe vector for easier addition
    //and less need for tracking of the number
    std::array<BaseGame*, 2> supportedGames{};
};
