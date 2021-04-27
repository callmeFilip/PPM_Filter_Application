#include "DataProcessingUnit.h"

#include <cassert>
#include <iostream>

DataProcessingUnit DataProcessingUnit::m_instance;

int DataProcessingUnit::extractMaxValue(const std::string line, size_t &maxValue) const
{
    if (line.empty())
    {
        maxValue = 0;
        return 0;
    }

    maxValue = std::stoi(line.substr(0));

    return 1;
}

int DataProcessingUnit::extractDimensions(const std::string line, size_t &width, size_t &height) const
{

    size_t separatorIndex = line.find(' ');

    if (separatorIndex == std::string::npos)
    {
        width = 0;
        height = 0;
        return 0;
    }
    else
    {
        width = std::stoi(line.substr(0, separatorIndex));
        height = std::stoi(line.substr(separatorIndex));
    }

    return 1;
}

void DataProcessingUnit::processHeader(const std::vector<std::string> &container, RGBImage *img) const
{
    int dimensionsFound = extractDimensions(container[1], img->m_width, img->m_height);
    int maxValueFound = extractMaxValue(container[2], img->m_maxValue);

    if (!dimensionsFound || !maxValueFound)
    {
        std::cout << "Invalid header!" << std::endl;

        img->m_width = 0;
        img->m_height = 0;

        return;
    }
}

void DataProcessingUnit::parse(std::vector<std::string> &container) const
{
    // removes the comments and new lines

    size_t commentIndex = 0;
    int spaceCounter = 0;
    for (size_t i = 0; i < container.size(); i++)
    {
        commentIndex = container[i].find('#');
        if (commentIndex != std::string::npos)
        {
            container[i].erase((container[i].begin()) + commentIndex, container[i].end());
        }

        if (container[i].empty())
        {
            container.erase(container.begin() + i--);
            continue;
        }

        // removes duplicating ' ' symbols
        for (size_t symbol = 0; symbol < container[i].size(); symbol++)
        {
            if (container[i][symbol] == ' ')
            {
                spaceCounter++;
                if (spaceCounter > 1)
                {
                    container[i].erase(container[i].begin() + (symbol--)); // removes the duplicating ' ' and shifts the index backwards to compencate
                    spaceCounter = 1;
                }
            }
            else
            {
                spaceCounter = 0;
            }
        }
    }
}

void DataProcessingUnit::cleanup(RGBImage *img) const
{
    delete img;
    assert(false);
}

void DataProcessingUnit::processBody(const std::vector<std::string> &container, RGBImage *img) const
{
    // creates the rgb matrices and binds them to the RGBImage struct
    int **redMatrix = new int *[img->m_height] { 0 };
    for (size_t i = 0; i < img->m_height; i++)
    {
        redMatrix[i] = new int[img->m_width]{0};
    }

    int **greenMatrix = new int *[img->m_height] { 0 };
    for (size_t i = 0; i < img->m_height; i++)
    {
        greenMatrix[i] = new int[img->m_width]{0};
    }

    int **blueMatrix = new int *[img->m_height] { 0 };
    for (size_t i = 0; i < img->m_height; i++)
    {
        blueMatrix[i] = new int[img->m_width]{0};
    }

    if (redMatrix == 0 || blueMatrix == 0 || greenMatrix == 0)
    {
        std::cout << "Not enough memory!" << std::endl;
    }

    img->m_red = redMatrix;
    img->m_green = greenMatrix;
    img->m_blue = blueMatrix;

    // fill the matrices
    int currentRow = 0;
    int currentElement = 0;
    size_t separatorIndex = 0;
    size_t lastSeparator = 0;

    for (size_t line = 3; line < container.size(); line++) // starts from 4th row and reads the vector (container[3])
    {
        separatorIndex = container[line].find(' ');
        if (separatorIndex == std::string::npos)
        {
            std::cout << "Invalid body!" << std::endl;
            cleanup(img);
            return;
        }

        // extract red value
        img->m_red[currentRow][currentElement] = std::stoi(container[line].substr(0, separatorIndex));

        // extract green value
        lastSeparator = separatorIndex;
        separatorIndex = container[line].find(' ', lastSeparator + 1);
        if (separatorIndex == std::string::npos)
        {
            std::cout << "Invalid body!" << std::endl;
            cleanup(img);
            return;
        }

        img->m_green[currentRow][currentElement] = std::stoi(container[line].substr(lastSeparator + 1, separatorIndex));

        // extract blue value
        lastSeparator = separatorIndex;
        separatorIndex = container[line].find(' ', lastSeparator + 1);
        if (separatorIndex == std::string::npos)
        {
            img->m_blue[currentRow][currentElement] = std::stoi(container[line].substr(lastSeparator + 1, container[line].size()));
        }
        else
        {
            img->m_blue[currentRow][currentElement] = std::stoi(container[line].substr(lastSeparator + 1, separatorIndex));
        }

        separatorIndex = 0;
        lastSeparator = 0;

        currentElement++;

        if ((img->m_width - currentElement) == 0) // if its the last element of the row go to the next row
        {
            currentElement = 0;
            currentRow++;
        }
    }
}

RGBImage *DataProcessingUnit::processData(std::vector<std::string> &container) const
{
    RGBImage *img = new RGBImage();
    parse(container);

    if (img == 0)
    {
        std::cout << "Not enough memory!" << std::endl;
        return 0;
    }

    processHeader(container, img);

    processBody(container, img);

    return img;
}
