#include <stdio.h>
#include <iostream>

using namespace std;

int a[] = {50, 51, 52, 53, 54, 55, 56, 57, 58, 59};
int b[] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69};
int c[10];

int *p, *q, *r;

int main(int argc, char**agrv) {
    cout << "Aritmetica de Ponteiros e Vetores" << endl;

    cout << " c[i] ->  ";
    for (int i = 0; i < 10; i++){
        c[i] = a[i] + b[i];
        cout << " " << c[i];
        
    }
    cout << endl << " *(c+i) ->";
    for (int i = 0; i < 10; i++){
        *(c + i) = *(a + i) + *(b + i);
        cout << " " << *(c + i);
    }
    cout << endl << " *r ->    ";
    for(p = a, q = b, r = c; p < a + 10; p++, q++, r++){
        *r = *p + *q;
        cout << " " << *r;
    }
    cout << endl;
    return 0;  
}