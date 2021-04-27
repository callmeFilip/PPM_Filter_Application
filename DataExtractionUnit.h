#ifndef DATA_EXTRACTION_UNIT_H
#define DATA_EXTRACTION_UNIT_H

/**
 * DataExtractionUnit.h
 * Responsible for extracting data from .ppm file.
 * Fills the data in std::vector<std::string>.
*/

#include <string>
#include <vector>
#include <fstream>

class DataExtractionUnit
{
private:
    static DataExtractionUnit m_instance;
    std::string m_filePath;

    DataExtractionUnit() {}
    DataExtractionUnit(const DataExtractionUnit &);
    void operator=(DataExtractionUnit const &);

public:
    static DataExtractionUnit *getInstance() { return &m_instance; }

    void readFile(std::vector<std::string> &container, std::ifstream &fileStream) const; // extracts data from file's header to vector<string>
};

#endif // DATA_EXTRACTION_UNIT_H
