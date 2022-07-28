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

        void operator = (float);
        void operator = (matrix);
        void operator += (float);
        void operator += (matrix);
        void operator -= (float);
        void operator -= (matrix);
        void operator *= (float);
        void operator *= (matrix);
        void operator /= (float);

        matrix operator + (float);
        matrix operator + (matrix);
        matrix operator - (float);
        matrix operator - (matrix);
        matrix operator * (float);
        matrix operator * (matrix);
        matrix operator / (float);

        bool operator == (matrix);
        bool operator != (matrix);

    protected:
        float* elements;
        int rows;
        int columns;
        bool is_copy;
    private:
        friend std::ostream& operator << (std::ostream&, matrix&);
};

#endif