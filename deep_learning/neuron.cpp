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
 * File:   neuron.cpp
 * Author: Chad Harper <chad.harper@gmail.com>
 *
 * Created on June 30, 2018, 1:47 AM
 * 
 * Adapted from: https://www.youtube.com/watch?v=PQo78WNGiow
 */

#include "neuron.h"
#include "math.h"

// Constructor
Neuron::Neuron(double value) {
    set_value(value);
}

void Neuron::set_value(double value) {
    this->value = value;
    activate();
    derive();
}

void Neuron::activate() {
    this->activated_value = this->value / (1 + fabs(this->value));
}

void Neuron::derive() {
    this->derived_value = this->activated_value * (1 - this->activated_value);
}
