#ifndef RGBIMAGE_H
#define RGBIMAGE_H

/**
 * RGBImage.h
 * Responsible for storing the image paramers.
*/

#include <cstddef>
#include <string>

struct RGBImage
{
public:
    int **m_red;
    int **m_green;
    int **m_blue;

    size_t m_width;
    size_t m_height;
    size_t m_maxValue;

    std::string m_format;

    RGBImage()
        : m_red(0), m_green(0), m_blue(0), m_width(0), m_height(0), m_format("P3") {}

    ~RGBImage()
    {
        for (size_t i = 0; i < m_height; i++)
        {
            delete[] m_red[i];
            delete[] m_green[i];
            delete[] m_blue[i];
        }

        delete[] m_red;
        delete[] m_green;
        delete[] m_blue;

        m_red = 0;
        m_green = 0;
        m_blue = 0;
    }
};

#endif // RGBIMAGE_H
