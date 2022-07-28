#include "main.hpp"

using namespace std;

int main(){
    {
    cout << "Hello World!\n\n";
    float el_1[] = {11,12,21,22};
    matrix m1(2, 2, el_1);

    float el_2[] = {31,32,41,12};
    matrix m2(2, 2, el_2);

    matrix m3(2, 2, el_1);
        cout << m1 << m2 << m3 << endl;
    
    {   // Teste de todas as operações 
        {
            cout << "m = number\n";
            m3 = 5;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m = matrix\n";
            m3 = m1;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m += number\n";
            m3 += 2;
            cout << m3 << endl;
        }
        {
            cout << "m += matrix\n";
            m3 += m2;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m -= number\n";
            m3 -= 2;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m -= matrix\n";
            m3 -= m2;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m *= number\n";
            m3 *= 4;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m *= matrix\n";
            m3 *= m1;
            cout << m3 << endl;
        }
        cout << endl;
        {
            cout << "m /= number\n";
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
            m3 = (m1 + 2 + m2)*3*m2;
            cout << m3 << endl;
        }
        cout << endl;
    }
    
    cout << endl;



    }
    cout << "\nGoodbye World." << endl;
    return 0;
}