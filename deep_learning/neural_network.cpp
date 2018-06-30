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
 * File:   neural_network.cpp
 * Author: Chad Harper <chad.harper@gmail.com>
 *
 * Created on June 30, 2018, 2:56 AM
 */

#include "neural_network.h"

NeuralNetwork::NeuralNetwork(vector<int> topology) {
    for(this->topology_size = 0; this->topology_size < topology.size(); this->topology_size++) {
        this->layers.push_back(new Layer(topology.at(this->topology_size)));        
    }
    
    for(int i = 0; i < this->topology_size-1; i++) {
        this->weight_matrices.push_back(new Matrix(topology.at(i), topology.at(i+1), true));
    }
    
    this->topology = topology;
}

void NeuralNetwork::set_current_input(vector<double> input) {
    this->current_input = input;
    
    for(int i = 0; i < input.size(); i++) {
        this->layers.at(0)->set_value(i, input.at(i));
    }
}

void NeuralNetwork::dump() {
    for(int i = 0; i < this->layers.size(); i++) {
        if(i==0) {
            Matrix *m = this->layers.at(i)->to_matrix_value();
            m->dump();
        } else {
            Matrix *m = this->layers.at(i)->to_matrix_activated_value();
            m->dump();            
        }
    }
}