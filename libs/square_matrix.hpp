#ifndef SQUARE_MATRIX_HPP
#define SQUARE_MATRIX_HPP

#include "generic_matrix.hpp"

class square_matrix: public matrix{
    public:
        square_matrix(int);
        ~square_matrix();
    protected:
        int size;
    private:
        friend std::ostream& operator << (std::ostream&, square_matrix*);
};

#endif