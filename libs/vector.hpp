#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "generic_matrix.hpp"

class vector: public matrix{
    public:
        vector(int);
        ~vector();
    protected:
        int size;
    private:
        friend std::ostream& operator << (std::ostream&, vector*);
};

#endif