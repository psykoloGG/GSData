#include "OpenGLUtils.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_resize.h"

#define GL_CLAMP_TO_EDGE 0x812F

bool OpenGLUtils::PrepareTextureFromFile(const char* fileUrl, GLuint* outTexture, int* outWidth, int* outHeight)
{
    //Load image
    int iconHeight = 0;
    int iconWidth = 0;
    constexpr int iconChannels = 4;
    const unsigned char* icon = stbi_load(fileUrl, &iconWidth, &iconHeight, nullptr, iconChannels);
    if (icon == nullptr)
    {
        return false;
    }

    //Resize image
    constexpr int resizedIconHeight = 15;
    constexpr int resizedIconWidth = 15;
    unsigned char* resizedIcon = static_cast<unsigned char*>(malloc(resizedIconWidth * resizedIconHeight * iconChannels));
    stbir_resize_uint8(icon, iconWidth, iconHeight, 0, resizedIcon, resizedIconWidth, resizedIconHeight, 0, 4);

    //Load image into GPU
    GLuint imageTexture;
    glGenTextures(1, &imageTexture);
    glBindTexture(GL_TEXTURE_2D, imageTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

#if defined(GL_UNPACK_ROW_LENGTH)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, resizedIconWidth, resizedIconHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 resizedIcon);

    *outTexture = imageTexture;
    *outWidth = resizedIconWidth;
    *outHeight = resizedIconHeight;
    return true;
}
