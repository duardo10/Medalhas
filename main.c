#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "medalhas.h"

int main(){
	/*
		Grupo:
		- BRUNA HELOISA FEITOSA VELOSO
		- LINDAIELY RODRIGUES DE SOUSA
		- LUIS EDUARDO SILVA BRITO
		- VICTOR MACEDO CARVALHO
		- VILMACIO DE MOURA DA SILVA
		- ROBSON DE MOURA SANTOS JUNIOR
		- SHEILA PALOMA DE SOUSA BRITO
	*/

	Medalha *lista;
    int TAM = 0;
    
	lista = criar_lista(1);
    
    while(preencher_lista(lista, &TAM)){
    	lista = (Medalha*) realloc(lista, sizeof_medalha() * (TAM + 1));
	}
    
    mergeSort(lista, 0, TAM, 4);
    mergeSort(lista, 0, TAM, 3);
    mergeSort(lista, 0, TAM, 2);
    mergeSort(lista, 0, TAM, 1);
    imprimir_lista(lista, TAM);
    printf("\nTamanho da lista: %d\n", TAM);
    
    return 0;
}

