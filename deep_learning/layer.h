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
 * File:   layer.h
 * Author: Chad Harper <chad.harper@gmail.com>
 *
 * Adapted from https://www.youtube.com/watch?v=c69KRgtmNSY
 * 
 * Created on June 30, 2018, 2:12 AM
 */

#ifndef LAYER_H
#define LAYER_H
#include <iostream>
#include <vector>
#include "neuron.h"
#include "matrix.h"

using namespace std;

class Layer {
public:
    Layer(int size);
    void set_value(int index, double value);
    Matrix * to_matrix_value();
    Matrix * to_matrix_activated_value();
    Matrix * to_matrix_derived_value();
    
private:
    int size;
    
    vector<Neuron *> neurons;
};


#endif /* LAYER_H */

