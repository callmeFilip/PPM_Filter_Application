#ifndef FILTER_GAUSSIAN_BLUR_5X5_H
#define FILTER_GAUSSIAN_BLUR_5X5_H

/**
 * Filter_Gaussian_Blur_5x5.h
*/

#include "Globals.h"
#include "Filter.h"

class Filter_Gaussian_Blur_5x5 : public Filter
{
private:
    static Filter_Gaussian_Blur_5x5 m_instance;

    Filter_Gaussian_Blur_5x5() : Filter(GAUSSIAN_BLUR_5x5_SIZE, GAUSSIAN_BLUR_5x5_SIZE, GAUSSIAN_BLUR_5x5_DIVIDER)
    {
        m_matrix[0][0] = 1;
        m_matrix[0][1] = 4;
        m_matrix[0][2] = 6;
        m_matrix[0][3] = 4;
        m_matrix[0][4] = 1;
        m_matrix[1][0] = 4;
        m_matrix[1][1] = 16;
        m_matrix[1][2] = 24;
        m_matrix[1][3] = 16;
        m_matrix[1][4] = 4;
        m_matrix[2][0] = 6;
        m_matrix[2][1] = 24;
        m_matrix[2][2] = 36;
        m_matrix[2][3] = 24;
        m_matrix[2][4] = 6;
        m_matrix[3][0] = 4;
        m_matrix[3][1] = 16;
        m_matrix[3][2] = 24;
        m_matrix[3][3] = 16;
        m_matrix[3][4] = 4;
        m_matrix[4][0] = 1;
        m_matrix[4][1] = 4;
        m_matrix[4][2] = 6;
        m_matrix[4][3] = 4;
        m_matrix[4][4] = 1;
    }

    Filter_Gaussian_Blur_5x5(const Filter_Gaussian_Blur_5x5 &);
    void operator=(Filter_Gaussian_Blur_5x5 const &);

public:
    static Filter_Gaussian_Blur_5x5 *getInstance() { return &m_instance; }
};

#endif // FILTER_GAUSSIAN_BLUR_5X5_H
