# PLANgebra
                                                                                                   
## A library for C++ that represents interaction with vectors and matrices                                                 

## Usage 
Example:
```
#include <iostream>
#include <algorithm>

#include "PLANgebra.h"

int main()
{
    try
    {
        double array[5] = {4, 123.2, 343, -4.37, 1};

        pla::Vector a(3, {1, 2, 3} ); //Declaration of Vector of dimension 3 with values 1, 2 and 3
        pla::Vector b(3);             //Declaration of null Vector of dimension 3
        pla::Vector c(5, array);      //Declaration of Vector of dimension 5 with values from array
        pla::Vector d(3, array);      //Declaration of Vector of dimension 3
                                      //with 3 first values from array

        a.Print(); b.Print();         //Prints Vector's dimension and values 
        c.Print(); d.Print();
        putchar('\n');        

        b -= a;
        b.Print();                    
        putchar('\n');


        c.Print();

        std::reverse(c.begin(), c.end());
                                      //Values in Vector c are now reversed
        c.Print();
        c.SetNull();                  //All the values are now null
        c.Print();
        putchar('\n');

        c += d * 5;                   //You get an exception here 
                                      //summing up Vectors of different dim
    }
    catch(std::invalid_argument &ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }


    return 0;
}
```
```
g++ Main.cpp PLANgebra.lib
```

<details>
<summary><b> Result: </b> </summary>

```
Vector: dimension 3, value 1 2 3 
Vector: dimension 3, value 0 0 0 
Vector: dimension 5, value 4 123.2 343 -4.37 1 
Vector: dimension 3, value 4 123.2 343 

Vector: dimension 3, value -1 -2 -3 

Vector: dimension 5, value 4 123.2 343 -4.37 1 
Vector: dimension 5, value 1 -4.37 343 123.2 4 
Vector: dimension 5, value 0 0 0 0 0 

Exception: The summed Vector::Vectors must be of the same dimension - 
You are trying to summ up Vector of dimension 5 with Vector of dimension 3
```
</details>

## Installation                                                                                             
Simply place `PLANgebra.lib` and `PLANgebra.h` in your project directory or anywhere you want, put `#include "[way_to_PLANgebra.h]"]` to your project and then you can use it!

