#include "MyModel.h"
#include "DNest4/code/Utils.h"

namespace BrOptim
{

MyModel::MyModel()
:params(2)
{

}

void MyModel::from_prior(DNest4::RNG& rng)
{
    params[0] = -10.0 + 20.0*rng.rand();
    params[1] = rng.rand(); // This mimics noise
}

double MyModel::perturb(DNest4::RNG& rng)
{
    double logH = 0.0;

    int which = rng.rand_int(2);

    if(which == 0)
    {
        params[0] += 20.0*rng.randh();
        DNest4::wrap(params[0], -10.0, 10.0);
    }
    else
    {
        params[1] += rng.randh();
        DNest4::wrap(params[1], 0.0, 1.0);
    }

    return logH;
}

double MyModel::objective_function() const
{
    return -0.5*pow(params[0], 2) + 100.0*(params[1] - 0.5);
}


void MyModel::print(std::ostream& out)
{
    out << params[0] << ' ' << params[1];
}


} // namespace
