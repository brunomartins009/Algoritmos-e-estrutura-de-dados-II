
// Implementação do algoritmo de ordenação Insertion Sort

#include <stdio.h>

int main (void){
  int vet[10000];
  int i, j, aux, cont = 0;

  // Leitura do vetor desordenado
  for(i = 0; i < 10000; i++){
    scanf ("%d", &vet[i]);
  }
  
  // Ordenação do vetor
  for(i = 1; i < 10000; i++){
    aux = vet[i];
    cont++;
    for(j = i - 1; j >= 0 && vet[j] > aux; j--){
	  vet[j+1] = vet[j];
      cont++;
    }
	vet[j+1] = aux;
    cont++;
  }
  
  // Escrita do resultado
  for(i = 0; i < 10000; i++){
	printf("%d ", vet[i]);
  }
  printf("- %d\n", cont);
}