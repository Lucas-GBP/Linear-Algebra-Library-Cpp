#include "generic_matrix.hpp"

#define DEBUG

matrix::matrix(){
    #ifdef DEBUG
        std::cout << "No arg Constructor Called: " << this << std::endl;
    #endif

    is_copy = false;
    elements = NULL;
}

matrix::matrix(int row, int column):rows(row), columns(column){
    #ifdef DEBUG
        std::cout << "Constructor Called " << this << std::endl;
    #endif

    is_copy = false;
    elements = (float*)malloc(sizeof(float)*rows*columns);
}

matrix::matrix(int row, int column, float *element):rows(row), columns(column){
    #ifdef DEBUG
        std::cout << "Constructor Called: " << this << std::endl;
    #endif

    is_copy = false;
    elements = (float*)malloc(sizeof(float)*rows*columns);
    for(int i = 0; i < rows*columns; i++){
        elements[i] = element[i];
    }
}

matrix::matrix(matrix& m):columns(m.columns), rows(m.rows), elements(m.elements), is_copy(true){
    #ifdef DEBUG
        std::cout << "Copy Constructor Called: " << this << std::endl;
    #endif
}

matrix::~matrix(){
    #ifdef DEBUG
        std::cout << "Destructor Called: " << is_copy << " " << this << std::endl;
    #endif

    if(!is_copy){
        free(elements);
    }
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

void matrix::operator = (matrix m){
    free(elements);
    columns = m.columns;
    rows = m.rows;

    elements = (float*)malloc(sizeof(matrix)*columns*rows);

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
    float* el = (float*)malloc(sizeof(matrix)*columns*rows);
    for(int i = 0; i < rows*columns; i++){
        el[i] = elements[i];
    }
    matrix m1(rows, columns, el);

    return m1;
}

void matrix::operator += (float number){
    if(columns != rows){
        return;
    }
    for(int i = 0; i < columns; i++){
        elements[i*(columns+1)] += number;
    }
}

void matrix::operator += (matrix m){
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

void matrix::operator -= (matrix m){
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

void matrix::operator *= (matrix m){
    if(columns != m.rows){
        return;
    }
    float* el = (float*)malloc(sizeof(float)*rows*m.columns);

    for(int i = 0; i < m.columns; i++){
        for(int j = 0; j < rows; j++){
            el[i+(j*m.columns)] = elements[i*columns] * m.elements[j];
            for(int z = 1; z < columns; z++){
                el[i+(j*m.columns)] += elements[z+(i*columns)] * m.elements[z*m.columns+j];
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
    float* el = (float*)malloc(sizeof(matrix)*columns*rows);

    for(int i = 0; i < rows*columns; i++){
        el[i] = elements[i];
    }
    for(int i = 0; i < columns; i++){
        el[i*(columns+1)] += number;
    }

    matrix m1(rows, columns);
    m1.elements = el;

    return m1;
}

matrix matrix::operator + (matrix m){
    float* el = (float*)malloc(sizeof(float)*rows*columns);
    for(int i = 0; i < columns*rows; i++){
        el[i] = m.elements[i] + elements[i];
    }

    m.elements = el;
    m.is_copy = false;

    return m;
}

matrix matrix::operator - (float number){
    float* el = (float*)malloc(sizeof(matrix)*columns*rows);
    
    for(int i = 0; i < rows*columns; i++){
        el[i] = elements[i];
    }
    for(int i = 0; i < columns; i++){
        el[i*(columns+1)] -= number;
    }

    matrix m1(rows, columns);
    m1.elements = el;

    return m1;
}

matrix matrix::operator - (matrix m){
    float* el = (float*)malloc(sizeof(float)*rows*columns);
    for(int i = 0; i < columns*rows; i++){
        el[i] = m.elements[i] - elements[i];
    }

    m.elements = el;
    m.is_copy = false;

    return m;
}

matrix matrix::operator * (float number){
    float* el = (float*)malloc(sizeof(matrix)*columns*rows);
    for(int i = 0; i < rows*columns; i++){
        el[i] = elements[i]*number;
    }
    matrix m1(rows, columns, el);

    return m1;
}

matrix matrix::operator * (matrix m){
    matrix el(rows, m.columns);

    for(int i = 0; i < el.columns; i++){
        for(int j = 0; j < el.rows; j++){
            el.elements[i+(j*m.columns)] = elements[i*columns] * m.elements[j];
            for(int z = 1; z < columns; z++){
                el.elements[i+(j*m.columns)] += elements[z+(i*columns)] * m.elements[z*m.columns+j];
            }
        }
    }
    return el;
}

matrix matrix::operator / (float number){
    float* el = (float*)malloc(sizeof(matrix)*columns*rows);
    for(int i = 0; i < rows*columns; i++){
        el[i] = elements[i]/number;
    }
    matrix m1(rows, columns, el);

    return m1;
}

bool matrix::operator == (matrix m1){
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

bool matrix::operator != (matrix m1){
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
    for(int i = 0; i < m.columns; i++){
        std::cout << "|";
        for(int j = 0; j < m.rows; j++){
            std::cout << m.elements[j + (m.columns*i)] << "\t";
        }
        std::cout << "|\n";
    }

    return os;
}