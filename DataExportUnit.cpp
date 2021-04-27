#include "DataExportUnit.h"

DataExportUnit DataExportUnit::m_instance;

void DataExportUnit::exportImage(std::ofstream &os, RGBImage *img)
{
    os << img->m_format << "\n"
       << img->m_width << " " << img->m_height << "\n"
       << img->m_maxValue << std::endl;

    for (size_t j = 0; j < img->m_height; j++)
    {
        for (size_t i = 0; i < img->m_width; i++)
        {
            os << img->m_red[j][i] << " "
               << img->m_green[j][i] << " "
               << img->m_blue[j][i] << "\n";
        }
    }

    os << std::endl;
}
