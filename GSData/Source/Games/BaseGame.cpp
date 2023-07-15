#include "BaseGame.h"

#include <iostream>

#include "OpenGLUtils.h"

const GameIcon* BaseGame::GetGameIcon() const
{
    return &gameIcon;
}

const char* BaseGame::GetName() const
{
    return name;
}

void BaseGame::LoadIcon()
{
    bool imageLoaded = OpenGLUtils::PrepareTextureFromFile(iconPath.c_str(), &gameIcon.iconTexture, &gameIcon.iconWidth, &gameIcon.iconHeight);
}

