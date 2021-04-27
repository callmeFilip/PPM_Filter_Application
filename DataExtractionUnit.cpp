#include "DataExtractionUnit.h"

#include <iostream>

DataExtractionUnit DataExtractionUnit::m_instance;

void DataExtractionUnit::readFile(std::vector<std::string> &container, std::ifstream &fileStream) const
{

    if (!fileStream.is_open())
    {
        std::cout << "File is not open!" << std::endl;
        return;
    }

    std::string line = "";

    // extract the data from .PPM file in string vector
    while (std::getline(fileStream, line))
    {
        container.push_back(line);
    }
}
