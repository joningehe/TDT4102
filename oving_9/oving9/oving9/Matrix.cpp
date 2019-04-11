//
//  Matrix.cpp
//  oving9
//
//  Created by Jon H on 12/03/2019.
//  Copyright © 2019 JonH. All rights reserved.
//
#include <iostream>
#include "Matrix.hpp"


double Matrix::get_matrix(int row, int column) const {
    return this->data[row][column];
}

void Matrix::set_matrix(int row, int column, double value) {
    this->data[row][column] = value;
}

int Matrix::get_rows() const{
    return this->rows;
}

int Matrix::get_columns() const{
    return this->columns;
}

bool Matrix::is_valid() const{
    return this->data;
}

std::ostream &operator<<(std::ostream& os, const Matrix& m){
    for(int i{0}; i < m.get_rows(); i++){
        for(int j{0}; j < m.get_columns(); j++){
            os << m.data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

Matrix& Matrix::operator += (const Matrix &m){  //denne funka :D
                for(int i{0}; i<m.get_rows(); i++){
                    for(int j{0}; j < m.get_columns(); j++){
                        data[i][j] += m.data[i][j];
                    }
                }
                return *this;
            }

            Matrix Matrix::operator + (const Matrix &m){
                return Matrix(*this)+=m;    //litt usikker på hva som var forskjell fra det jeg hadde gjort, men dette var en bedre måte å gjøre det på
            }


/*Matrix operator += (Matrix const &m, Matrix const &n){
    int first_size = m.get_columns()*m.get_rows();
    int second_size = n.get_columns()*n.get_rows();
    if(first_size > second_size){
        Matrix temp(m.get_rows(), m.get_columns());
        for(int i{0}; i<m.get_rows(); i++){
            for(int j{0}; j < m.get_columns(); j++){
                temp.data[i][j] = m.data[i][j] += n.data[i][j];
            }
        }
        return temp;
    }
    else{
        Matrix temp(n.get_rows(), n.get_columns());
        for(int i{0}; i<n.get_rows(); i++){
            for(int j{0}; j < n.get_columns(); j++){
                temp.data[i][j] = n.data[i][j] += m.data[i][j];
            }
        }
        return temp;
    }
}

Matrix operator + (Matrix const &m, Matrix const &n){
    int first_size = m.get_columns()*m.get_rows();
    int second_size = n.get_columns()*n.get_rows();
    if(first_size > second_size){
        Matrix temp(m.get_rows(), m.get_columns());
        for(int i{0}; i<m.get_rows(); i++){
            for(int j{0}; j < m.get_columns(); j++){
                temp.data[i][j] = m.data[i][j] + n.data[i][j];
            }
        }
        return temp;
    }
    else{
        Matrix temp(n.get_rows(), n.get_columns());
        for(int i{0}; i<n.get_rows(); i++){
            for(int j{0}; j < n.get_columns(); j++){
                temp.data[i][j] = n.data[i][j] + m.data[i][j];
            }
        }
        return temp;
    }
}*/
