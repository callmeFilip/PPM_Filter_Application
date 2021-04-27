#ifndef CONVOLUTION_UNIT_H
#define CONVOLUTION_UNIT_H

/**
 * ConvolutionUnit.h
 * Responsible for the convolution between two matrices.
*/

#include <cstddef>

class ConvolutionUnit
{
private:
    static ConvolutionUnit m_instance;

    ConvolutionUnit() {}
    ConvolutionUnit(const ConvolutionUnit &);
    void operator=(ConvolutionUnit const &);

public:
    ~ConvolutionUnit() {}

    static ConvolutionUnit *getInstance() { return &m_instance; }

    // always apply the bigger matrix first!
    // The second element is the filter
    int **convolution(int **matrix1, const size_t height1, const size_t width1, const int maxValue,
                      int **matrix2, const size_t height2, const size_t width2, const int divider) const;
};

#endif // CONVOLUTION_UNIT_H
