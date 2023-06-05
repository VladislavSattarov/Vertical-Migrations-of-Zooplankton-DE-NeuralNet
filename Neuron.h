#pragma once

#include "Systems.h"


struct NeuronConnection
{
	int index;
	double weight;
	void ChangeWeight();
	void SetRandomWeight();
    void SetNullWeight();
    NeuronConnection()
    {
        index = 0;
        weight = 0;
    }
    NeuronConnection(const NeuronConnection &other){
        index = other.index;
        weight = other.weight;

    }
    // Сериализация объекта NeuronConnection
    void serializeNeuronConnection(const NeuronConnection& nc, std::ofstream& ofs)
    {
        ofs.write((char*)&nc.weight, sizeof(double));
        ofs.write((char*)&nc.index, sizeof(int));
    }

    // Десериализация объекта NeuronConnection
    void deserializeNeuronConnection(std::ifstream& ifs)
    {
        ifs.read((char*)&weight, sizeof(double));
        ifs.read((char*)&index, sizeof(int));
    }
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

    Neuron(const Neuron &other);

    Neuron& operator = (const Neuron &other);

    ~Neuron();

    void Clone(const Neuron &other);

	void AddConnection(int INDEX);

    void AddNullConnection(int INDEX);

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

    void serializeNeuron(const Neuron& n, std::ofstream& ofs)
    {
        ofs.write((char*)&n.value, sizeof(double));
        ofs.write((char*)&n.type, sizeof(NeuronType));
        ofs.write((char*)&n.bias, sizeof(double));
        ofs.write((char*)&n.numConnections, sizeof(int));
        for (int i = 0; i < n.numConnections; i++) {
            n.allConnections[i]->serializeNeuronConnection(*n.allConnections[i], ofs);
        }
    }

    void deserializeNeuron(std::ifstream& ifs)
    {
        ifs.read((char*)&value, sizeof(double));
        ifs.read((char*)&type, sizeof(NeuronType));
        ifs.read((char*)&bias, sizeof(double));
        ifs.read((char*)&numConnections, sizeof(int));
        allConnections = std::vector<NeuronConnection*>(numConnections);
        for (int i = 0; i < numConnections; i++) {
            allConnections[i] = new NeuronConnection();
            allConnections[i]->deserializeNeuronConnection(ifs);
        }
    }

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
