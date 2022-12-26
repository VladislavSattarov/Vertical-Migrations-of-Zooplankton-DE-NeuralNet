#pragma once
#include "NeuralNet.h"

class DE
{
private:
    double F = 0.45; // амплитуда возмущений
    double P = 0.5; // веро€тность скрещивани€
	std::vector<NeuralNet> N1; // население предков
	std::vector<NeuralNet> N2; // население потомков
	NeuralNet Mutated;
	void MakePopulation();
	NeuralNet Mutate(int index);
	void Crossover(NeuralNet mutated);
	void Selection();


public:
	NeuralNet process(int CountOperations);
	double Fit(NeuralNet tmp);
};
