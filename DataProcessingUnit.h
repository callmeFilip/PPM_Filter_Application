#ifndef DATA_PROCESSING_UNIT_H
#define DATA_PROCESSING_UNIT_H

/**
 * DataProcessingUnit.h
 * Responsible for processing the data, after it is extracted.
 * Takes vector<string> and returns RGBImage *.
*/

#include "RGBImage.h"

#include <string>
#include <vector>

class DataProcessingUnit
{
private:
    static DataProcessingUnit m_instance;

    DataProcessingUnit() {}
    DataProcessingUnit(const DataProcessingUnit &);
    void operator=(DataProcessingUnit const &);

    void parse(std::vector<std::string> &container) const;
    void processHeader(const std::vector<std::string> &container, RGBImage *img) const;
    void processBody(const std::vector<std::string> &container, RGBImage *img) const;
    int extractDimensions(const std::string line, size_t &width, size_t &height) const;
    int extractMaxValue(const std::string line, size_t &maxValue) const;
    void cleanup(RGBImage *img) const;

public:
    static DataProcessingUnit *getInstance() { return &m_instance; }
    RGBImage *processData(std::vector<std::string> &container) const;
};

#endif // DATA_PROCESSING_UNIT_H
