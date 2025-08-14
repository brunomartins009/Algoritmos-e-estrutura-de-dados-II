#include <stdio.h>
#include <stdlib.h>

typedef struct no_ {
    int chave; //ordem (posicao) no vetor/criterio de busca
    int valor; //valor util do vetor/exemplo, nome, endereco...

    struct no_ * prox;
} no;

no * ptlista;  //vetor principal

no * inicia_lista() {    //inicia a lista vazia
    no* tmp = malloc(sizeof(no)); //aloca o vetor cabeça(vazio)
    tmp->chave = 0;  //inicia a cabeça
    tmp->valor = 0;
    tmp->prox = NULL;  //sem proximo elemento na lista(final)

    return tmp;  //retorna o vetor cabeça criado
}

void encerra_lista(){    //desaloca o espaço alocado anteriormente
    no * ant = ptlista->prox;  //criou um nó "ant" que começa apos o cabeça
    no * pont = ant->prox;  //pont vira o prox na primeira posicao

    while(pont != NULL){ //enquanto o pont nao for NULL
        free(ant);  //exclui o anterior
        ant = pont; //anterior recebe o pont (avança)
        pont = pont->prox; //pont recebe o proximo (avança)
    }
    free(ant);  //apaga o ultimo que está faltando

    free(ptlista);  //apaga o nó cabeça
}

//ponteiros de ponteiros para serem utilizados dentro da inserção e remoção
void busca_enc(int chave, no ** ant, no ** pont){      //realiza busca dos parametros passados na lista encadeada
    *ant = ptlista; //cria um ponteiro com o endereço do cabeça
    *pont = NULL;  

    no*ptr = ptlista->prox;  //cria um nó começando no prox do cabeça
    while (ptr!=NULL){  //enquanto não acabarem as posições
        if (ptr->chave < chave){
            *ant = ptr;   //ant avança para a posição de ptr
            ptr = ptr->prox;     //ptr avança para a posição apontada por ptr->prox
        } else{
            if (ptr->chave == chave){
                *pont = ptr;  //retorna o endereço do nó, caso encontrado
			}
            ptr = NULL;  //para a repetição, nó não encontrado
        }
    }
}

int insere_enc(int chave, int valor){    //insere chave e valor passados por parametro na lista encadeada de forma ordenada e sem repetição
    int retorno = -1;  //retorna -1 caso não seja possível inserir
    no* ant; //cria os parametros(endereço passado) para buscar se o nó ja existe
    no* pont;

    busca_enc(chave, &ant, &pont); //chave foi passado por parametro
    //caso o nó ja exista, não entra no proximo if e retorna -1
    if(pont==NULL){
        no * ptr = malloc(sizeof(no)); //cria o nó que vai ser inserido
        ptr->chave = chave; //nó criado recebe os valores desejados
        ptr->valor = valor; //nó criado recebe os valores desejados
        ptr->prox = ant->prox;  //novo nó recebe o local apontado pelo nó anterior
        ant->prox = ptr;  //o antigo nó agora aponta para o novo nó
        retorno = 0; //retorna 0 indicando sucesso
    }

    return retorno;  //0 sucesso / -1 falha
}


no * remove_enc(int chave){     //remove chave passada por parametro
    no* ant; //cria os parametros(endereço passado) para buscar se o nó ja existe
    no* pont;

    busca_enc(chave, &ant, &pont);
    if(pont!=NULL) //nó foi encontrado
    {
        ant->prox = pont->prox; // o prox anterior assume o valor prox do nó a ser excluido
        return pont; //retorna o nó a ser excluído como foi pedido
    }
    return NULL; //nó não foi encontrado
}


void imprime(){    //imprime a lista encadeada
    no * ptr = ptlista->prox; //cria nó local para percorrer o vetor
    while(ptr != NULL){ //enqunato não chegar no final do vetor
        printf("(chave,valor): (%d,%d)\n",ptr->chave, ptr->valor);
        printf("------------------------\n");

        ptr = ptr->prox; //avança
    }
}

int main(void) {
    ptlista = inicia_lista(); //função para criar o nó

    printf("valor retornado: %d\n", insere_enc(4,5));
    printf("valor retornado: %d\n", insere_enc(3,14));
    printf("valor retornado: %d\n", insere_enc(2,11));
    //printf("valor retornado: %p\n", remove_enc(3)); //nó retornado "excluido"
    free(remove_enc(3)); //como excluir da forma "segura"
    imprime();

    encerra_lista(ptlista);
    return (EXIT_SUCCESS);
}