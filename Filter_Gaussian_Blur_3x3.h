#ifndef FILTER_BLUR_GAUSSIAN_BLUR_H
#define FILTER_BLUR_GAUSSIAN_BLUR_H

/**
 * Filter_Gaussian_Blur_3x3.h
*/

#include "Filter.h"
#include "Globals.h"

class Filter_Gaussian_Blur_3x3 : public Filter
{
private:
    static Filter_Gaussian_Blur_3x3 m_instance;

    Filter_Gaussian_Blur_3x3() : Filter(GAUSSIAN_BLUR_3x3_SIZE, GAUSSIAN_BLUR_3x3_SIZE, GAUSSIAN_BLUR_3x3_DIVIDER)
    {

        m_matrix[0][0] = 1;
        m_matrix[0][1] = 2;
        m_matrix[0][2] = 1;
        m_matrix[1][0] = 2;
        m_matrix[1][1] = 4;
        m_matrix[1][2] = 2;
        m_matrix[2][0] = 1;
        m_matrix[2][1] = 2;
        m_matrix[2][2] = 1;
    }

    Filter_Gaussian_Blur_3x3(const Filter_Gaussian_Blur_3x3 &);
    void operator=(Filter_Gaussian_Blur_3x3 const &);

public:
    static Filter_Gaussian_Blur_3x3 *getInstance() { return &m_instance; }
};

#endif // FILTER_BLUR_GAUSSIAN_BLUR_H
