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
 * File:   neuron.h
 * Author: Chad Harper <chad.harper@gmail.com>
 *
 * Created on June 30, 2018, 1:47 AM
 * 
 * Adapted from: https://www.youtube.com/watch?v=PQo78WNGiow
 */

#ifndef NEURON_H
#define NEURON_H

#define NEURON_VALUE 0
#define NEURON_ACTIVATED 1
#define NEURON_DERIVED 2

#include <iostream>
using namespace std;

class Neuron {
public:
    // Constructor
    Neuron(double value);
    
    // Set the value of the neuron
    void set_value(double value);
    
    // Uses the fast sigmoid function to activate the value
    // f(x) = x / (1 + |x|)
    void activate();
    
    // Derivative for fast sigmoid function
    // f'(x) = f(x) * (1 + f(x)
    void derive();
    
    // Accessor functions
    double get_value() { return this->value; }
    double get_activated_value() { return this->activated_value; }
    double get_derived_value() { return this->derived_value; }
    
private:
    // The value input in the constructor
    double value;
    
    // The activated value of the neuron
    double activated_value;
    
    // The derived value of the neuron
    double derived_value;
    
};


#endif /* NEURON_H */

