#ifndef MEDALHAS_H_INCLUDED
#define MEDALHAS_H_INCLUDED

typedef struct medalha Medalha;

Medalha* criar_lista(int tamanho);
int sizeof_medalha();
int preencher_lista(Medalha *lista, int *tam);
void imprimir_lista(Medalha *lista, int tam);
void mergeSort(Medalha *lista, int inicio, int fim, int tipo);
void merge(Medalha *lista, int inicio, int meio, int fim, int tipo);

#endif

