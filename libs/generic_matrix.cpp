#include "generic_matrix.hpp"

//#define DEBUG

matrix::matrix(){
    #ifdef DEBUG
        std::cout << "No arg Constructor Called: " << this << std::endl;
    #endif

    elements = NULL;
}

matrix::matrix(int row, int column):rows(row), columns(column){
    #ifdef DEBUG
        std::cout << "Constructor Called " << this << std::endl;
    #endif

    elements = (float*)malloc(sizeof(float)*(rows*columns));
}

matrix::matrix(int row, int column, float *element):rows(row), columns(column){
    #ifdef DEBUG
        std::cout << "Constructor Called: " << this << std::endl;
    #endif

    elements = (float*)malloc(sizeof(float)*rows*columns);
    for(int i = 0; i < rows*columns; i++){
        elements[i] = element[i];
    }
}

matrix::matrix(matrix& m):columns(m.columns), rows(m.rows), elements(m.elements){
    #ifdef DEBUG
        std::cout << "Copy Constructor Called: " << this << std::endl;
    #endif
    elements = (float*)malloc(sizeof(matrix)*columns*rows);
    for(int i = 0; i < rows*columns; i++){
        elements[i] = m.elements[i];
    }
}

matrix::~matrix(){
    #ifdef DEBUG
        std::cout << "Destructor Called: " << this << std::endl;
    #endif

    free(elements);

    /*if(!is_copy){
        free(elements);
    }*/
}

void matrix::operator = (float num){
    if(rows == columns){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(i == j){
                    elements[j+(i*columns)] = num;
                } else {
                    elements[j+(i*columns)] = 0;
                }
            }
        }
    } else {
        for(int i = 0; i < rows*columns; i++){
            elements[i] = num;
        }
    }
}

void matrix::operator = (const matrix& m){
    free(elements);
    columns = m.columns;
    rows = m.rows;

    elements = (float*)malloc(sizeof(matrix)*(rows*columns));

    for(int i = 0; i < columns*rows; i++){
        elements[i] = m.elements[i];
    }
}

float matrix::element(int row, int column){
    return elements[column + (columns*row)];
}

float matrix::element(int index){
    return elements[index];
}

matrix matrix::copy(){
    matrix m1(rows, columns);
    m1.elements = (float*)malloc(sizeof(matrix)*columns*rows);
    for(int i = 0; i < rows*columns; i++){
        m1.elements[i] = elements[i];
    }


    return m1;
}

matrix matrix::transpose(){
    matrix return_m(columns, rows);

    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){
            return_m.elements[i+(j*columns)] = elements[j+(i*columns)];
        }
    }

    return return_m;
}

void matrix::ramdom_values(int range){
    for(int i = 0; i < rows*columns; i++){
        elements[i] = (rand()%(2*range))-range;
    }
}

void matrix::operator += (float number){
    if(columns != rows){
        return;
    }
    for(int i = 0; i < columns; i++){
        elements[i*(columns+1)] += number;
    }
}

void matrix::operator += (const matrix& m){
    if(m.columns != columns || m.rows != rows){
        return;
    }
    for(int i = 0; i < rows*columns; i++){
        elements[i] += m.elements[i];
    }
}

void matrix::operator -= (float number){
    if(columns != rows){
        return;
    }
    for(int i = 0; i < columns; i++){
        elements[i*(columns+1)] += number;
    }
}

void matrix::operator -= (const matrix& m){
    if(m.columns != columns || m.rows != rows){
        return;
    }
    for(int i = 0; i < rows*columns; i++){
        elements[i] -= m.elements[i];
    }
}

void matrix::operator *= (float number){
    for(int i = 0; i < columns*rows; i++){
        elements[i] *= number;
    }
}

void matrix::operator *= (const matrix& m){
    if(columns != m.rows){
        return;
    }
    float* el = (float*)malloc(sizeof(float)*rows*m.columns);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < m.columns; j++){
            el[j+(i*m.columns)] = elements[i*columns] * m.elements[j];
            for(int z = 1; z < columns; z++){
                el[j+(i*m.columns)] += elements[z+(i*columns)] * m.elements[z*m.columns+j];
            }
        }
    }

    columns = m.columns;
    free(elements);
    elements = el;
}

void matrix::operator /= (float number){
    for(int i = 0; i < columns*rows; i++){
        elements[i] /= number;
    }
}

matrix matrix::operator + (float number){
    if(columns != rows){
        return *this;
    }
    matrix m1(rows, columns);

    for(int i = 0; i < rows*columns; i++){
         m1.elements[i] = elements[i];
    }
    for(int i = 0; i < columns; i++){
         m1.elements[i*(columns+1)] += number;
    }

    return m1;
}

matrix matrix::operator + (const matrix& m){
    if(m.columns != columns || m.rows != rows){
        std::cout << "Error in operator +" << std::endl;
        return *this;
    }
    matrix m_return(rows, columns);
    for(int i = 0; i < columns*rows; i++){
        m_return.elements[i] = m.elements[i] + elements[i];
    }

    return m_return;
}

matrix matrix::operator - (float number){
    if(columns != rows){
        return *this;
    }
    matrix m1(rows, columns);

    for(int i = 0; i < rows*columns; i++){
        m1.elements[i] = elements[i];
    }
    for(int i = 0; i < columns; i++){
        m1.elements[i*(columns+1)] -= number;
    }

    return m1;
}

matrix matrix::operator - (const matrix& m){
    if(m.columns != columns || m.rows != rows){
        std::cout << "Error in operator -" << std::endl;
        return *this;
    }
    matrix m_return(rows, columns);
    for(int i = 0; i < columns*rows; i++){
        m_return.elements[i] = m.elements[i] - elements[i];
    }

    return m_return;
}

matrix matrix::operator * (float number){
    matrix m1(rows, columns);
    for(int i = 0; i < rows*columns; i++){
        m1.elements[i] = elements[i]*number;
    }

    return m1;
}

matrix matrix::operator * (const matrix& m){
    if(columns != m.rows){
        std::cout << "Error in operator *" << std::endl;
        return *this;
    }

    matrix el(rows, m.columns);

    for(int i = 0; i < el.rows; i++){
        for(int j = 0; j < el.columns; j++){
            el.elements[j+(i*m.columns)] = elements[i*columns] * m.elements[j];
            for(int z = 1; z < columns; z++){
                el.elements[j+(i*m.columns)] += elements[z+(i*columns)] * m.elements[z*m.columns+j];
            }
        }
    }

    return el;
}

matrix matrix::operator / (float number){
    matrix m1(rows, columns);
    for(int i = 0; i < rows*columns; i++){
        m1.elements[i] = elements[i]/number;
    }

    return m1;
}

bool matrix::operator == (const matrix& m1){
    if(m1.rows != rows || m1.columns != columns){
        return false;
    }
    for(int i = 0; i < columns*rows; i++){
        if(m1.elements[i] != elements[i]){
            return false;
        }
    }
    return true;
}

bool matrix::operator != (const matrix& m1){
    if(m1.rows != rows || m1.columns != columns){
        return true;
    }
    for(int i = 0; i < columns*rows; i++){
        if(m1.elements[i] != elements[i]){
            return true;
        }
    }
    return false;
}

std::ostream& operator << (std::ostream& os, matrix& m){
    std::cout << m.rows << "x" << m.columns << std::endl;
    for(int i = 0; i < m.rows; i++){
        std::cout << "|";
        for(int j = 0; j < m.columns; j++){
            std::cout << m.elements[j + (m.columns*i)] << "\t";
        }
        std::cout << "|\n";
    }

    return os;
}