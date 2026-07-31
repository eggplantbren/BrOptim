#ifndef BrOptim_MyModel_h
#define BrOptim_MyModel_h

#include <ostream>
#include <vector>
#include "DNest4/code/RNG.h"

namespace BrOptim
{

class MyModel
{
    private:
        std::vector<double> params;

    public:
        MyModel();
        void from_prior(DNest4::RNG& rng);
        double perturb(DNest4::RNG& rng);
        double objective_function() const;
        void print(std::ostream& out);
};

} // namespace

#endif
