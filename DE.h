#pragma once
#include "NeuralNet.h"

class DE
{
private:
    double F = 0.45; // ��������� ����������
    double P = 0.5; // ����������� �����������
	std::vector<NeuralNet> N1; // ��������� �������
	std::vector<NeuralNet> N2; // ��������� ��������
	NeuralNet Mutated;
	void MakePopulation();
	NeuralNet Mutate(int index);
	void Crossover(NeuralNet mutated);
	void Selection();


public:
	NeuralNet process(int CountOperations);
	double Fit(NeuralNet tmp);
};
