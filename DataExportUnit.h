#ifndef DATAEXPORTUNIT_H
#define DATAEXPORTUNIT_H

/**
 * DataExportUnit.h
 * Responsible for exporting RGBImage * to .ppm file.
*/

#include "RGBImage.h"

#include <fstream>

class DataExportUnit
{
private:
    static DataExportUnit m_instance;
    DataExportUnit() {}
    DataExportUnit(const DataExportUnit &);
    void operator=(DataExportUnit const &);

public:
    static DataExportUnit *getInstance() { return &m_instance; }
    void exportImage(std::ofstream &os, RGBImage *img);
};

#endif // DATAEXPORTUNIT_H
