#ifndef BrOptim_Optimiser_h
#define BrOptim_Optimiser_h

#include "Collection.h"
#include <fstream>
#include <iomanip>

namespace BrOptim
{

template<typename T>
class Optimiser
{
    private:
        int iteration;
        T particle;
        Collection collection;
        double goodness;
        int dist;

        std::fstream fout;

    public:
        Optimiser() = delete;
        Optimiser(DNest4::RNG& rng);
        void update(DNest4::RNG& rng);
};

template<typename T>
Optimiser<T>::Optimiser(DNest4::RNG& rng)
:fout("output.txt", std::ios::out)
{
    fout << std::setprecision(12);
    iteration = 0;
    particle.from_prior(rng);
    goodness = particle.objective_function();
    collection.insert(goodness);
    dist = 0;
}


template<typename T>
void Optimiser<T>::update(DNest4::RNG& rng)
{
    ++iteration;

    std::cout << "Iteration " << iteration << ". ";
    std::cout << "Exploring..." << std::flush;

    int accepts = 0;
    for(int i=0; i<1000; ++i)
    {
        T proposal = particle;
        double logH = proposal.perturb(rng);
        double goodness_proposal = proposal.objective_function();
        int dist_proposal = collection.distance_from_top(goodness_proposal);

        double loga = logH - log(1.0 + pow((double)dist_proposal/10.0, 2))
                           + log(1.0 + pow((double)dist/10.0, 2));
        if(rng.rand() <= exp(loga))
        {
            particle = std::move(proposal);
            goodness = goodness_proposal;
            dist = dist_proposal;
            ++accepts;
        }
    }

    collection.insert(goodness);
    particle.print(fout);    
    fout << ' ' << goodness << std::endl;
    std::cout << "done. Acceptance rate = " << accepts << '/' << 1000;
    std::cout << '.' << std::endl;
}

} // namespace


#endif
