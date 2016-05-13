# Simple-NN

Here You can observe a C++ implementation of a feed forward Neural Network.

The Project is composed of several Key Components (classes - header files (.hpp) + implementations (.cpp))

Neural Net class (NeuralNet.hpp + NeuralNet.cpp)
------

This is  a class for the general construction of the Neual Network structure (object)
and training the Neural Network.

1. This class includes the constructor of the neural network. 
2. The network operation for forward propagation (fforward) is included in the class.
3. Back propagation algorithm is included in the class. 

Neuron class(Neuron.hpp + Neuron.cpp)
-------------

This is a class that is responsible for constructing the main computational unit neuron.()

1. The class includes the functionality for feeding forward (preactivating, activating) the single Neuron.
2. The class includes the functionality for the computation of all the gradients for each neuron.
3. The class includes the functionality for updating each neuron's parametrs(weights,biases) in the direction of the steepest descent.

-------------

TrainingData.hpp + TrainingData.cpp is a class for reading the XOR  data provided from the code of Dave Miller

-------------

main.cpp includes an interface for testing the neural network on various Datasets.

PS: An R code for optimizing the dataset is also provided



