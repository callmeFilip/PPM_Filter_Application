#ifndef FILTERAPPLIER_H
#define FILTERAPPLIER_H

/**
 * FilterApplier.h
 * Responsible for applying filters to RGBImage *.
*/

#include "RGBImage.h"
#include "Filter.h"

class FilterApplier
{
private:
    static FilterApplier m_instance;
    FilterApplier() {}
    FilterApplier(const FilterApplier &);
    void operator=(FilterApplier const &);

public:
    static FilterApplier *getInstance() { return &m_instance; }
    RGBImage *applyFilter(Filter *fil, const RGBImage *img) const;
};

#endif // FILTERAPPLIER_H
