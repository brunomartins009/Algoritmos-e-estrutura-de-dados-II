#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
    int v[10];
    int i, j, aux, cont;

    // Leitura do vetor desordenado
    for (i = 0; i < 10; i++){
        scanf("%d", &v[i]);
    }
    cont = 0;
  
    // Ordenação do vetor
    for (i = 9; i > 0; i--){
        for (j = 0; j < i; j++){
    	    if(v[j] > v[j+1]){
	            aux = v[j];
                cont++;
                v[j] = v[j+1];
                cont++;
	            v[j+1] = aux;
                cont++;
            }
        }
    }
  
    // Escrita do resultado
    for (i = 0; i < 10; i++){
	   cout << "  " << v[i];
    }
    cout << endl;
}