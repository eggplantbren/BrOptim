#include "Collection.h"
#include <iostream>

namespace BrOptim
{

// Insert a single value while keeping the vector sorted
void Collection::insert(double value)
{
    auto it = std::lower_bound(values.begin(), values.end(), value);
    values.insert(it, value);
}

// Bulk insert is much more efficient if adding many elements at once
void Collection::insert_bulk(const std::vector<double>& new_values)
{
    values.insert(values.end(), new_values.begin(), new_values.end());
    std::sort(values.begin(), values.end());
}

// O(log N) lookup + O(1) distance calculation
int Collection::distance_from_top(double value) const
{
    auto it = std::upper_bound(values.begin(), values.end(), value);
    return std::distance(it, values.end()); 
}

void Collection::test()
{
    Collection collection;
    collection.insert_bulk({4.1, 5.5, 7.3, 11.4});
    for(int i=0; i<15; ++i)
    {
        std::cout << i << ' ' << collection.distance_from_top((double)i);
        std::cout << std::endl;
    }
}

} // namespace
