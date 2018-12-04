//
// Created by msi on 03.12.2018.
//
#include <iostream>


#ifndef PATTERN_MATRIX_H
#define PATTERN_MATRIX_H

template <typename T>
class Matrix {
private:

    T** mass;
    unsigned sizeX;
    unsigned sizeY;

public:

    Matrix() = delete;
    Matrix(unsigned X, unsigned Y);
    ~Matrix();
    Matrix(const Matrix& from);
    Matrix(const Matrix&& from);
    Matrix<T>&operator=(const Matrix& right);
    Matrix<T>&operator=(const Matrix&& right);


    unsigned getSizeX(void);
    unsigned getSizeY(void);
    const T** getMass(void);

    void operator+(const Matrix& right);
    void operator-(const Matrix& right);
    void operator*(const T x);
    void operator/(const T x);

//    friend std::ostream&operator<<(std::ostream& out, Matrix& obj);
//    friend std::istream&operator>>(std::istream& in, Matrix& obj);

};
template <typename T>
void printMatrix(Matrix<T> obj);


#endif //PATTERN_MATRIX_H
