#include "FilterApplier.h"
#include "ConvolutionUnit.h"

#include <cstdlib>

FilterApplier FilterApplier::m_instance;

RGBImage *FilterApplier::applyFilter(Filter *fil, const RGBImage *img) const
{
    RGBImage *result = new RGBImage();

    {
        int realValue = fil->getHeight() - img->m_height;
        const size_t resultHeight = abs(realValue) + 1; // gets the absolute value of height1 - height2

        realValue = fil->getWidth() - img->m_width;
        const size_t resultWidth = abs(realValue) + 1; // gets the absolute value of height1 - height2

        result->m_height = resultHeight;
        result->m_width = resultWidth;
    }

    // apply red filter
    result->m_red = ConvolutionUnit::getInstance()->convolution(
        img->m_red,
        img->m_height,
        img->m_width,
        img->m_maxValue,
        fil->getFilter(),
        fil->getHeight(),
        fil->getWidth(),
        fil->getDivider());

    result->m_green = ConvolutionUnit::getInstance()->convolution(
        img->m_green,
        img->m_height,
        img->m_width,
        img->m_maxValue,
        fil->getFilter(),
        fil->getHeight(),
        fil->getWidth(),
        fil->getDivider());

    result->m_blue = ConvolutionUnit::getInstance()->convolution(
        img->m_blue,
        img->m_height,
        img->m_width,
        img->m_maxValue,
        fil->getFilter(),
        fil->getHeight(),
        fil->getWidth(),
        fil->getDivider());

    result->m_maxValue = img->m_maxValue;

    return result;
}
