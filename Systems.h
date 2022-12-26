#pragma once

//System headers
#include <fstream>
#include <thread>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>

const double PI = acos(-1.0);

#define MaxConnections_Basic 4
#define MaxConnections_Input 4
#define MaxConnections_Random 1
#define MaxConnections_RadialBasis 4
#define MaxConnections_Memory 4
//const int NeuronsInLayer[] = { 5,5,5,5 };

#define C1 40
#define C2 -10
#define C3 -120
#define sigma1 0.25
#define sigma2 0.003
#define e1 0.25
#define e2 0.25
#define e3 0.25
#define eta1 1.15
#define eta2 1.15
#define xi1 0.105
#define xi2 0.105

#define deltax 1

#define MaxDeep -150

#define NeuronBiasMin -100
#define NeuronBiasMax 100

#define ConnectionWeightMin -100
#define ConnectionWeightMax 100

#define EPS 2.71828182845904

#define PopulationSize 1000

//Get random number (0 to max-1)
#define RandomVal(max) (rand()%(max))

//Get random float in given range
inline double RandomFloatInRange(double min, double max)
{
	return min + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (max - min)));
}
//Roll (chance in percents)
#define RandomPercent(val) ((rand()%1000)>=(1000 - (val * 10)))

//Roll (chance in 1/10 percent)
#define RandomPercentX10(val) ((rand()%1000)>=(1000 - (val)))

//Simple loop
#define repeat(times) for(int i=0;i<times;++i)
