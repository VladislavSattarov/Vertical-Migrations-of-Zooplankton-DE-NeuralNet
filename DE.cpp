#include "DE.h"

void DE::MakePopulation()
{
	for (int i = 0; i < PopulationSize; i++)
	{
		N1.push_back(NeuralNet());
		N1[i].ProcessDay();
		std::cout << Fit(N1[i]) << "\n";
	}
}

NeuralNet DE::Mutate(int index)
{
	NeuralNet Y1;
	NeuralNet Y2;
	int randindex = rand() % (N1.size());
	NeuralNet Mutated;
	while(randindex == index)
	{
		randindex = rand() % (N1.size());
	}
	Y1 = N1[randindex];
	int tmp = randindex;
	while (randindex == index || tmp == randindex)
	{
		randindex = rand() % (N1.size());
	}
	Y2 = N1[randindex];
	for (int i = 0; i < N1[index].m_layers.size(); i++)
	{
		for (int j = 0; j < N1[index].m_layers[i].size(); j++)
		{
			for (int x = 0; x < N1[index].m_layers[i][j].allConnections.size(); x++)
			{
				
				Mutated.m_layers[i][j].allConnections[x]->weight = N1[index].m_layers[i][j].allConnections[x]->weight + F * (Y1.m_layers[i][j].allConnections[x]->weight - Y2.m_layers[i][j].allConnections[x]->weight);
			}
			Mutated.m_layers[i][j].bias = N1[index].m_layers[i][j].bias + F * (Y1.m_layers[i][j].bias - Y2.m_layers[i][j].bias);
		}
	}
	return Mutated;
}

void DE::Crossover(NeuralNet mutated)
{	
	for (int i = 0; i < N1.size(); i++)
	{
		NeuralNet tmp = N1[i];
		for (int j = 0; j < N1[i].m_layers.size(); j++)
		{
			for (int k = 0; k < N1[i].m_layers[j].size(); k++)
			{
				if(RandomFloatInRange(0, 1) <= P)
				{
					tmp.m_layers[j][k].bias = mutated.m_layers[j][k].bias;
				}
				else
				{
					tmp.m_layers[j][k].bias = N1[i].m_layers[j][k].bias;
				}
				for (int x = 0; x < N1[i].m_layers[j][k].allConnections.size(); x++)
				{

				if (RandomFloatInRange(0, 1) <= P)
				{
					tmp.m_layers[j][k].allConnections[x]->weight = mutated.m_layers[j][k].allConnections[x]->weight;
				}
				else
				{
					tmp.m_layers[j][k].allConnections[x]->weight = N1[i].m_layers[j][k].allConnections[x]->weight;
				}
				}
			}
		}
		N2.push_back(NeuralNet());
	}
	for (int i = 0; i < N2.size(); i++)
	{
		N2[i].ProcessDay();
	}
}

void DE::Selection() 
{
	for (int i = 0; i < N1.size(); i++)
	{
		if (Fit(N1[i]) < Fit(N2[i])) // Fit - функция фитнеса
		{
			N1[i] = N2[i];
		}
	}

	N2.clear();

}

NeuralNet DE::process(int CountOperations)
{
	MakePopulation();
	for (int i = 0; i < CountOperations; i++)
	{
		Mutated = Mutate(RandomVal(N1.size()));
		Crossover(Mutated);
		Selection();
	}
	NeuralNet tmp;
	tmp = N1[0];
	for (int i = 1; i < N1.size(); i++)
	{
		if (Fit(tmp) < Fit(N1[i]))
		{
			tmp = N1[i];
		}

	}
	return tmp;
}

double DE::Fit(NeuralNet tmp)
{
    double P = 0.0016 * tmp.GetM1() - 0.0000007 * tmp.GetM3() - 0.000016 * tmp.GetM4(); //0.0016, 0.0000007, 0.000016
    double Q = 0.00008 * tmp.GetM2(); // увеличить, было 0.00008
	double S = 0.004 * tmp.GetM6();
    double R = 0.006 * tmp.GetM5() - 0.0000075 * tmp.GetM7() - 0.00006 * tmp.GetM8();
    return -P - S - Q + sqrt(4 * R * P + pow(P + Q - S, 2));
    //return P + Q + S + R;
}



