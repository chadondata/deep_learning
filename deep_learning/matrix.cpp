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
 * File:   matrix.cpp
 * Author: Chad Harper <chad.harper@gmail.com>
 *
 * Created on June 30, 2018, 2:25 AM
 */

#include <random>

#include "matrix.h"

Matrix::Matrix(int row_count, int column_count, bool randomize) {
    this->row_count = row_count;
    this->column_count = column_count;
    
    for(int i = 0; i < row_count; i++) {
        vector<double> column_values;
        for(int j = 0; j < column_count; j++) {
            column_values.push_back((randomize ? this->random_number() : 0.0));
        }
        this->values.push_back(column_values);
    }
}

double Matrix::random_number() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    
    return dis(gen);
    
}

void Matrix::dump() {
    cout << endl << "Dump of Matrix:" << endl;
    for(int i = 0; i < this->row_count; i++) {
        for(int j = 0; j < this->column_count; j++) {
            cout << this->values.at(i).at(j) << "\t\t";
        }
        cout << endl;
    }
}

void Matrix::set_value(int row, int column, double value) {
    this->values.at(row).at(column) = value;
}

Matrix * Matrix::transpose() {
    Matrix *m = new Matrix(this->column_count, this->row_count, false);
    for(int i = 0; i < this->row_count; i++) {
        for(int j = 0; j < this->column_count; j++) {
            m->set_value(j, i, this->get_value(i, j));
        }
    }
    return m;
}