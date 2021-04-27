#include "Runner.h"
#include <vector>
#include <string>
#include <fstream>

#include "DataExtractionUnit.h"
#include "DataProcessingUnit.h"
#include "DataExportUnit.h"
#include "FilterApplier.h"
#include "RGBImage.h"

void Runner::run(std::string &inputFile, std::string &outputFile, Filter *filter) const
{
    std::vector<std::string> container;
    std::ifstream in(inputFile); // TODO user input

    DataExtractionUnit::getInstance()->readFile(container, in); // extract data from file

    RGBImage *img = DataProcessingUnit::getInstance()->processData(container); // extract rgb values from data

    RGBImage *filteredImage = FilterApplier::getInstance()->applyFilter(filter, img);

    std::ofstream out(outputFile);
    DataExportUnit::getInstance()->exportImage(out, filteredImage);

    // memory cleanup
    container.clear();
    container.shrink_to_fit();

    out.close();

    delete img;
    delete filteredImage;
}
