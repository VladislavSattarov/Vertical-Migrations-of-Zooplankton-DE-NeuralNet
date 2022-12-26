#include "Neuron.h"




Neuron::Neuron()
{
	type = basic;
}

Neuron::Neuron(NeuronType typ)
{
	type = typ;
}

void Neuron::Clone(Neuron* source) // check
{
	memcpy(this, source, sizeof(Neuron));
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
	NeuronConnection* tmp = new NeuronConnection;
	tmp->index = index;
	tmp->SetRandomWeight();

	allConnections.push_back(tmp);
	++numConnections;
}

//bool Neuron::AddRandomConnection()
//{
//	if (numConnections >= MaxConnectionsPerNeuronType[type])
//		return false;
//
//	int connectionIndex;
//
//	for (;;)
//	{
//		connectionIndex = RandomVal(NeuronsInLayer);
//
//		if (IsConnected(connectionIndex) == -1)
//		{
//			AddConnection(connectionIndex);
//
//			return true;
//		}
//	}
//}

//void Neuron::RemoveConnection(int index)
//{
//	--numConnections;
//
//	for (int i = index; i < numConnections; ++i)
//	{
//		allConnections[i] = allConnections[i + 1];
//	}
//}

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
	numConnections = 0;
	allConnections.clear();
}

void Neuron::SetRandomBias()
{
	bias = RandomFloatInRange(NeuronBiasMin, NeuronBiasMax);
}


//void Neuron::SetRandomConnections()
//{
//	ClearConnections();
//
//	if (type == output)
//		return;
//
//#ifdef FullyConnected
//	MakeFullyConnected();
//	return;
//#endif
//
//	int connections = RandomVal(MaxConnectionsPerNeuronType[type] + 1);
//
//	for (; connections > 0; --connections)
//	{
//		if (connections > 0)
//		{
//			if (!AddRandomConnection())
//				return;
//
//		}
//	}
//}

/*void Neuron::MakeFullyConnected()
{
	repeat(NeuronsInLayer[numLayer + 1])
	{
		allConnections[i].dest = i;
		allConnections[i].SetRandomWeight();
	}

	numConnections = NeuronsInLayer[];
}*/

//void Neuron::SetRandom()
//{
//	SetRandomBias();
//	SetRandomConnections();
//}

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

//void Neuron::SlightlyChange()
//{
//	bias += (RandomVal(1001) * 0.0001f) - .05f;
//
//	for (int i = 0; i < numConnections; ++i)
//	{
//		allConnections[i].weight += (RandomVal(2001) * 0.0001f) - .1f;
//	}
//}
//
//
//
//void Neuron::mutate_ChangeBias()
//{
//	float change = RandomFloatInRange(ChangeBiasMin, ChangeBiasMax);
//
//	if (RandomPercent(50))
//		change *= -1.0f;
//
//	bias += change;
//
//	if (bias > NeuronBiasMax)
//		bias = NeuronBiasMax;
//	else if (bias < NeuronBiasMin)
//		bias = NeuronBiasMin;
//}
//
//void Neuron::mutate_ChangeOneConnection()
//{
//	if (numConnections == 0)
//		return;
//
//	int roll = RandomVal(101);
//	int connection = RandomVal(numConnections);
//
//	if (roll <= 10)
//		RemoveConnection(connection);
//	else if (roll <= 20)
//		AddRandomConnection();
//	else
//		allConnections[connection].ChangeWeight();
//
//}
//
//void Neuron::mutate_DeleteNeuron()
//{
//	SetZero();
//
//	if ((type != input) && (type != output))
//		type = basic;
//}
//
//char* Neuron::GetTextFromType(NeuronType t)
//{
//	switch (t)
//	{
//	case basic:
//		return (char*)"basic";
//	case input:
//		return (char*)"input";
//	case output:
//		return (char*)"output";
//	default:
//		return (char*)"other";
//	}
//}

//void Neuron::SortConnections()
//{
//	//TODO
//}

//void NeuronConnection::ChangeWeight()
//{
//	double change = RandomFloatInRange(ChangeConnectionWeightMin, ChangeConnectionWeightMax);
//
//	if (RandomPercent(50))
//		change *= -1.0;
//
//	weight += change;
//
//	if (weight > ConnectionWeightMax)
//		weight = ConnectionWeightMax;
//	else if (weight < ConnectionWeightMin)
//		weight = ConnectionWeightMin;
//}

void NeuronConnection::SetRandomWeight()
{
	weight = RandomFloatInRange(ConnectionWeightMin, ConnectionWeightMax);
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