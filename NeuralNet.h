#pragma once

#include "Neuron.h"


typedef std::vector<Neuron> Layer;

enum NetInput
{
		food1,
		predatorDistribution1,
		predatorActivity1,
		additionalMortality1,
		food2,
		predatorDistribution2,
		predatorActivity2,
		additionalMortality2,
};



enum NetOutput
{

	s11,
	s12,
	s13,
	s21,
	s22,
	s23
};




class NeuralNet
{
private:
    double x1 = 0;
    double x2 = -1;
	double t = 0;
	double E(double x)
	{
        //return sigma1 * (tanh(e1 * x + C1) + 1);
        return  (tanh(0.02 * (x + C1)) + 1.)/2.;
	}
	double Sx(double x)
	{
        //return sigma2 * (tanh(e2 * x + C1) + 1);
        return (tanh(0.025 * (x + C1)) + 1)/2.;
	}
	double St(double t)
	{
        //return cos(2 * PI * t) + 1.;
        return (cos(2 * PI * (t/1440. + 1./2.)) + 1.)/2.;
	}
	double G(double x)
	{
		return xi1 * pow(eta1, x - C2) + xi2 * pow(eta2, -(x - C3)) / 2;
	}
public:
	std::vector<Layer> m_layers; // m_layers[layerNum][neuronNum]



public:
	std::vector<double> migrationx1;
	std::vector<int> x1dt;
	std::vector<double> migrationx2;
	std::vector<int> x2dt;
	void Clone(NeuralNet* prototype);

	NeuralNet()
	{
		Layer l1;
		for (size_t i = 0; i < 8; i++)
		{
			l1.push_back(Neuron(input));
		}
		Layer l2;
		for (size_t i = 0; i < 12; i++)
		{
			l2.push_back(Neuron(basic));
		}
		Layer l3;
		for (size_t i = 0; i < 24; i++)
		{
			l3.push_back(Neuron(basic));
		}
		Layer l4;
		for (size_t i = 0; i < 6; i++)
		{
			l4.push_back(Neuron(output));
		}
		m_layers = { l1, l2, l3, l4};
		this->FullyConnect(1);
		for (size_t i = 0; i < 12; i++)
		{
			for (size_t j = 0; j < 6; j++)
			{
				m_layers[2][i].AddConnection(j);
			}
		}
		for (size_t i = 12; i < 24; i++)
		{
			for (size_t j = 6; j < 12; j++)
			{
				m_layers[2][i].AddConnection(j);
			}
		}
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 12; j++)
			{
				m_layers[3][i].AddConnection(j);
			}
		}
		for (size_t i = 3; i < 6; i++)
		{
			for (size_t j = 12; j < 24; j++)
			{
				m_layers[3][i].AddConnection(j);
			}
		}
	}
	NeuralNet(NeuralNet* prototype);


	
	void Clear();

	void Process();

	void ProcessDay();

	void FullyConnect(int numlayer);

	void SumValue(int numLayer, int numNeuron);

	void ResetValues();

	void Setx1(double x)
	{
		x1 = x;
	}

	void Setx2(double x)
	{
		x2 = x;
	}

	double Getx1()
	{
		return x1;
	}
	double Getx2()
	{
		return x2;
	}

	void Sett(double T)
	{
		t = T;
	}

	double Gett()
	{
		return t;
	}
	NetOutput GetMaxOutput1();
	NetOutput GetMaxOutput2();

	Layer GetOutput(); // test

	//test
	double GetFunc(int num)
	{
		if (num == 0)
		{
			return E(x1);
		}
		if (num == 1)
		{
			return Sx(x1);
		}
		if (num == 2)
		{
			return St(t);
		}
		if (num == 3)
		{
			return G(x1);
		}
		if (num == 4)
		{
			return E(x2);
		}
		if (num == 5)
		{
			return Sx(x2);
		}
		if (num == 6)
		{
			return St(t);
		}
		if (num == 7)
		{
			return G(x2);
		}
	}

	double GetM1()
	{
		double m = 0;
		for (int i = 0; i < 1440; i++)
		{
			m += E(this->migrationx1[i]);
		}
        return m;
	}
	double GetM2()
	{
		double m = 0;
		for (int i = 0; i < 1440; i++)
		{
            //m += St(this->Gett() + i)*Sx(this->migrationx1[i]);
            m += St(i)*Sx(this->migrationx1[i]);
		}
        return m;
	}
	double GetM3()
	{
		double m = 0;
		for (int i = 0; i < x1dt.size(); i++)
		{
			m += x1dt[i]; // ???
		}
        return m;
	}

	double GetM4()
	{
		double m = 0;
		for (int i = 0; i < 1440; i++)
		{
			m += G(this->migrationx1[i]);
		}
        return m;
	}
	double GetM5()
	{
		double m = 0;
		for (int i = 0; i < 1440; i++)
		{
			m += E(this->migrationx2[i]);
		}
        return m;
	}
	double GetM6()
	{
		double m = 0;
		for (int i = 0; i < 1440; i++)
		{
            //m += St(this->Gett() + i)*Sx(this->migrationx2[i]);
            m += St(i)*Sx(this->migrationx2[i]);
		}
        return m;
	}
	double GetM7()
	{
		double m = 0;
		for (int i = 0; i < x2dt.size(); i++)
		{
			m += x2dt[i]; // ???
		}
        return m;
	}

	double GetM8()
	{
		double m = 0;
		for (int i = 0; i < 1440; i++)
		{
			m += G(this->migrationx2[i]);
		}
        return m;
	}
	
};
