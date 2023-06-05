#include "NeuralNet.h"


void NeuralNet::Clone(const NeuralNet &other)
{
    migrationx1 = other.migrationx1;
    migrationx2 = other.migrationx2;
    x1dt = other.x1dt;
    x2dt = other.x2dt;
    x1 = other.x1;
    x2 = other.x2;
    t = other.t;
    m_layers = std::vector<Layer>(other.m_layers.size());
    for(int i = 0; i < other.m_layers.size(); i++)
    {
        m_layers[i] = Layer(other.m_layers[i].size());
        for(int j = 0; j < other.m_layers[i].size(); j++)
        {
            m_layers[i][j] = new Neuron;
            *m_layers[i][j] = *other.m_layers[i][j];
        }
    }
    //ClearMemory();
    //memcpy(&m_layers, &prototype->m_layers, sizeof(&m_layers)); ///?????
}

NeuralNet::NeuralNet(const NeuralNet &other)
{

    migrationx1 = other.migrationx1;
    migrationx2 = other.migrationx2;
    settings = other.settings;
    x1dt = other.x1dt;
    x2dt = other.x2dt;
    x1 = other.x1;
    x2 = other.x2;
    t = other.t;
    if(settings.Col)
        localx2 = other.localx2;
    m_layers = std::vector<Layer>(other.m_layers.size());
    for(int i = 0; i < other.m_layers.size(); i++)
    {
        m_layers[i] = Layer(other.m_layers[i].size());
        for(int j = 0; j < other.m_layers[i].size(); j++)
        {
            m_layers[i][j] = new Neuron;
            *m_layers[i][j] = *other.m_layers[i][j];
        }
    }
}

NeuralNet& NeuralNet::operator = (const NeuralNet &other)
{
    if (this == &other)
        return *this;

    migrationx1.clear();
    migrationx1 = other.migrationx1;
    migrationx2.clear();
    migrationx2 = other.migrationx2;
    x1dt.clear();
    x1dt = other.x1dt;
    x2dt.clear();
    x2dt = other.x2dt;
    x1 = other.x1;
    x2 = other.x2;
    t = other.t;
    settings = other.settings;
    if(settings.Col)
        localx2 = other.localx2;

    for(int i = 0; i < m_layers.size(); i++)
    {
        for(int j = 0; j < m_layers[i].size(); j++)
        {
            delete m_layers[i][j];
        }
        m_layers[i].clear();
    }
    m_layers.clear();
    m_layers = std::vector<Layer>(other.m_layers.size());
    for(int i = 0; i < other.m_layers.size(); i++)
    {
        m_layers[i] = Layer(other.m_layers[i].size());
        for(int j = 0; j < other.m_layers[i].size(); j++)
        {
            m_layers[i][j] = new Neuron;
            *m_layers[i][j] = *other.m_layers[i][j];
        }
    }
    return *this;
}

/*void NeuralNet::Clear()
{
    for (int i = 0; i < m_layers.size(); i++)
    {
        for(int j = 0; j < m_layers[i].size(); j++)
        {
            delete m_layers[i][j];
        }
        m_layers[i].clear();
    }
    m_layers.clear();
    migrationx1.clear();
    migrationx2.clear();
    x1dt.clear();
    x2dt.clear();
}*/


void NeuralNet::FullyConnect(int numlayer)
{
	if (numlayer == 0)
		return;
	for (int i = 0; i < m_layers[numlayer].size(); i++)
	{
		for (int j = 0; j < m_layers[numlayer - 1].size(); j++)
            m_layers[numlayer][i]->AddConnection(j);
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
    if (m_layers[numLayer][numNeuron]->GetType() == input)
	{

        m_layers[numLayer][numNeuron]->AddValue(GetFunc(numNeuron));
	}
	else
	{
        for (int j = 0; j < m_layers[numLayer][numNeuron]->numConnections; j++)
		{
            m_layers[numLayer][numNeuron]->AddValue(m_layers[numLayer - 1][m_layers[numLayer][numNeuron]->allConnections[j]->index]->GetValue() * m_layers[numLayer][numNeuron]->allConnections[j]->weight);
		} // BIAS ???
        m_layers[numLayer][numNeuron]->AddValue(m_layers[numLayer][numNeuron]->bias);
	}
}

NetOutput NeuralNet::GetMaxOutput1()
{
	int indexmax = 0;
    double max = m_layers[m_layers.size() - 1][0]->GetValue();
	for (int i = 1; i < 3; i++)
	{
        if (max < m_layers[m_layers.size() - 1][i]->GetValue())
		{
            max = m_layers[m_layers.size() - 1][i]->GetValue();
			indexmax = i;
		}
	}
	return NetOutput(indexmax); //???
}

NetOutput NeuralNet::GetMaxOutput2()
{
	int indexmax = 3;
    double max = m_layers[m_layers.size() - 1][3]->GetValue();
	for (int i = 4; i < 6; i++)
	{
        if (max < m_layers[m_layers.size() - 1][i]->GetValue())
		{
            max = m_layers[m_layers.size() - 1][i]->GetValue();
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
    migrationx1.clear();
    migrationx2.clear();
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
            if (Getx1() <= settings.MaxDeep)
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
            if (Getx2() <= settings.MaxDeep)
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
            m_layers[i][j]->ResetValue();
		}
	}
	t = 0;
}

void NeuralNet::serialize(const std::string& filename) const
{
    std::ofstream ofs(filename, std::ios::binary | std::ios::trunc);
    if (ofs.is_open()) {

    //ofs.write((char*)&migrationx1, sizeof(migrationx1));
    //ofs.write((char*)&migrationx2, sizeof(migrationx2));
    //ofs.write((char*)&x1dt, sizeof(x1dt));
    //ofs.write((char*)&x2dt, sizeof(x2dt));
    ofs.write((char*)&x1, sizeof(x1));
    ofs.write((char*)&x2, sizeof(x2));
    ofs.write((char*)&t, sizeof(t));

    int numLayers = m_layers.size();
    ofs.write((char*)&numLayers, sizeof(int));
    for (int i = 0; i < numLayers; i++) {
        int numNeurons = m_layers[i].size();
        ofs.write((char*)&numNeurons, sizeof(int));
        for (int j = 0; j < numNeurons; j++) {
            m_layers[i][j]->serializeNeuron(*m_layers[i][j], ofs);
        }
    }
    }
    else
    {
    throw std::runtime_error("Cannot open file for writing: " + filename);
    }
}

NeuralNet NeuralNet::deserializeNeuralNet(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Failed to open file for deserialization: " << filename << std::endl;
        exit(1);
    }

    NeuralNet net;

    // Читаем данные для net
    //file.read((char*)&net.migrationx1, sizeof(net.migrationx1));
    //file.read((char*)&net.migrationx2, sizeof(net.migrationx2));
    //file.read((char*)&net.x1dt, sizeof(net.x1dt));
    //file.read((char*)&net.x2dt, sizeof(net.x2dt));
    file.read((char*)&net.x1, sizeof(net.x1));
    file.read((char*)&net.x2, sizeof(net.x2));
    file.read((char*)&net.t, sizeof(net.t));

    // Десериализуем m_layers
    int numLayers;
    file.read((char*)&numLayers, sizeof(numLayers));
    net.m_layers.clear();
    net.m_layers.reserve(numLayers);
    for (int i = 0; i < numLayers; i++) {
        int numNeurons;
        file.read((char*)&numNeurons, sizeof(numNeurons));
        Layer layer(numNeurons);
        for (int j = 0; j < numNeurons; j++) {
            layer[j] = new Neuron;
            layer[j]->deserializeNeuron(file);
        }
        net.m_layers.push_back(layer);
    }

    file.close();

    return net;
}

void NeuralNet::AddColNeurons()
{
    settings.Col = true;
    this->m_layers[0].push_back(new Neuron(input));//9
    this->m_layers[1].push_back(new Neuron(basic));
    this->m_layers[2].push_back(new Neuron(basic));
    m_layers[1][12]->AddConnection(8);
    m_layers[2][24]->AddConnection(12);
    for(int i = 0; i < 3; i++)
    {
    m_layers[3][i]->AddConnection(24);
    }
    for(int i = 0; i < 1440; i++)
    {

    localx2.push_back(0);

    }
}

