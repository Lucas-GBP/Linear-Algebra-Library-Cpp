#ifndef GENERIC_MATRIX_HPP
#define GENERIC_MATRIX_HPP

#include <cstddef>
#include <iostream>
#include <stdlib.h>

class matrix{
    public:
        matrix();
        matrix(int, int);
        matrix(int, int, float*);
        matrix(matrix&);
        ~matrix();

        float element(int, int);
        float element(int);
        matrix copy();
        matrix transpose();
        void ramdom_values(int);

        void operator = (float);
        void operator = (const matrix&);
        void operator += (float);
        void operator += (const matrix&);
        void operator -= (float);
        void operator -= (const matrix&);
        void operator *= (float);
        void operator *= (const matrix&);
        void operator /= (float);

        matrix operator + (float);
        matrix operator + (const matrix&);
        matrix operator - (float);
        matrix operator - (const matrix&);
        matrix operator * (float);
        matrix operator * (const matrix&);
        matrix operator / (float);

        bool operator == (const matrix&);
        bool operator != (const matrix&);

    protected:
        float* elements;
        int rows;
        int columns;
        //bool is_copy;
    private:
        friend std::ostream& operator << (std::ostream&, matrix&);
};

#endif