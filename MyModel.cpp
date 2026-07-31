#include "MyModel.h"
#include "DNest4/code/Utils.h"

namespace BrOptim
{

MyModel::MyModel()
:params(1)
{

}

void MyModel::from_prior(DNest4::RNG& rng)
{
    params[0] = -10.0 + 20.0*rng.rand();
}

double MyModel::perturb(DNest4::RNG& rng)
{
    double logH = 0.0;

    params[0] += 20.0*rng.randh();
    DNest4::wrap(params[0], -10.0, 10.0);

    return logH;
}

double MyModel::objective_function() const
{
    return -0.5*pow(params[0], 2);
}


void MyModel::print(std::ostream& out)
{
    out << params[0];
}


} // namespace
