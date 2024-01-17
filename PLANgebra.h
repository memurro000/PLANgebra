#include <cstddef>
#include <iostream>
namespace pla
{
    typedef double f64;

    class Vector
    {
        private:
            int *dim;
            f64 *val;

        public:

            typedef f64 T;
            struct iterator
            {
                using iterator_category = std::random_access_iterator_tag;
                using difference_type   = std::ptrdiff_t;
                using value_type        = T;
                using pointer           = T*;  // or also value_type*
                using reference         = T&;  // or also value_type& 
             
                explicit iterator(pointer ptr) : m_ptr(ptr) {}
                reference operator*() const { return *m_ptr; }
                pointer operator->() const { return m_ptr; }
             
                // Prefix increment
                iterator& operator++() { ++m_ptr; return *this; }  
             
                // Postfix increment
                iterator operator++(int) { iterator tmp = *this; ++m_ptr; return tmp; }
             
                // Prefix decrement
                iterator& operator--() { --m_ptr; return *this; }  
             
                // Postfix decrement
                iterator operator--(int) { iterator tmp = *this; --m_ptr; return tmp; }
             
                friend bool operator== (const iterator& a, const iterator& b) { return a.m_ptr == b.m_ptr; };
                friend bool operator!= (const iterator& a, const iterator& b) { return a.m_ptr != b.m_ptr; };
                friend size_t operator- (const iterator& a, const iterator& b) { return a.m_ptr - b.m_ptr; };
                friend bool operator< (const iterator& a, const iterator& b) { return a.m_ptr < b.m_ptr; };
                friend bool operator<= (const iterator& a, const iterator& b) { return a.m_ptr <= b.m_ptr; };
                friend bool operator> (const iterator& a, const iterator& b) { return a.m_ptr > b.m_ptr; };
                friend bool operator>= (const iterator& a, const iterator& b) { return a.m_ptr >= b.m_ptr; };
             
                private:
                    pointer m_ptr;
            };
            
            iterator begin() const noexcept { return iterator(this->val); }
            iterator end() const noexcept { return iterator(this->val + *(this->dim)); }


            //Null constructor
            Vector(int dim);

            //Value constructor
            Vector(int dim, f64 value);

            //Initializer list constructor
            Vector(int dim, std::initializer_list<f64> value);

            //Array constructor
            Vector(int dim, f64 *value);

            //Destructor
            ~Vector();

            //Prints dimension and values in console
            void Print();

            //Gets dimension
            int GetDim() const;

            //Sets value at index
            void SetAt(int index, f64 value);

            //Gets value at index
            f64 GetAt(int index) const;

            //Finds the length of Vector
            f64 Length() const;

            //Sets whole vector to null value
            void SetNull();

            Vector operator=(const Vector &in);

            Vector operator*(const f64 a);

            Vector &operator*=(const f64 a);

            Vector operator/(const f64 a);

            Vector &operator/=(const f64 a);

            Vector operator+(const Vector &a);

            Vector &operator+=(const Vector &a);

            Vector operator-(const Vector &a);

            Vector &operator-=(const Vector &a);

    };
	    
    //Finds scalar product of two Vectors
    f64 ScalarProduct(const Vector &a, const Vector &b);

    //Finds Cos of Angle between two Vectors
    f64 AngleCos(const Vector &a, const Vector &b);

}







