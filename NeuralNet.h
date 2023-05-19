#pragma once

#include "Neuron.h"


typedef std::vector<Neuron*> Layer;

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
    double x1 = -50; //молодые особи начальное положение
    double x2 = -50; //взрослые особи начальное положение
	double t = 0;
public:
	std::vector<Layer> m_layers; // m_layers[layerNum][neuronNum]
    Settings settings;
    bool Col =false;

public:
	std::vector<double> migrationx1;
	std::vector<int> x1dt;
	std::vector<double> migrationx2;
	std::vector<int> x2dt;
    void Clone(const NeuralNet &other);
    std::vector<int> localx1;
    std::vector<int> localx2;

	NeuralNet()
	{
        Layer l1;
		for (size_t i = 0; i < 8; i++)
		{
            l1.push_back(new Neuron(input));
		}
		Layer l2;
		for (size_t i = 0; i < 12; i++)
		{
            l2.push_back(new Neuron(basic));
		}
		Layer l3;
		for (size_t i = 0; i < 24; i++)
		{
            l3.push_back(new Neuron(basic));
		}
		Layer l4;
		for (size_t i = 0; i < 6; i++)
		{
            l4.push_back(new Neuron(output));
		}
		m_layers = { l1, l2, l3, l4};
        for (size_t i = 0; i < 6; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {
                m_layers[1][i]->AddConnection(j);
            }
        }
        for (size_t i = 6; i < 12; i++)
        {
            for (size_t j = 4; j < 8; j++)
            {
                m_layers[1][i]->AddConnection(j);
            }
        }
		for (size_t i = 0; i < 12; i++)
		{
			for (size_t j = 0; j < 6; j++)
			{
                m_layers[2][i]->AddConnection(j);
			}
		}
		for (size_t i = 12; i < 24; i++)
		{
			for (size_t j = 6; j < 12; j++)
			{
                m_layers[2][i]->AddConnection(j);
			}
		}
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 12; j++)
			{
                m_layers[3][i]->AddConnection(j);
			}
		}
		for (size_t i = 3; i < 6; i++)
		{
			for (size_t j = 12; j < 24; j++)
			{
                m_layers[3][i]->AddConnection(j);
			}
        }


         /*Layer l1;
                for (size_t i = 0; i < 8; i++)
                {
                    l1.push_back(new Neuron(input));
                }
                Layer l2;
                for (size_t i = 0; i < 24; i++)
                {
                    l2.push_back(new Neuron(basic));
                }
                Layer l3;
                for (size_t i = 0; i < 24; i++)
                {
                    l3.push_back(new Neuron(basic));
                }
                Layer l4;
                for (size_t i = 0; i < 6; i++)
                {
                    l4.push_back(new Neuron(output));
                }
                m_layers = { l1, l2, l3, l4};
                this->FullyConnect(1);
                for (size_t i = 0; i < 12; i++)
                {
                    for (size_t j = 0; j < 12; j++)
                    {
                        m_layers[2][i]->AddConnection(j);
                    }
                }
                for (size_t i = 12; i < 24; i++)
                {
                    for (size_t j = 12; j < 24; j++)
                    {
                        m_layers[2][i]->AddConnection(j);
                    }
                }
                for (size_t i = 0; i < 3; i++)
                {
                    for (size_t j = 0; j < 12; j++)
                    {
                        m_layers[3][i]->AddConnection(j);
                    }
                }
                for (size_t i = 3; i < 6; i++)
                {
                    for (size_t j = 12; j < 24; j++)
                    {
                        m_layers[3][i]->AddConnection(j);
                    }
                }*/
        //Settings settings;
	}
    NeuralNet(Settings set)
    {
        Layer l1;
        for (size_t i = 0; i < 8; i++)
        {
            l1.push_back(new Neuron(input));
        }
        Layer l2;
        for (size_t i = 0; i < 12; i++)
        {
            l2.push_back(new Neuron(basic));
        }
        Layer l3;
        for (size_t i = 0; i < 24; i++)
        {
            l3.push_back(new Neuron(basic));
        }
        Layer l4;
        for (size_t i = 0; i < 6; i++)
        {
            l4.push_back(new Neuron(output));
        }
        m_layers = { l1, l2, l3, l4};
        for (size_t i = 0; i < 6; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {
                m_layers[1][i]->AddConnection(j);
            }
        }
        for (size_t i = 6; i < 12; i++)
        {
            for (size_t j = 4; j < 8; j++)
            {
                m_layers[1][i]->AddConnection(j);
            }
        }
        for (size_t i = 0; i < 12; i++)
        {
            for (size_t j = 0; j < 6; j++)
            {
                m_layers[2][i]->AddConnection(j);
            }
        }
        for (size_t i = 12; i < 24; i++)
        {
            for (size_t j = 6; j < 12; j++)
            {
                m_layers[2][i]->AddConnection(j);
            }
        }
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 12; j++)
            {
                m_layers[3][i]->AddConnection(j);
            }
        }
        for (size_t i = 3; i < 6; i++)
        {
            for (size_t j = 12; j < 24; j++)
            {
                m_layers[3][i]->AddConnection(j);
            }
        }
        /*Layer l1;
        for (size_t i = 0; i < 8; i++)
        {
            l1.push_back(new Neuron(input));
        }
        Layer l2;
        for (size_t i = 0; i < 12; i++)
        {
            l2.push_back(new Neuron(basic));
        }
        Layer l3;
        for (size_t i = 0; i < 24; i++)
        {
            l3.push_back(new Neuron(basic));
        }
        Layer l4;
        for (size_t i = 0; i < 6; i++)
        {
            l4.push_back(new Neuron(output));
        }
        m_layers = { l1, l2, l3, l4};
        this->FullyConnect(1);
        for (size_t i = 0; i < 12; i++)
        {
            for (size_t j = 0; j < 6; j++)
            {
                m_layers[2][i]->AddConnection(j);
            }
        }
        for (size_t i = 12; i < 24; i++)
        {
            for (size_t j = 6; j < 12; j++)
            {
                m_layers[2][i]->AddConnection(j);
            }
        }
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 12; j++)
            {
                m_layers[3][i]->AddConnection(j);
            }
        }
        for (size_t i = 3; i < 6; i++)
        {
            for (size_t j = 12; j < 24; j++)
            {
                m_layers[3][i]->AddConnection(j);
            }
        }*/
        settings = set;
    }
    NeuralNet(const NeuralNet &other);

    ~NeuralNet() {
        for (auto layerIt = m_layers.begin(); layerIt != m_layers.end(); ++layerIt) {
            for (auto neuronIt = layerIt->begin(); neuronIt != layerIt->end(); ++neuronIt) {
                delete *neuronIt;
            }
            layerIt->clear();
        }
        m_layers.clear();
        migrationx1.clear();
        migrationx2.clear();
        x1dt.clear();
        x2dt.clear();
    }

    void AddColNeurons();

    NeuralNet& operator = (const NeuralNet &other);
	
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

    void serialize(const std::string& filename) const;
    NeuralNet deserializeNeuralNet(const std::string& filename);

	Layer GetOutput(); // test

    double Pxt(double x, double t)
    {
        return settings.Sx(x) * settings.St(t) / 2;
    }

	//test
	double GetFunc(int num)
	{
		if (num == 0)
		{
            return settings.E(x1);
		}
		if (num == 1)
		{
            //return Pxt(x1, t);
            return settings.Sx(x1);
		}
		if (num == 2)
		{
            /*if(t = 0)
                return 0;
            return Pxt(migrationx1[t-1], t) - Pxt(x1, t);*/
            return settings.St(t);
		}
		if (num == 3)
		{
            return settings.G(x1);
		}
		if (num == 4)
		{
            //return Pxt(x2, t);
            return settings.E(x2);
		}
		if (num == 5)
		{
            //return Pxt(x2, t);
            return settings.Sx(x2);
		}
		if (num == 6)
		{
            /*if(t = 0)
                return 0;
            return Pxt(migrationx2[t-1], t) - Pxt(x2, t);*/
            return settings.St(t);
		}
		if (num == 7)
		{
            return settings.G(x2);
		}
        if (num == 8)
        {
            return localx1[t];
        }
        if (num == 9)
        {
            return localx2[t];
        }
	}

	double GetM1()
	{
		double m = 0;
		for (int i = 0; i < 1440; i++)
		{
            m += settings.E(this->migrationx1[i]);
		}
        return m;
	}
	double GetM2()
	{
        if(settings.Col)
        {
            double m = 0;
            for (int i = 0; i < 1440; i++)
            {
                m += settings.St(i)*settings.Sx(this->migrationx1[i])/localx1[i];
            }
            return m;
        }
        else{
		double m = 0;
		for (int i = 0; i < 1440; i++)
		{
            //m += St(this->Gett() + i)*Sx(this->migrationx1[i]);
            m += settings.St(i)*settings.Sx(this->migrationx1[i]);
		}
        return m;
        }
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
            m += settings.G(this->migrationx1[i]);
		}
        return m;
	}
	double GetM5()
	{
		double m = 0;
		for (int i = 0; i < 1440; i++)
		{
            m += settings.E(this->migrationx2[i]);
		}
        return m;
	}
	double GetM6()
	{
        if(settings.Col)
        {
            double m = 0;
            for (int i = 0; i < 1440; i++)
            {
                m += settings.St(i)*settings.Sx(this->migrationx2[i])/localx2[i];
            }
            return m;
        }
		double m = 0;
		for (int i = 0; i < 1440; i++)
		{
            //m += St(this->Gett() + i)*Sx(this->migrationx2[i]);
            m += settings.St(i)*settings.Sx(this->migrationx2[i]);
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
            m += settings.G(this->migrationx2[i]);
		}
        return m;
	}
	
};
