#pragma once

#include "Systems.h"


struct NeuronConnection
{
	int index;
	double weight;
	void ChangeWeight();
	void SetRandomWeight();
};


enum NeuronType
{
	basic,
	input,
	output,
};

const int MaxConnectionsPerNeuronType[] =
{
	MaxConnections_Basic,
	MaxConnections_Input,
	0,
	MaxConnections_Random,
	MaxConnections_RadialBasis,
	MaxConnections_Memory
};


struct Neuron
{
private:
	double value = 0;
	NeuronType type = basic;
public:

	double bias = RandomFloatInRange(NeuronBiasMin, NeuronBiasMax);

	int numConnections = 0;

	std::vector<NeuronConnection*> allConnections;


	Neuron();
	Neuron(NeuronType type);

	void Clone(Neuron* source);

	void AddConnection(int INDEX);

	//void RemoveConnection(int index);

	int IsConnected(int index);

	void AddValue(double set)
	{
		value += set;
	}

	void ResetValue()
	{
		value = 0;
	}

	void SetRandomBias();

	void SetZero();

	void ClearConnections();

	void SetTunnelConnection(int indexconnection);

	double GetValue();

	NeuronType GetType()
	{
		return type;
	}

	static char* GetTextFromType(NeuronType t);

	double ActivationSimple(double value);
	double PlusMinusActivation(double value);
	double RadialBasisActivation(double value);
	double LinearActivation(double value);
	double SigmoidActivation(double value);

};