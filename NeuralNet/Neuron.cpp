//
//  Neuron.cpp
//  NeuralNet
//
//  Created by Erik Arakelyan on 5/11/16.
//  Copyright © 2016 Erik Arakelyan. All rights reserved.
//

#include "Neuron.hpp"

double Neuron:: eta = 0.2; // momentum adder
double Neuron:: alpha = 0.5; //hyperparametr for learning rate

void Neuron::updateInputWeights(LayerOfNet &previousLayer)
{
    //The updated version of weights are gona be in outgoingWeights of previous layers neurons
    
    for(unsigned n = 0; n < previousLayer.size(); n++)//inclding the bias
    {
        Neuron &neuron = previousLayer[n];
        double oldDeltaWeight = neuron.outgoingWeights[neuron_index].deltaWeights;
        
        alpha = 0.5; // momentum adder
        eta = 0.2; //hyperparametr for learning rate
        
        //updating parametrs with momentum
        
        double newDeltaWeight = eta * neuron.getOutputValue() * gradient + alpha*oldDeltaWeight; // theta + alpha * delta
        
        neuron.outgoingWeights[neuron_index].deltaWeights = newDeltaWeight;
        neuron.outgoingWeights[neuron_index].weights += newDeltaWeight;
        
    }
    
}

double Neuron::sumDOW(const LayerOfNet &nextLayer) const
{
    double sum = 0.0;
    
    //sum all the error contributions we make to the next layer neurons
    
    for(unsigned n = 0; n < nextLayer.size() - 1 ; n++)
    {
        sum += outgoingWeights[n].weights * nextLayer[n].gradient;
    }
    
    return sum;
}

void Neuron:: calculateHiddenGradients(const LayerOfNet &nextLayer)
{
    double derOfWeights = sumDOW(nextLayer); // sum of the derivatives of weights of next layer
    gradient = derOfWeights * Neuron::activationFunctionDerivative(outputValue);
}

void Neuron:: calaculateOutputGradient(double targetedValues, vector <LayerOfNet> layers)
{
    double delta = targetedValues - outputValue;
    gradient = delta * activationFunctionDerivative(outputValue);
    
    
    /*
    double regularizationL2 = 0.0;
    int overalCount = 0;
    for(int i = 0; i <layers.size()-1; i++ )
        for(int j=0; j<layers[i].size()-1;j++)
        {
            regularizationL2 += layers[i][j].outgoingWeights[neuron_index].weights;
            overalCount++;
        }
    
    regularizationL2 /= overalCount;
    
    regularizationL2 *= 0.002;
    gradient -= regularizationL2;
    */
}



void Neuron::feedForward(const LayerOfNet previousLayer)
{
    double sum = 0.0;
    
    //1) now here we know that preActivationFunction = sum(x_i *w_i) + bias
    
    for(unsigned neuronNum = 0; neuronNum < previousLayer.size();neuronNum++)
    {
        sum += previousLayer[neuronNum].outputValue * previousLayer[neuronNum].outgoingWeights[neuron_index].weights;
    }
    
    // 2) Now lets Activate the Neuron
    
    outputValue = Neuron::activationFunction(sum);
}

Neuron:: Neuron(unsigned numberOfOutputs, unsigned neuronIndex)
{
    
    for(unsigned connectionCount = 0; connectionCount < numberOfOutputs; connectionCount++)
    {
        outgoingWeights.push_back(Connection());
        outgoingWeights.back().weights = initialWeight();
        
    }
    neuron_index = neuronIndex;
}

double sigmoid(double x)
{
    return 1/(1+exp(-x));
}


double Neuron::activationFunction(double preactivation)
{
    
    return tanh(preactivation);
  //  return sigmoid(preactivation);
}

double Neuron::activationFunctionDerivative(double x)
{
    return 1.0 -x*x;
   // return sigmoid(x)*(1-sigmoid(x)); use for sigmoid output

}
