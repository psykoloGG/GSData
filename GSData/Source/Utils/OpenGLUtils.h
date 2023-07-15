#pragma once

#include "windows.h"
#include "gl/GL.h"

class OpenGLUtils
{
public:
    static bool PrepareTextureFromFile(const char* fileUrl, GLuint* outTexture, int* outWidth, int* outHeight);
};
