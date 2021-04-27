#ifndef FILTER_SHARPEN_H
#define FILTER_SHARPEN_H

/**
 * Filter_Sharpen.h
*/

#include "Filter.h"
#include "Globals.h"

class Filter_Sharpen : public Filter
{
protected:
    static Filter_Sharpen m_instance;

    Filter_Sharpen() : Filter(SHARPENSIZE, SHARPENSIZE)
    {
        m_matrix[0][1] = -1;
        m_matrix[1][0] = -1;
        m_matrix[1][1] = 5;
        m_matrix[1][2] = -1;
        m_matrix[2][1] = -1;

        // the rest are 0 by default
    }

    Filter_Sharpen(const Filter_Sharpen &);
    void operator=(Filter_Sharpen const &);

public:
    static Filter_Sharpen *getInstance() { return &m_instance; }
};

#endif // FILTER_SHARPEN_H
