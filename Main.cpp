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






