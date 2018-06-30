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
 * File:   matrix.h
 * Author: Chad Harper <chad.harper@gmail.com>
 *
 * Created on June 30, 2018, 2:25 AM
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
    Matrix(int row_count, int column_count, bool randomize);
    
    Matrix *transpose();
    double random_number();
    
    void set_value(int row, int column, double value);
    double get_value(int row, int column) { return this->values.at(row).at(column); }
    
    int get_row_count() { return this->row_count; }
    int get_column_count() { return this->column_count; }
    
    void dump();
    
private:
    int row_count, column_count;
    
    vector< vector<double> > values;
};

#endif /* MATRIX_H */

