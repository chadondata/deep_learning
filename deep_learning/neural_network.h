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
 * File:   neural_network.h
 * Author: Chad Harper <chad.harper@gmail.com>
 *
 * Created on June 30, 2018, 2:56 AM
 */

#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H
#include <iostream>
#include <vector>
#include "layer.h"
#include "matrix.h"

class NeuralNetwork {
public:
    NeuralNetwork(vector<int> topology);
    void set_current_input(vector<double> input);
    void dump();
    
private:
    int topology_size;
    vector<int> topology;
    vector<Layer *> layers;
    vector<Matrix *> weight_matrices; // = size of topology -1
    vector<double> current_input;
};


#endif /* NEURAL_NETWORK_H */

