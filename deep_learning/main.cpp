/*
 * Copyright (C) 2018 Chad Harper <chad.harper@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   main.cpp
 * Author: Author: Chad Harper <chad.harper@gmail.com>
 *
 * Adapted from: https://www.youtube.com/watch?v=PQo78WNGiow
 * 
 * Created on June 30, 2018, 1:29 AM
 */

#include <iostream>

#include "neuron.h"
#include "matrix.h"
#include "neural_network.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Deep Learning Fun Times" << endl;
    Neuron *n = new Neuron(1.0);
    
    cout << "Value: " << n->get_value() << endl;
    cout << "Activated Value: " << n->get_activated_value() << endl;
    cout << "Derived Value: " << n->get_derived_value() << endl;
    
    cout << endl << endl << "Matrix test" << endl;
    
    Matrix *m = new Matrix(3, 2, true);
    m->dump();
    cout << "Transpose of matrix:" << endl;
    m->transpose()->dump();
    
    const int IO_NODES = 3;
    const int HIDDEN_LAYERS = 1;
    
    vector<int> topology;
    topology.push_back(IO_NODES);
    
    for(int i = 0; i < HIDDEN_LAYERS; i++) topology.push_back(IO_NODES-1);
    
    topology.push_back(IO_NODES);
    
    vector<double> input;
    input.push_back(0.9);
    input.push_back(0.8);
    input.push_back(0.7);
    
    NeuralNetwork *nn = new NeuralNetwork(topology);
    nn->set_current_input(input);
    
    nn->dump();
    return 0;
}

