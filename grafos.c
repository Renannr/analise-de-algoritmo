//Trabalho de Analise de algoritmos Função de busca em grafos (busca em largura)

#include <stdio.h>
#include <stdlib.h>

#define TAM 100

int cont=0;

typedef struct no {
  int valor;
  struct no *prox[TAM];
} no;

no *vertice[TAM];

void inicia_vertice() {
  for(int i=0; i< TAM; i++) {
    vertice[i] = NULL;
  }
}

void cria_vertice(int valor) {
  no *aux;

  aux = malloc(sizeof(no));

  aux->valor    = valor;
  aux->prox[0]  = NULL;
  vertice[cont] = aux;

  cont++;

  printf("Vertice criado [%d]\n", valor);
}


void insere_elemento(int origem, int destino) {
  int i=0, j=0, k=0, y=0;
  no *aux;

  while(i < cont && vertice[i]->valor != origem)
    i++;

  if(i == cont)
    cria_vertice(origem);

  while(j < cont && vertice[j]->valor != destino)
    j++;

  if(j == cont)
    cria_vertice(destino);

  if(cont > 0) {
    aux = vertice[i];
    while(aux->prox[k] != NULL)
      k++;

    aux->prox[k] = vertice[j];
    vertice[i] =  aux;

    aux = vertice[j];
    while(aux->prox[y] != NULL)
      y++;

    aux->prox[y] = vertice[i];
    vertice[j] =  aux;
  }

  printf("Inserido ligacao [%d]->[%d]\n\n", origem, destino);
}

void imprime() {
  int j=0;
  no *aux;
  printf("Imprimindo vertices e suas ligacoes...\n");
  for(int i=0; i<cont && vertice[i] != NULL; i++) {
    printf("\nvertice[%d] valor: %d ",i+1, vertice[i]->valor);
    aux = vertice[i];
    printf("\n\t proximos ");
    while(aux->prox[j] != NULL){
      printf("->[%d]", aux->prox[j]->valor);
      j++;
    }
    j=0;
    printf("\n");
  }
  printf("\n\n");
}


int busca(no *grafo, int fila[TAM]) {
  // Faz uma busca em largura no grafo passado

  return 0;
}

int main(int argc, char const *argv[]) {

  inicia_vertice();
  printf("\n");
  insere_elemento(1, 10);
  insere_elemento(1, 101);
  insere_elemento(1, 102);

  printf("\n");
  imprime();

  return 0;
}