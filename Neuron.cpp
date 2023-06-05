#include "Neuron.h"




Neuron::Neuron()
{
	type = basic;
}

Neuron::Neuron(NeuronType typ)
{
	type = typ;
}

Neuron::Neuron(const Neuron &other)
{
    value = other.value;
    type = other.type;
    bias = other.bias;
    numConnections = other.numConnections;
    allConnections = std::vector<NeuronConnection*>(other.allConnections.size());
    for (int i = 0; i < other.numConnections; i++)
    {
        allConnections[i] = new NeuronConnection(*other.allConnections[i]);
    }
}

void Neuron::Clone(const Neuron &other)
{
    value = other.value;
    type = other.type;
    bias = other.bias;
    numConnections = other.numConnections;
    allConnections = std::vector<NeuronConnection*>(other.allConnections.size());
    for (int i = 0; i < other.numConnections; i++)
    {
        allConnections[i] = new NeuronConnection(*other.allConnections[i]);
        //allConnections[i]->index = other.allConnections[i]->index;
        //allConnections[i]->weight = other.allConnections[i]->weight;
    }
}

Neuron& Neuron::operator = (const Neuron &other)
{
    if (this != &other) // проверка на самоприсваивание
    {
        value = other.value;
        type = other.type;
        bias = other.bias;
        numConnections = other.numConnections;
        for (int i = 0; i < allConnections.size(); i++)
        {
            delete allConnections[i];
        }
        allConnections.clear();
        allConnections.reserve(other.allConnections.size());
        for (int i = 0; i < other.numConnections; i++)
        {
            allConnections.push_back(new NeuronConnection(*other.allConnections[i]));
        }
    }
    return *this;
}

Neuron::~Neuron()
{
    for (auto it = allConnections.begin(); it != allConnections.end(); ++it) {
            delete *it;
        }
        allConnections.clear();
}

double Neuron::GetValue()
{
	if (this->type == input)
		return value;
	else
	return SigmoidActivation(value);
}

void Neuron::AddConnection(int index)
{
    NeuronConnection* tmp = new NeuronConnection();
	tmp->index = index;
	tmp->SetRandomWeight();

	allConnections.push_back(tmp);
	++numConnections;
}

void Neuron::AddNullConnection(int index)
{
    NeuronConnection* tmp = new NeuronConnection();
    tmp->index = index;
    tmp->SetNullWeight();

    allConnections.push_back(tmp);
    ++numConnections;
}

int Neuron::IsConnected(int index)
{
	for (int i = 0; i < numConnections; ++i)
	{
		if (allConnections[i]->index == index)
			return i;
	}

	return -1;
}

void Neuron::ClearConnections()
{
    for(int i = 0; i < allConnections.size(); i++)
    {
        delete allConnections[i];
    }
    allConnections.clear();
    numConnections = 0;
}

void Neuron::SetRandomBias()
{
	bias = RandomFloatInRange(NeuronBiasMin, NeuronBiasMax);
}

void Neuron::SetZero()
{
	ClearConnections();
	bias = 0.0;
}

void Neuron::SetTunnelConnection(int indexconnection)
{
	bias = 0.0;
	
	for (int i = 0; i < numConnections; ++i)
	{
		if (allConnections[i]->index == indexconnection)
			allConnections[i]->weight = 1.0;
	}
	
}

void NeuronConnection::SetRandomWeight()
{
	weight = RandomFloatInRange(ConnectionWeightMin, ConnectionWeightMax);
}
void NeuronConnection::SetNullWeight()
{
    weight = 0;
}
double Neuron::ActivationSimple(double value)
{
	return (value >= 0.5) ? 1.0 : 0.0;
}

double Neuron::PlusMinusActivation(double value)
{
	if (value >= 0.5)
		return 1.0;
	else if (value <= -0.5)
		return -1.0;

	return 0.0f;
}

double Neuron::RadialBasisActivation(double value)
{
	return ((value >= 0.45) && (value <= 0.55)) ? 1.0 : 0.0;
}

double Neuron::LinearActivation(double value)
{
	if (value > 1.0)
		value = 1.0;
	else if (value < 0.0)
		value = 0.0;

	return value;
}

double Neuron::SigmoidActivation(double value) // 1/(1+e^-x)
{
	return (1.0 / (1.0 + pow(EPS, -value)));
}
