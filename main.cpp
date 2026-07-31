#include <iostream>
#include "DNest4/code/RNG.h"
#include "MyModel.h"
#include "Optimiser.hpp"

int main()
{
    DNest4::RNG rng(time(0));
    BrOptim::Optimiser<BrOptim::MyModel> optimiser(rng);

    for(int i=0; i<10000; ++i)
        optimiser.update(rng);

    return 0;
}
