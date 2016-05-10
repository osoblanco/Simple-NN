//
//  TrainingData.hpp
//  NeuralNet
//
//  Created by Erik Arakelyan on 5/11/16.
//  Copyright © 2016 Erik Arakelyan. All rights reserved.
//

#ifndef TrainingData_hpp
#define TrainingData_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;

#endif /* TrainingData_hpp */


// ___________________________________ Training Data ___________________________

class TrainingData
{
public:
    TrainingData(const string filename);
    bool isEof(void) { return m_trainingDataFile.eof(); }
    void getTopology(vector<unsigned> &topology);
    
    // Returns the number of input values read from the file:
    unsigned getNextInputs(vector<double> &inputVals);
    unsigned getTargetOutputs(vector<double> &targetOutputVals);
    
private:
    ifstream m_trainingDataFile;
};

