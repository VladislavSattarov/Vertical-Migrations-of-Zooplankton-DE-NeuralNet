#pragma once
#include "NeuralNet.h"

class DE
{
private:
    double F = 0.5; // амплитуда возмущений
    double P = 0.5; // веро€тность скрещивани€
    std::vector<NeuralNet*> N1; // население предков
    std::vector<NeuralNet*> N2; // население потомков
    NeuralNet* Mutated;
    void MakePopulation(int PopulationSize, Settings sett);
    NeuralNet* Mutate(int index);
    void Crossover(NeuralNet* mutated);
    void Selection(int i, int countop);
public:
    double alpha_j, beta_j, delta_j;
    double alpha_a, beta_a, delta_a;
    double gamma_j, gamma_a;
    Settings settings;
    NeuralNet process(int CountOperations, int PopulationSize, Settings set);
    std::vector<NeuralNet*> process(std::vector<NeuralNet*> Pop, int CountOperations, Settings set);
    double Fit(NeuralNet* tmp);
    std::vector<double> Fits;
    ~DE()
    {
        for(int i = 0; i < N1.size(); i++)
        {
            delete N1[i];
        }
        for(int i = 0; i < N2.size(); i++)
        {
            delete N2[i];
        }
        if(Mutated != nullptr)
        delete Mutated;
    }

};
