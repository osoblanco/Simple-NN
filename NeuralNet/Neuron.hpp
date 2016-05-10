//
//  Neuron.hpp
//  NeuralNet
//
//  Created by Erik Arakelyan on 5/11/16.
//  Copyright © 2016 Erik Arakelyan. All rights reserved.
//

#ifndef Neuron_hpp
#define Neuron_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;

#endif /* Neuron_hpp */


// _________________  Neuron ____________________________________

class Neuron;

typedef vector<Neuron> LayerOfNet; // every layer is a vector of Neurons





struct Connection
{
    double weights;
    double deltaWeights; // weight change
    
};

class Neuron
{
    
public:
    Neuron(unsigned numberOfOutputs, unsigned neuron_index); // argument - number of neurons in the next layer
    void feedForward(const LayerOfNet previousLayer);
    
    //setter and getter
    
    void setOutputValue(double value) {outputValue =value;}
    double getOutputValue(){return outputValue;}
    
    //gradients
    void calaculateOutputGradient(double targetedValues);
    void calculateHiddenGradients(const LayerOfNet &nextLayer);
    void updateInputWeights(LayerOfNet &previousLayer); //updates the weights it feeds from
    
private:
    static double eta;
    static double alpha;
    
    static double initialWeight(void){ return rand()/double(RAND_MAX);} //look up the notes for batter init
    static double activationFunction(double preactivation);
    static double activationFunctionDerivative(double x);
    double sumDOW(const LayerOfNet &nextLayer) const;
    
    double outputValue;
    vector <Connection> outgoingWeights;
    unsigned neuron_index;
    double gradient;
    
    
};

