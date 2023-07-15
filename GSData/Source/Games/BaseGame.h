#pragma once
#include <string>

#include "windows.h"
#include "gl/GL.h"

struct GameIcon
{
    int iconWidth = 0;
    int iconHeight = 0;
    GLuint iconTexture = 0;
};

//Might refactor later for Valve specific games sharing same format
class BaseGame
{
public:
    const GameIcon* GetGameIcon() const;
    const char* GetName() const;
    
protected:
    void LoadIcon();
    
    const char* name = nullptr;
    std::string iconPath;
    GameIcon gameIcon;
};
