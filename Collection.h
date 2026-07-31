#ifndef PostEnt2026_Collection_h
#define PostEnt2026_Collection_h

#include <vector>
#include <algorithm>
#include <iterator>

namespace BrOptim
{

class Collection
{
    private:
        std::vector<double> values;

    public:
        Collection() = default;

        // Insert a single value while keeping the vector sorted
        void insert(double value);

        // Bulk insert is much more efficient if adding many elements at once
        void insert_bulk(const std::vector<double>& new_values);

        // O(log N) lookup + O(1) distance calculation
        int distance_from_top(double value) const;

        static void test();
};

} // namespace


#endif
