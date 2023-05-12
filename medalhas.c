#include <stdio.h>
#include <stdlib.h>

#include "medalhas.h"

struct medalha{
	char nome[100];
	int ouro, prata, bronze;
};

Medalha* criar_lista(int tamanho){
	return (Medalha*) malloc(sizeof(Medalha) * tamanho);
}

int sizeof_medalha(){
	return sizeof(Medalha);
}

int preencher_lista(Medalha *lista, int *tam){
	printf("Nome do Time (0 para encerrar): ");
	scanf("%[^\n]s", lista[*tam].nome);
	
	if(lista[*tam].nome[0] == '0')
		return 0;
	
	printf("Medalhas de ouro, prata e bronze (nessa ordem): ");
	scanf("%d %d %d", &lista[*tam].ouro, &lista[*tam].prata, &lista[*tam].bronze);
	getchar();
	*tam = *tam + 1;
	return 1;
}

void imprimir_lista(Medalha *lista, int tam){
	int i;
	
	printf("\n%-20s%-10s%-10s%-10s\n", "NOME DO TIME", "OURO", "PRATA", "BRONZE");
	
	for(i = 0; i < tam; i++)
		printf("%-20s%-10d%-10d%-10d\n", lista[i].nome, lista[i].ouro, lista[i].prata, lista[i].bronze);
}

void merge(Medalha *lista, int inicio, int meio, int fim, int tipo){
    int i, j, k;
    Medalha *aux = (Medalha*) malloc((fim - inicio) * sizeof(Medalha));
    
    i = inicio;
    j = meio;
    k = 0;

    while (i < meio && j < fim){
    	switch(tipo){
    		case 1:
    			if (lista[i].ouro >= lista[j].ouro){
		            aux[k] = lista[i];
		            i++;
		        } else {
		            aux[k] = lista[j];
		            j++;
		        }
		        
    			break;
    		case 2:
    			if (lista[i].prata >= lista[j].prata){
		            aux[k] = lista[i];
		            i++;
		        } else {
		            aux[k] = lista[j];
		            j++;
		        }
		        
    			break;
    		case 3:
    			if (lista[i].bronze >= lista[j].bronze){
		            aux[k] = lista[i];
		            i++;
		        } else {
		            aux[k] = lista[j];
		            j++;
		        }
		        
    			break;
    		case 4:
    			if (strcmp(lista[i].nome, lista[j].nome) <= 0){
		            aux[k] = lista[i];
		            i++;
		        } else {
		            aux[k] = lista[j];
		            j++;
		        }
		}

        k++;
    }

    while (i < meio){
        aux[k] = lista[i];
        i++;
        k++;
    }

    while (j < fim){
        aux[k] = lista[j];
        j++;
        k++;
    }

    for (i = inicio; i < fim; i++)
        lista[i] = aux[i - inicio];

    free(aux);
}

void mergeSort(Medalha *lista, int inicio, int fim, int tipo){
    if (fim - inicio > 1) {
        int meio = (inicio + fim) / 2;
        mergeSort(lista, inicio, meio, tipo);
        mergeSort(lista, meio, fim, tipo);
        merge(lista, inicio, meio, fim, tipo);
    }
}

