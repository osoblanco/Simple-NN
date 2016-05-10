//
//  main.cpp
//  NeuralNet
//
//  Created by Erik Arakelyan on 5/10/16.
//  Copyright © 2016 Erik Arakelyan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <math.h>
#include <fstream>
#include <sstream>

#include "NeuralNet.hpp"
#include "TrainingData.hpp"

using namespace std;







//__________________________ Interface For testing ___________________________________


void showVectorVals(string label, vector<double> &v)
{
    cout << label << " ";
    for (unsigned i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    
    cout << endl;
}



int main() {
    
    /*
    vector <unsigned> Constructoptions; //specify the net structure EX:3-2-1
    Constructoptions.push_back(3);
    Constructoptions.push_back(2);
    Constructoptions.push_back(1);
    
    
    NeuralNet Net(Constructoptions);//number of layers, and neurons in each layer
    
    vector <double> inputValues;
    
    Net.fforward(inputValues);
    
    vector <double> targetedValues;
    
    Net.backprop(targetedValues);
    
    vector <double> retriveValues;
    Net.retrieveResults(retriveValues);
    
    */
    
    
    
    
    
    
    TrainingData trainData("/Users/Erik/Desktop/NeuralNet/NeuralNet/train.txt");
    
    // e.g., { 3, 2, 1 }
    vector<unsigned> Constructoptions;
    trainData.getTopology(Constructoptions);
    
    NeuralNet myNet(Constructoptions);
    
    vector<double> inputVals, targetVals, resultVals;
    int trainingPass = 0;
    
    while (!trainData.isEof()) {
        ++trainingPass;
        cout << endl << "Pass " << trainingPass;
        
        // Get new input data and feed it forward:
        if (trainData.getNextInputs(inputVals) != Constructoptions[0]) {
            break;
        }
        showVectorVals(": Inputs:", inputVals);
        myNet.fforward(inputVals);
        
        // Collect the net's actual output results:
        myNet.retrieveResults(resultVals);
        showVectorVals("Outputs:", resultVals);
        
        // Train the net what the outputs should have been:
        trainData.getTargetOutputs(targetVals);
        showVectorVals("Targets:", targetVals);
        assert(targetVals.size() == Constructoptions.back());
        
        myNet.backprop(targetVals);
        
        // Report how well the training is working, average over recent samples:
        cout << "Net recent average error: "
        << myNet.getRecentAverageError() << endl;
    }
    
    cout << endl << "Done" << endl;
    
    return 0;
}