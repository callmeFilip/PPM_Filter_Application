#include "ConvolutionUnit.h"

#include <cstdlib>
#include <cmath>

ConvolutionUnit ConvolutionUnit::m_instance;

int **ConvolutionUnit::convolution(int **matrix1, const size_t height1, const size_t width1, const int maxValue,
                                   int **matrix2, const size_t height2, const size_t width2, const int divider) const
{

    int realValue = height1 - height2;
    const size_t resultHeight = abs(realValue) + 1; // gets the absolute value of height1 - height2

    realValue = width1 - width2;
    const size_t resultWidth = abs(realValue) + 1; // gets the absolute value of width1 - width2

    int **result = new int *[resultHeight] { 0 };
    for (size_t i = 0; i < resultHeight; i++)
    {
        result[i] = new int[resultWidth]{0};
    }

    int cellValue = 0;
    // the outer fors are for moving the filter on the matrix
    for (size_t i = 0; i < resultHeight; i++)
    {
        for (size_t j = 0; j < resultWidth; j++)
        {

            // the inner fors are for calculating the actual number coming out of the applied filter
            for (size_t r = 0; r < height2; r++)
            {
                for (size_t c = 0; c < width2; c++)
                {
                    cellValue += matrix1[r + i][c + j] * matrix2[r][c];
                }
            }
            result[i][j] = abs(std::round(cellValue / divider));

            if (result[i][j] > maxValue)
            {
                result[i][j] = maxValue;
            }

            cellValue = 0;
        }
    }

    return result;
}
