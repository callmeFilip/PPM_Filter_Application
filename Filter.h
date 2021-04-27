#ifndef FILTER_H
#define FILTER_H

/**
 * Filter.h
 * The base filter class.
 * All filters must derive from Filter.h.
*/

#include <cstddef>

class Filter
{
protected:
    int **m_matrix;
    size_t m_height;
    size_t m_width;
    int m_divider;

public:
    Filter(size_t height, size_t width, int divider = 1) : m_height(height), m_width(width), m_divider(divider)
    {
        m_matrix = new int *[m_height] { 0 };
        for (size_t i = 0; i < m_height; i++)
        {
            m_matrix[i] = new int[width]{0};
        }
    }

    virtual ~Filter()
    {
        for (size_t i = 0; i < m_height; i++)
        {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;
    }

    virtual int **getFilter() const
    {
        return m_matrix;
    }

    virtual size_t getHeight() const
    {
        return m_height;
    }

    virtual size_t getWidth() const
    {
        return m_width;
    }

    virtual size_t getDivider() const
    {
        return m_divider;
    }
};

#endif // FILTER_H
