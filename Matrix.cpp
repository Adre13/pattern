//
// Created by msi on 03.12.2018.
//

#include "Matrix.h"
template <typename T>
Matrix<T>::Matrix(unsigned X, unsigned Y)
{
    sizeX = X;
    sizeY = Y;
    mass = new T*[X];
    for(auto i = 0; i < X; i++)
    {
        mass[i] = new T[Y];
        for(auto j = 0; j < Y; j++)
        {
            mass[i][j] = 0;
        }
    }
}

template <typename T>
Matrix<T>::~Matrix()
{
    for(auto i = 0; i < sizeX; i++)
    {
        delete [] mass[i];
    }
    delete[] mass;
}

template <typename T>
Matrix<T>::Matrix(const Matrix &from)
{
    this->sizeX = from.sizeX;
    this->sizeY = from.sizeY;
    this->mass = new T*[this->sizeX];
    for(auto i = 0; i < this->sizeX; i++)
    {
        this->mass[i] = new T[this->sizeY];
        for(auto j = 0; j < this->sizeY; j++)
        {
            this->mass[i][j] = from.mass[i][j];
        }
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix &&from)
{
    this->sizeX = from.sizeX;
    this->sizeY = from.sizeY;
    this->mass = new T*[this->sizeX];
    for(auto i = 0; i < this->sizeX; i++)
    {
        this->mass[i] = new T[this->sizeY];
        for(auto j = 0; j < this->sizeY; j++)
        {
            this->mass[i][j] = from.mass[i][j];
        }
    }
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix &right)
{
    if(this == &right)
    {
        return  *this;
    }
    this->sizeX = right.sizeX;
    this->sizeY = right.sizeY;
    this->mass = new T*[this->sizeX];
    for(auto i = 0; i < this->sizeX; i++)
    {
        this->mass[i] = new T[this->sizeY];
        for(auto j = 0; j < this->sizeY; j++)
        {
            this->mass[i][j] = right.mass[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix &&right)
{
    if(this == &right)
    {
        return  *this;
    }
    this->sizeX = right.sizeX;
    this->sizeY = right.sizeY;
    this->mass = new T*[this->sizeX];
    for(auto i = 0; i < this->sizeX; i++)
    {
        this->mass[i] = new T[this->sizeY];
        for(auto j = 0; j < this->sizeY; j++)
        {
            this->mass[i][j] = right.mass[i][j];
        }
    }
    return *this;
}

template <typename T>
void Matrix<T>::operator*(const T x)
{
    for(auto i = 0; i < this->sizeX; i++)
    {
        for(auto j = 0; j < this->sizeY; j++)
        {
            this->mass[i][j] *= x;
        }
    }
}

template <typename T>
void Matrix<T>::operator/(const T x)
{
    if(x == 0 || x == 0.0)
    {
        std::cout << "\nYou can not use zero=)" << std::endl;
        return;
    }
    for(auto i = 0; i < this->sizeX; i++)
    {
        for(auto j = 0; j < this->sizeY; j++)
        {
            this->mass[i][j] /= x;
        }
    }
}

template <typename T>
void Matrix<T>::operator+(const Matrix &right)
{
    if(this->sizeY == right.sizeY || this->sizeX == right.sizeX)
    {
        for(auto i = 0; i < this->sizeX; i++)
        {
            for(auto j = 0; j < this->sizeY; j++)
            {
                this->mass[i][j] += right.mass[i][j];
            }
        }
    }else
    {
        std::cout << "\nThe size of Matrix must be equal=)" << std::endl;
        return;
    }
}

template <typename T>
void Matrix<T>::operator-(const Matrix &right)
{
    if(this->sizeY == right.sizeY || this->sizeX == right.sizeX)
    {
        for(auto i = 0; i < this->sizeX; i++)
        {
            for(auto j = 0; j < this->sizeY; j++)
            {
                this->mass[i][j] -= right.mass[i][j];
            }
        }
    }else
    {
        std::cout << "\nThe size of Matrix must be equal=)" << std::endl;
        return;
    }
}
template <typename T>
unsigned Matrix<T>::getSizeX(void){ return sizeX; }
template <typename T>
unsigned Matrix<T>::getSizeY(void){ return sizeY; }
template <typename T>
const T** Matrix<T>::getMass(void){ return mass;}

template <typename T>
void printMatrix(Matrix<T> obj)
{
    for(auto i = 0; i < obj.getSizeX(); i++ )
    {
        for(auto j = 0; j < obj.getSizeY(); j++)
        {
            std::cout << std::cout.width(4) << obj.getMass()[i][j];
        }
        std::cout << std::endl;
    }
}

//std::ostream& operator<<(std::ostream& out, Matrix& obj)
//{
//    for(auto i = 0; i < obj.getSizeX(); i++ )       //если передать объект const, то как сделать const getSizeX() ???
//    {
//        for(auto j = 0; j < obj.getSizeY(); j++)
//        {
//            std::cout << std::cout.width(4) << obj.getMass()[i][j];
//        }
//        std::cout << std::endl;
//    }
//    return out;
//}
//
//std::istream& operator>>(std::istream& in, Matrix& obj)
//{
//    for(auto i = 0; i < obj.getSizeX(); i++ )
//    {
//        for(auto j = 0; j < obj.getSizeY(); j++)
//        {
//            std::cin << obj.getMass()[i][j];
//        }
//    }
//    return in;
//}