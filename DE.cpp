#include "DE.h"

void DE::MakePopulation(int PopulationSize, Settings sett)
{
    if(!N1.empty())
        N1.clear();
    #pragma omp parallel for
    for (int i = 0; i < PopulationSize; i++)
    {
        NeuralNet* tmp = new NeuralNet(sett);
        #pragma omp critical
        {
        N1.push_back(tmp);
        }
        //N1[i]->ProcessDay();
    }
    #pragma omp parallel for
    for (int i = 0; i < PopulationSize; i++)
    {
    N1[i]->ProcessDay();
    }
}

NeuralNet* DE::Mutate(int index)
{
    int randindex = rand() % (N1.size());
    while(randindex == index)
    {
        randindex = rand() % (N1.size());
    }
    NeuralNet Y1 = *N1[randindex];
    NeuralNet Y2 = *N1[index];
    NeuralNet* Mutated = new NeuralNet(settings);
    if(settings.Col)
        Mutated->AddColNeurons();
    for (int i = 0; i < N1[index]->m_layers.size(); i++)
    {
        for (int j = 0; j < N1[index]->m_layers[i].size(); j++)
        {
            for (int x = 0; x < N1[index]->m_layers[i][j]->allConnections.size(); x++)
            {

                Mutated->m_layers[i][j]->allConnections[x]->weight = N1[index]->m_layers[i][j]->allConnections[x]->weight + F * (Y1.m_layers[i][j]->allConnections[x]->weight - Y2.m_layers[i][j]->allConnections[x]->weight);
            }
            Mutated->m_layers[i][j]->bias = N1[index]->m_layers[i][j]->bias + F * (Y1.m_layers[i][j]->bias - Y2.m_layers[i][j]->bias);
        }
    }
    return Mutated;
}

void DE::Crossover(NeuralNet* mutated)
{
#pragma omp parallel for
    for (int i = 0; i < N1.size(); i++)
    {
        NeuralNet* tmp = new NeuralNet;
        if(settings.Col)
            tmp->AddColNeurons();
        *tmp = *N1[i];
        for (int j = 0; j < N1[i]->m_layers.size(); j++)
        {
            for (int k = 0; k < N1[i]->m_layers[j].size(); k++)
            {
                if(RandomFloatInRange(0, 1) <= P)
                {
                    tmp->m_layers[j][k]->bias = mutated->m_layers[j][k]->bias;
                }
                else
                {
                    tmp->m_layers[j][k]->bias = N1[i]->m_layers[j][k]->bias;
                }
                for (int x = 0; x < N1[i]->m_layers[j][k]->allConnections.size(); x++)
                {

                if (RandomFloatInRange(0, 1) <= P)
                {
                    tmp->m_layers[j][k]->allConnections[x]->weight = mutated->m_layers[j][k]->allConnections[x]->weight;
                }
                else
                {
                    tmp->m_layers[j][k]->allConnections[x]->weight = N1[i]->m_layers[j][k]->allConnections[x]->weight;
                }
                }
            }
        }
#pragma omp critical
        {
        N2.push_back(tmp);
        }
    }
/*	for (int i = 0; i < N2.size(); i++)
    {
        N2[i]->migrationx1.clear();
        N2[i]->migrationx2.clear();
    }*/
}

void DE::Selection(int i, int countop)
{
    /*if(settings.Col)
    {
        if(settings.isDif())
        {
         NeuralNet tmp = *N1[0];
            tmp.migrationx1.clear();
            tmp.migrationx2.clear();
            tmp.ProcessDay();
        double ic = (double)i/(double)countop;
        int randC1 = settings.GetC1() + ic * RandomFloatInRange(-5, 5);
        int randC2 = settings.GetC2() + ic * RandomFloatInRange(-15, 5);
        int randC3 = settings.GetC3() + ic * RandomFloatInRange(-5, 15);
        for (int i = 0; i < N1.size(); i++)
        {
            N1[i]->settings.SetC1(randC1);
            N1[i]->settings.SetC2(randC2);
            N1[i]->settings.SetC3(randC3);

            N2[i]->settings.SetC1(randC1);
            N2[i]->settings.SetC2(randC2);
            N2[i]->settings.SetC3(randC3);
            N1[i]->migrationx1.clear();
            N1[i]->migrationx2.clear();
            N2[i]->migrationx1.clear();
            N2[i]->migrationx2.clear();
            N1[i]->ProcessDay();
            N2[i]->ProcessDay();
            if (Fit(N1[i]) < Fit(N2[i])) // Fit - ??????? ???????
            {
                *N1[i] = *N2[i];
            }
            if (Fit(&tmp) < Fit(N1[i]))
            {
                tmp = *N1[i];
            }
        }
        }
        else{
            for (int i = 0; i < N1.size(); i++)
            {
                N1[i]->migrationx1.clear();
                N1[i]->migrationx2.clear();
                N2[i]->migrationx1.clear();
                N2[i]->migrationx2.clear();
                N1[i]->ProcessDay();
                N2[i]->ProcessDay();
            }
            for (int i = 0; i < N1.size(); i++)
            {
                for(int x = 0; x < N1[i]->migrationx1.size(); x++)
                {
                    for (int j = 0; j < N1.size(); j++)
                        {
                            if(N1[i]->migrationx2[x] < N1[j]->migrationx2[x] + 5 && N1[i]->migrationx2[x] > N1[j]->migrationx2[x] - 5)
                            {
                                N1[i]->localx2[x]++;
                            }
                        }
                }
            }
            for (int i = 0; i < N2.size(); i++)
            {
                for(int x = 0; x < N2[i]->migrationx1.size(); x++)
                {
                    for (int j = 0; j < N2.size(); j++)
                        {
                            if(N2[i]->migrationx2[x] < N1[j]->migrationx2[x] + 5 && N2[i]->migrationx2[x] > N1[j]->migrationx2[x] - 5)
                            {
                                N2[i]->localx2[x]++;
                            }
                        }
                }
            }
            NeuralNet tmp = *N1[0];
            tmp.migrationx1.clear();
            tmp.migrationx2.clear();
            tmp.ProcessDay();

            for (int i = 0; i < N1.size(); i++)
            {
                N1[i]->migrationx1.clear();
                N1[i]->migrationx2.clear();
                N2[i]->migrationx1.clear();
                N2[i]->migrationx2.clear();
                N1[i]->ProcessDay();
                N2[i]->ProcessDay();

                if (Fit(N1[i]) < Fit(N2[i])) // Fit - ??????? ???????
                {
                    *N1[i] = *N2[i];
                }
                if (Fit(&tmp) < Fit(N1[i]))
                {
                    tmp = *N1[i];
                }
            }
        }
    }*/
    //else{
    NeuralNet tmp = *N1[0];
    std::vector<double> FitsN1;
    std::vector<double> FitsN2;
    if(settings.isDif())
    {
    double ic = (double)i/(double)countop;
    int randC1 = settings.GetC1();// + RandomFloatInRange(-5, 5);
    int randC2 = settings.GetC2();// + RandomFloatInRange(-30, 0);
    int randC3 = settings.GetC3();// + RandomFloatInRange(0, 30);
    #pragma omp parallel for
    for (int i = 0; i < N1.size(); i++)
    {
        N1[i]->settings.SetC1(randC1);
        N1[i]->settings.SetC2(randC2);
        N1[i]->settings.SetC3(randC3);

        N2[i]->settings.SetC1(randC1);
        N2[i]->settings.SetC2(randC2);
        N2[i]->settings.SetC3(randC3);
        N1[i]->migrationx1.clear();
        N1[i]->migrationx2.clear();
        N2[i]->migrationx1.clear();
        N2[i]->migrationx2.clear();
        N1[i]->ProcessDay();
        N2[i]->ProcessDay();
    }
    for (int i = 0; i < N1.size(); i++)
    {
    FitsN1.push_back(Fit(N1[i]));
    FitsN2.push_back(Fit(N2[i]));
    }
    randC1 = settings.GetC1() + 10;//RandomFloatInRange(-5, 5);
    randC2 = settings.GetC2() - 30;//RandomFloatInRange(-30, 0);
    randC3 = settings.GetC3() + 40;//RandomFloatInRange(0, 30); // ИЗМЕНИЛ
    for (int i = 0; i < N1.size(); i++)
    {
        N1[i]->settings.SetC1(randC1);
        N1[i]->settings.SetC2(randC2);
        N1[i]->settings.SetC3(randC3);

        N2[i]->settings.SetC1(randC1);
        N2[i]->settings.SetC2(randC2);
        N2[i]->settings.SetC3(randC3);
        N1[i]->migrationx1.clear();
        N1[i]->migrationx2.clear();
        N2[i]->migrationx1.clear();
        N2[i]->migrationx2.clear();
        N1[i]->ProcessDay();
        N2[i]->ProcessDay();
    }
    for (int i = 0; i < N1.size(); i++)
    {
    FitsN1[i] += (Fit(N1[i]));
    FitsN2[i] += (Fit(N2[i]));
    }
    #pragma omp parallel for shared(tmp)
    for (int i = 0; i < N1.size(); i++)
    {
        if (FitsN1[i] < FitsN2[i]) // Fit - ??????? ???????
        {
            *N1[i] = *N2[i];
        }
        #pragma omp critical
        {
        if (Fit(&tmp) < Fit(N1[i]))
        {
            tmp = *N1[i];
        }
        }
    }
    }
    else{
        #pragma omp parallel for
        for (int i = 0; i < N1.size(); i++)
        {
            N2[i]->migrationx1.clear();
            N2[i]->migrationx2.clear();
            N2[i]->ProcessDay();
        }
        #pragma omp parallel for shared(tmp)
        for (int i = 0; i < N1.size(); i++)
        {
            /*N2[i]->migrationx1.clear();
            N2[i]->migrationx2.clear();
            N2[i]->ProcessDay();*/
            if (Fit(N1[i]) < Fit(N2[i])) // Fit - ??????? ???????
            {
                *N1[i] = *N2[i];
            }
            #pragma omp critical
            {
            if (Fit(&tmp) < Fit(N1[i]))
            {
                tmp = *N1[i];
            }
            }
        }
    }

    Fits.push_back(Fit(&tmp));
    for (int i = 0; i < N2.size(); i++)
    {
        delete N2[i];
    }
    N2.clear();

}

NeuralNet DE::process(int CountOperations, int PopulationSize, Settings set)
{
    settings = set;
    MakePopulation(PopulationSize, settings);
    NeuralNet tmp = *N1[0];
    for (int i = 1; i < N1.size(); i++)
    {
        if (Fit(&tmp) < Fit(N1[i]))
        {
            tmp = *N1[i];
        }
    }
    Fits.push_back(Fit(&tmp));
    for (int i = 0; i < CountOperations; i++)
    {
        Mutated = Mutate(RandomVal(N1.size()));
        Crossover(Mutated);
        Selection(i, CountOperations);
    }
    tmp = *N1[0];
    tmp.settings = this->settings;
    tmp.migrationx1.clear();
    tmp.migrationx2.clear();
    tmp.ProcessDay();
    #pragma omp parallel for
    for (int i = 1; i < N1.size(); i++)
    {
        N1[i]->settings = this->settings;
        N1[i]->migrationx1.clear();
        N1[i]->migrationx2.clear();
        N1[i]->ProcessDay();
    }
    #pragma omp parallel for shared(tmp)
    for (int i = 1; i < N1.size(); i++)
    {
        if (Fit(&tmp) < Fit(N1[i]))
        {
            #pragma omp critical
            {
            tmp = *N1[i];
            }
        }
    }
    Fits.push_back(Fit(&tmp));
    return tmp;
}

std::vector<NeuralNet*> DE::process(std::vector<NeuralNet*> Pop, int CountOperations, Settings set)
{
    settings = set;
    N1.clear();
    N2.clear();
    for(int i = 0; i < Pop.size(); i++)
    {
        N1.push_back(Pop[i]);
        N1[i]->AddColNeurons();
    }
    for (int i = 0; i < CountOperations; i++)
    {
        Mutated = Mutate(RandomVal(N1.size()));
        Crossover(Mutated);

        Selection(i, CountOperations);
    }
    return N1;
}

double DE::Fit(NeuralNet* tmp)
{
    double P = alpha_j * tmp->GetM1() - beta_j * tmp->GetM3() - delta_j * tmp->GetM4(); //0.0016, 0.0000007, 0.000016
    double Q = gamma_j * tmp->GetM2(); // 0.00008 Q
    double S = gamma_a * tmp->GetM6(); // 0.004 S
    double R = alpha_a * tmp->GetM5() - beta_a * tmp->GetM7() - delta_a * tmp->GetM8(); // 0.006, 0.0000075, 0.00006
    return -P - S - Q + sqrt(4 * R * P + pow(P + Q - S, 2));
    //return P + Q + S + R;
}



