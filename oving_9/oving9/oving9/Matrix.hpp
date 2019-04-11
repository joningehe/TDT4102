//
//  Matrix.hpp
//  oving9
//
//  Created by Jon H on 12/03/2019.
//  Copyright © 2019 JonH. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp
#include <iostream>
#include <stdio.h>

class Matrix{
    int rows;
    int columns;
    double** data;
public:
    //This is the empty matrix
    Matrix() :
    data(nullptr)
    {}
    
    //Creates a matrix and fills all the values pointed to with default 0
    Matrix(int nRows, int nColumns) :
    data(new double*[nRows]),
    rows(nRows),
    columns(nColumns)
    {
        for(int i{0}; i < rows; i++){
            data[i] = new double[columns];
            for(int j{0}; j < columns; j++){
                data[i][j] = 0;
            }
        }
    }
    
    //Uses everything from Matrix(), but creates an identitymatrix as well
    explicit Matrix(int nRows) : Matrix(nRows, nRows)
    {
        for(int i{0}; i < rows; i++){
            for(int j{0}; j < columns; j++)
                if(i == j){
                    data[i][j] = 1;
                }
        }
    }
    
                            //copy constructor allowing us to make proper copies of our object, denne var strengt talt riktig, men studass viste at man kunne legge på delegering til originale Matrix() funksjon
                            Matrix(const Matrix &rhs) : Matrix(rhs.rows, rhs.columns){
                                for(int i{0}; i < rows; i++){
                                    for(int j{0}; j < columns; j++){
                                        data[i][j] = rhs.data[i][j];
                                    }
                                }
                            }
    
                            //copy-and-swap operator ensuring deep copying
                            Matrix &operator=(Matrix rhs) {
                                std::swap(data, rhs.data);
                                std::swap(rows, rhs.rows);  //Må huske denne
                                std::swap(columns, rhs.columns);    //må huske denne også, hvis ikke funker ikke copy som intended
                                return *this;
                            }
    
    //Destructor for this class
    ~Matrix(){
        if(is_valid()){
            for(int i{0}; i < rows; i++){
                delete[] data[i];
            }
            delete[] data;
        }
    }
    
    double get_matrix(int row, int column) const;    //lag funksjon i .cpp
    void set_matrix(int row, int column, double value); //lag funksjon i .cpp
    
    int get_rows() const;    //lag funksjon i .cpp
    int get_columns() const; //lag funksjon i .cpp
    
    bool is_valid() const;    //lag funksjon i .cpp
    
    friend std::ostream &operator<<(std::ostream& os, const Matrix& m); //lag funksjon i .cpp
    
    Matrix& operator += (const Matrix &m);
    Matrix operator + (const Matrix &m);
    
};

#endif /* Matrix_hpp */
