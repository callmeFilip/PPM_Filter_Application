#ifndef RUNNER_H
#define RUNNER_H

/**
 * Runner.h
 * Responsible for running the different filters,
 * according to the input.
*/

#include "Filter.h"

#include <string>

class Runner
{
private:
public:
    void run(std::string &inputFile, std::string &outputFile, Filter *filter) const;
};

#endif // RUNNER_H
