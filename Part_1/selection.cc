
// Implementação do algoritmo de ordenação Selection Sort

#include <stdio.h>

int main(void){
  int vet[10000];
  int i, j, aux, min, cont = 0;

  // Leitura do vetor desordenado
  for (i = 0; i < 10000; i++){
    scanf ("%d", &vet[i]);
  }
    
  // Ordenação do vetor
  for(i = 0; i < 9999; i++){
    aux = vet[i];
    cont++;
	  min = i;
	  for (j = i + 1; j < 10000; j++){
	    if (vet[j] < aux){
	      min = j;
  	    aux = vet[j];
        cont++;
      }
    }
	  vet[min] = vet[i];
    cont++;
	  vet[i] = aux;
    cont++;
  }
  
  // Escrita do resultado
  for(i = 0; i < 10000; i++){
	  printf("%d ", vet[i]);
  }
  printf("- %d\n", cont);
}