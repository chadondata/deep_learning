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
 * File:   layer.cpp
 * Author: Chad Harper <chad.harper@gmail.com>
 *
 * Adapted from https://www.youtube.com/watch?v=c69KRgtmNSY
 * 
 * Created on June 30, 2018, 2:12 AM
 */

#include "layer.h"

Layer::Layer(int size) {
    for(int i = 0; i < size; i++) this->neurons.push_back(new Neuron(0.0));
    this->size = size;
}

void Layer::set_value(int index, double value) {
    this->neurons.at(index)->set_value(value);
}

Matrix * Layer::to_matrix_value() {
    Matrix *m = new Matrix(1, this->neurons.size(), false);
    for(int i=0; i < this->neurons.size(); i++) {
        m->set_value(0, i, this->neurons.at(i)->get_value()); 
    }
    return m;
}

Matrix * Layer::to_matrix_activated_value() {
    Matrix *m = new Matrix(1, this->neurons.size(), false);
    for(int i=0; i < this->neurons.size(); i++) {
        m->set_value(0, i, this->neurons.at(i)->get_activated_value()); 
    }
    return m;
}

Matrix * Layer::to_matrix_derived_value() {
    Matrix *m = new Matrix(1, this->neurons.size(), false);
    for(int i=0; i < this->neurons.size(); i++) {
        m->set_value(0, i, this->neurons.at(i)->get_derived_value()); 
    }
    return m;
}
