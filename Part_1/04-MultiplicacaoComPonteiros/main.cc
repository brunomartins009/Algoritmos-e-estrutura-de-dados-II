
#include <iostream>

using namespace std;

int *p1, *q1, *r, *p2, *q2;

int m1[3][4] = {{ 1, 1, 1, 1},
                { 2, 2, 2, 2},
                { 3, 3, 3, 3}};

int m2[4][5] = {{ 1, 1, 1, 1, 1},
                { 2, 2, 2, 2, 2},
                { 3, 3, 3, 3, 3},
                { 4, 4, 4, 4, 4}};

int m3[3][5];

int main(int argc, char**argv) {
    
    cout << "Multiplicação de Matrizes ..." << endl;

    r = &m3[0][0];
    for (p2 = &m1[0][0]; p2 < &m1[0][0]+12; p2+=4) {
        for (q2 = &m2[0][0]; q2 < &m2[0][0]+5; q2++) {
            *r = 0;
            for (p1 = p2, q1 = q2; p1 < p2 + 4; p1++, q1+=5) {
                *r += *p1 * *q1;
            }
            r++;
        }
    }

    for (r = &m3[0][0]; r < &m3[0][0]+15; r++) {
        cout << *r << " ";
    }
    cout << endl;
    
    return 0;
}
