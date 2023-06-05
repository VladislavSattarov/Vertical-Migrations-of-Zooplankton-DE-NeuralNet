#pragma once

//System headers
#include <fstream>
#include <thread>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>

//Get random float in given range
inline double RandomFloatInRange(double min, double max)
{
    return min + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (max - min)));
}

const double PI = acos(-1.0);

#define MaxConnections_Basic 4
#define MaxConnections_Input 4
#define MaxConnections_Random 1
#define MaxConnections_RadialBasis 4
#define MaxConnections_Memory 4
//const int NeuronsInLayer[] = { 5,5,5,5 };

//#define C1 40
//#define C2 -10
//#define C3 -120
//#define sigma1 0.25
//#define sigma2 0.003
//#define e1 0.25
//#define e2 0.25
//#define e3 0.25
//#define eta1 1.15
//#define eta2 1.15
//#define xi1 0.105
//#define xi2 0.105

#define deltax 1

//#define MaxDeep -150

#define NeuronBiasMin -100
#define NeuronBiasMax 100

#define ConnectionWeightMin -100
#define ConnectionWeightMax 100

#define EPS 2.71828182845904


class Settings
{
    int C1 = 40;
    int C2 = -10;
    int C3 = -120;
    //double sigma1 = 0.25;
    //double sigma2 = 0.003;
    //double e1 = 0.25;
    //double e2 = 0.25;
    //double e3 = 0.25;
    double eta1 = 1.15;
    double eta2 = 1.15;
    double xi3 = 0.105;
    double xi4 = 0.105;
    bool noise = false;
    bool dif = false;
    double per = 0;
    public:
    int MaxDeep = -150;
    double xi1 = 0.02;
    double xi2 = 0.025;
    bool Col = false;
public:
    bool isDif()
    {
        if(dif == true)
            return true;
        else return false;
    }

    int GetC1()
    {
        return C1;
    }
    int GetC2()
    {
        return C2;
    }
    int GetC3()
    {
        return C3;
    }
    void SetC1(int C1)
    {
        this->C1 = C1;
    }
    void SetC2(int C2)
    {
        this->C2 = C2;
    }
    void SetC3(int C3)
    {
        this->C3 = C3;
    }
double E(double x)
{
    //return sigma1 * (tanh(e1 * x + C1) + 1);
    if(noise == false)
    return  (tanh(xi1 * (x + C1)) + 1.)/2.;
    else
    return  (tanh(xi1 * (x + C1)) + 1.)/2. + RandomFloatInRange(-per, per);
}
double Sx(double x)
{
    //return sigma2 * (tanh(e2 * x + C1) + 1);
    return (tanh(xi2 * (x + C1)) + 1)/2.;
}
double St(double t)
{
    //return cos(2 * PI * t) + 1.;
    return (cos(2 * PI * (t/1440. + 1./2.)) + 1.)/2.;
}
double G(double x)
{
    return xi3 * pow(eta1, x - C2) + xi4 * pow(eta2, -(x - C3)) / 2;
}
Settings()
{
}
Settings(int C1, int C2, int C3, double eta1, double eta2, double xi1, double xi2, double xi3, double xi4, bool noise, double per, int MaxDeep, bool dif)
{
    this->C1 = C1;
    this->C2 = C2;
    this->C3 = C3;
    this->eta1 = eta1;
    this->eta2 = eta2;
    this->xi1 = xi1;
    this->xi2 = xi2;
    this->xi3 = xi3;
    this->xi4 = xi4;
    this->noise = noise;
    this->per = per;
    this->MaxDeep = MaxDeep;
    this->dif = dif;
}

Settings(int C1, int C2, int C3, double eta1, double eta2, double xi1, double xi2, double xi3, double xi4, bool noise, double per, int MaxDeep, bool dif, bool col)
{
    this->C1 = C1;
    this->C2 = C2;
    this->C3 = C3;
    this->eta1 = eta1;
    this->eta2 = eta2;
    this->xi1 = xi1;
    this->xi2 = xi2;
    this->xi3 = xi3;
    this->xi4 = xi4;
    this->noise = noise;
    this->per = per;
    this->MaxDeep = MaxDeep;
    this->dif = dif;
    this->Col = col;
}
};

//Get random number (0 to max-1)
#define RandomVal(max) (rand()%(max))

//Roll (chance in percents)
#define RandomPercent(val) ((rand()%1000)>=(1000 - (val * 10)))

//Roll (chance in 1/10 percent)
#define RandomPercentX10(val) ((rand()%1000)>=(1000 - (val)))

//Simple loop
#define repeat(times) for(int i=0;i<times;++i)
