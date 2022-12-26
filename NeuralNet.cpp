#include "NeuralNet.h"


void NeuralNet::Clone(NeuralNet* prototype)
{
	//ClearMemory();
	memcpy(&m_layers, &prototype->m_layers, sizeof(&m_layers)); ///?????
}

NeuralNet::NeuralNet(NeuralNet* prototype)
{

	Clone(prototype);
}

/*void NeuralNet::Clear()
{
    memset(&m_layers, 0, sizeof(m_layers));
}*/


void NeuralNet::FullyConnect(int numlayer)
{
	if (numlayer == 0)
		return;
	for (int i = 0; i < m_layers[numlayer].size(); i++)
	{
		for (int j = 0; j < m_layers[numlayer - 1].size(); j++)
			m_layers[numlayer][i].AddConnection(j);
	}
}

void NeuralNet::Process()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		for (int j = 0; j < m_layers[i].size(); j++)
		{
			SumValue(i, j);
		}
	}
}

void NeuralNet::SumValue(int numLayer, int numNeuron)
{
	if (m_layers[numLayer][numNeuron].GetType() == input)
	{

		m_layers[numLayer][numNeuron].AddValue(GetFunc(numNeuron));
	}
	else
	{
		for (int j = 0; j < m_layers[numLayer][numNeuron].numConnections; j++)
		{
			m_layers[numLayer][numNeuron].AddValue(m_layers[numLayer - 1][m_layers[numLayer][numNeuron].allConnections[j]->index].GetValue() * m_layers[numLayer][numNeuron].allConnections[j]->weight);
		} // BIAS ???
		m_layers[numLayer][numNeuron].AddValue(m_layers[numLayer][numNeuron].bias);
	}
}

NetOutput NeuralNet::GetMaxOutput1()
{
	int indexmax = 0;
	double max = m_layers[m_layers.size() - 1][0].GetValue();
	for (int i = 1; i < 3; i++)
	{
		if (max < m_layers[m_layers.size() - 1][i].GetValue())
		{
			max = m_layers[m_layers.size() - 1][i].GetValue();
			indexmax = i;
		}
	}
	return NetOutput(indexmax); //???
}

NetOutput NeuralNet::GetMaxOutput2()
{
	int indexmax = 3;
	double max = m_layers[m_layers.size() - 1][3].GetValue();
	for (int i = 4; i < 6; i++)
	{
		if (max < m_layers[m_layers.size() - 1][i].GetValue())
		{
			max = m_layers[m_layers.size() - 1][i].GetValue();
			indexmax = i;
		}
	}
	return NetOutput(indexmax); //???
}

Layer NeuralNet::GetOutput() // test
{
	return m_layers[m_layers.size() - 1];
}

void NeuralNet::ProcessDay()
{
	migrationx1.push_back(x1);
	migrationx2.push_back(x2);
	NetOutput n1 = s11;
	NetOutput n2 = s21;
	for (int i = 0; i < 1440 - 1; i++)
	{
        this->Sett(this->Gett() + i);
		Process();
		n1 = GetMaxOutput1();
		n2 = GetMaxOutput2();
		if (n1 == s11)
		{
			if (Getx1() > -1)
			{
				this->Setx1(Getx1());
			}
			else
			{
				this->Setx1(Getx1() + deltax);
				x1dt.push_back(1);
			}
		}
		else if (n1 == s12)
		{
			this->Setx1(Getx1());
		}
		else if (n1 == s13)
		{
            if (Getx1() <= MaxDeep)
			{
				this->Setx1(Getx1());
			}
			else
			{
				this->Setx1(Getx1() - deltax);
				x1dt.push_back(1);
			}
		}
		if (n2 == s21)
		{
			if (Getx2() >= -1)
			{
				this->Setx2(Getx2());
			}
			else
			{
				this->Setx2(Getx2() + deltax);
				x2dt.push_back(1);
			}
		}
		else if (n2 == s22)
		{
			this->Setx2(Getx2());
		}
		else if (n2 == s23)
		{
            if (Getx2() <= MaxDeep)
			{
				this->Setx2(Getx2());
			}
			else
			{
				this->Setx2(Getx2() - deltax);
				x2dt.push_back(1);
			}
		}
		migrationx1.push_back(x1);
		migrationx2.push_back(x2);
		ResetValues();
	}
}

void NeuralNet::ResetValues()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		for (int j = 0; j < m_layers[i].size(); j++)
		{
			m_layers[i][j].ResetValue();
		}
	}
	t = 0;
}
