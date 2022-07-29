#include "main.hpp"
#include "libs/generic_matrix.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

//TODO Arrumar operação de multiplicação

int main(){
    cout << "Hello World!\n\n";
    srand((unsigned) time(0));
    {
        float el_1[] = {11,12,21,22};
        float el_2[] = {31,32,41,12};

        matrix m1(2, 2, el_1);
        matrix m2(2, 2, el_2);
        matrix m3(2, 2, el_1);

        cout << "m1 " << m1 << "m2 " << m2 << "m3 " << m3 << endl;
        //test_operations(m1, m2);

        m3 = (m1 + 2 + m2)*3*m2.transpose();
        cout << m3 << endl;
    }
    /*{
        #define SIZE 50
            matrix m1(3, 50);
            m1.ramdom_values(10);
            //cout << m1;
            matrix m2(3, 50);
            m2.ramdom_values(10);
            //cout << m2;

            matrix m3;
            m3 = m1*m2;
            //cout << m3;
    }*/
    cout << "\nGoodbye World." << endl;
    return 0;
}

void test_operations(matrix m1, matrix m2){
    matrix m3; 
    m3 = m1;

    {   cout << "m = number\n";
            m3 = 5;
            cout << m3 << endl;
        }
        cout << endl;
        {   cout << "m = matrix\n";
            m3 = m1;
            cout << m3 << endl;
        }
        cout << endl;
        {   cout << "m += number\n";
            m3 += 2;
            cout << m3 << endl;
        }
        cout << endl;
        {   cout << "m += matrix\n";
            m3 += m2;
            cout << m3 << endl;
        }
        cout << endl;
        {   cout << "m -= number\n";
            m3 -= 2;
            cout << m3 << endl;
        }
        cout << endl;
        {   cout << "m -= matrix\n";
            m3 -= m2;
            cout << m3 << endl;
        }
        cout << endl;
        {   cout << "m *= number\n";
            m3 *= 4;
            cout << m3 << endl;
        }
        cout << endl;
        {   cout << "m *= matrix\n";
            m3 *= m1;
            cout << m3 << endl;
        }
        cout << endl;
        {   cout << "m /= number\n";
            m3 /= 4;
            cout << m3 << endl;
        }
        cout << endl;
        {   
            cout << "m = matrix + number\n";
            m3 = m1 + 1;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m = matrix + matrix\n";
            m3 = m1 + m2;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m = matrix - number\n";
            m3 = m1 - 20;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m = matrix - matrix\n";
            m3 = m1 - m2;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m = matrix * number\n";
            m3 = m1 * 3;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m = matrix * matrix\n";
            m3 = m1 * m2;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m = matrix / number\n";
            m3 = m1 / 6;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m == matrix \n";
            bool a = m3 == m1;
            cout << a << endl;
            cout << "m != matrix \n";
            a = m3 != m1;
            cout << a << endl;
        }
        cout << endl;
        {
            cout << "m == matrix \n";
            m3 = m1;
            bool a = m3 == m1;
            cout << a << endl;
            cout << "m != matrix \n";
            a = m3 != m1;
            cout << a << endl;
        }
        /*
        cout << endl;
        {
            cout << "m \n";
            m3 ;
            cout << m3 << endl;
        }
        */
        cout << endl;
        {
            //vscode tá chorando mas o gnu não então...
            cout << "m3 = (m1 + 2 + m2)*3*m2\n";
            
        }
        cout << endl;
}