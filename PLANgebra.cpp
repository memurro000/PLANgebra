#ifndef PLANGEBRA_H
#define PLANGEBRA_H
    #include "PLANgebra.h"
#endif

#include <iostream>
#include <exception>
#include <iterator>
#include <stdexcept>

using namespace pla;



//====Vector====//

//Null constructor
Vector::Vector(int dim)
{
    this->dim = dim;
    this->val = new f64[dim];
    for(f64 &x : *this)
    {
        x = 0;
    }
}

//Value constructor
Vector::Vector(int dim, f64 value)
{
    this->dim = dim;
    this->val = new f64[dim];
    for(f64 &x : *this)
    {
        x = value;
    }
}

//Initializer list constructor
Vector::Vector(int dim, std::initializer_list<f64> value)
{
    this->dim = dim;
    this->val = new f64[dim];
    std::copy(value.begin(), value.end(), val);
    return;
}

//Array constructor
Vector::Vector(int dim, f64 *value)
{
    this->dim = dim;
    this->val = new f64[dim];
    std::copy(value, value + dim, val);
    return;
}

//Destructor
Vector::~Vector()
{
    delete [] val;
}

//Prints dimension and values in console
void Vector::Print()
{
    std::cout << "Vector: dimension " << dim << ", value ";
    for(int i = 0; i < dim; ++i)
    {
        //Just to demonstrate adress ariphmetics
        std::cout << *(val + i) << " ";
    }
    std::cout << "\n";

    return;
}

//Gets dimension
int Vector::GetDim() const
{
    return dim;
}

//Sets value at index
void Vector::SetAt(int index, f64 value)
{
    this->val[index] = value;
    return;
}

//Gets value at index
f64 Vector::GetAt(int index) const
{
    return this->val[index];
}


//Sets whole vector to null value
void Vector::SetNull()
{
    for(f64 &x : *this) x = 0;
    return;
}

/*
{
    return sqrt(ScalarProduct(*this, *this);
}

*/

Vector Vector::operator=(const Vector &in)
{
    if(this->dim != in.dim) throw std::invalid_argument( \
            "The equated Vectors must be of the same dimension - \n \
            You are trying to equate Vector of dimension " + \
            std::to_string(this->dim) + " with Vector of dimension " + std::to_string(in.dim));

    for(int i = 0; i < dim; ++i)
    {
        this->val[i] = in.val[i];
    }
    return *this;
}


Vector Vector::operator*(const f64 a)
{
    f64 *array = new double[dim];
    for(int i = 0; i < dim; ++i)
    {
        array[i] = this->val[i] * a;
    }
    return *(new Vector(dim, array));
}

Vector &Vector::operator*=(const f64 a)
{
    for(int i = 0; i < dim; ++i)
    {
        this->val[i] = this->val[i] * a;
    } 
    return *this;
}

Vector Vector::operator/(const f64 a)
{
    f64 *array = new double[dim];
    for(int i = 0; i < dim; ++i)
    {
        array[i] = this->val[i] / a;
    }
    return *(new Vector(dim, array));
}

Vector &Vector::operator/=(const f64 a)
{
    for(int i = 0; i < dim; ++i)
    {
        this->val[i] = this->val[i] / a;
    }
    return *this;
}

Vector Vector::operator+(const Vector &a)
{
    if(this->dim != a.dim) throw std::invalid_argument( \
            "The summed Vectors must be of the same dimension - \n \
            You are trying to summ up Vector of dimension " + \
            std::to_string(this->dim) + " with Vector of dimension " + std::to_string(a.dim));
    
    f64 *array = new double[dim];
    for(int i = 0; i < dim; ++i)
    {
        array[i] = this->val[i] + a.GetAt(i);
    }
    return *(new Vector(dim, array));
    
}

Vector &Vector::operator+=(const Vector &a)
{
    if(this->dim != a.dim) throw std::invalid_argument( \
            "The summed Vectors must be of the same dimension - \n \
            You are trying to summ up Vector of dimension " + \
            std::to_string(this->dim) + " with Vector of dimension " + std::to_string(a.dim));

    for(int i = 0; i < dim; ++i)
    {
        this->val[i] = this->val[i] + a.GetAt(i);
    }
    return *this;
}

Vector Vector::operator-(const Vector &a)
{
    if(this->dim != a.dim) throw std::invalid_argument( \
            "The summed Vectors must be of the same dimension - \n \
            You are trying to summ up Vector of dimension " + \
            std::to_string(this->dim) + " with Vector of dimension " + std::to_string(a.dim));

    f64 *array = new double[dim];
    for(int i = 0; i < dim; ++i)
    {
        array[i] = this->val[i] - a.GetAt(i);
    }
    return *(new Vector(dim, array));
    
}

Vector &Vector::operator-=(const Vector &a)
{
    if(this->dim != a.dim) throw std::invalid_argument( \
            "The summed Vectors must be of the same dimension - \n \
            You are trying to summ up Vector of dimension " + \
            std::to_string(this->dim) + " with Vector of dimension " + std::to_string(a.dim));

    for(int i = 0; i < dim; ++i)
    {
        this->val[i] = this->val[i] - a.GetAt(i);
    }
    return *this;
}

//==Vector Functions==//
