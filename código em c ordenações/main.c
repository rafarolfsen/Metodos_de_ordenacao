// Rafael Amaro Rolfsen
// Este programa foi feito para fixar o conhecimento em criação de header e métodos de ordenação.

#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"

int *readvector( int* size){    // Função para leitura e alocação de um vetor de int, parametro: tamanho(int)                      

    int aux;                    // inicia variavel inteira auxiliar 
    int* vector = NULL;         // declara o vetor de inteiros iniciado com NULL 
    char c;                     // declara variavel para verificação de condição

    *size = 0;                  // inicia o tamanho em 0

    c = fgetc(stdin);           // lê o primeiro caractere de verificação

    while(c != '\n'){                                                   // enquanto não ler um pulo de linha faz:
        ungetc(c, stdin);                                               // devolve o caractere de verificação
        scanf("%d", &aux);                                              // lê o inteiro
        vector = (int*) realloc (vector, sizeof(int) * (*size+1) );     // aloca o espaço para o inteiro no vetor            
        vector[*size] = aux;                                            // adiciona o inteiro no vetor               
        *size = *size + 1;                                              // aumenta o tamanho
        c = fgetc(stdin);                                               // lê o caractere de verificação 
    }                       

    return vector;              // retorna o vetor alocado e preenchido
}


int main(int argc, char *argv[ ]){

    int* vector = NULL;     // declara o vetor de entrada
    int i, size, option;    // declara variavel auxiliar, variavel para tamanho do vetor lido e opção de ordenação

    printf("Insira os valores inteiros do vetor separados por espaço e sem espaço após o ultimo valor: \n");

    vector = readvector(&size);     // chama função para leitura do vetor via stdin

    printf("o vetor inserido foi: [ ");
    for(i=0; i<size ; i++){                 //apresenta para o usuário o vetor lido
        printf("%d ", vector[i]);
    }
    printf("] \n");

    printf("Digite 1 para bubble-sort ou 2 para quick_sort: \n");

    scanf("%d", &option);   // Le a opção de ordenação

    switch(option){                             // seleciona a função desejada do ordenacao.h
        case 1:
            vector = bubble_sort(vector, size);
        break;

        case 2:
            quick_sort(vector, 0, size-1);
        break;

        default:
            printf("Nenhuma ordenação escolhida.");
            return 0;
    }


    printf("o vetor ordenado é: [ ");
    for(i=0; i<size ; i++){                 //apresenta para o usuário o vetor lido
        printf("%d ", vector[i]);
    }
    printf("] \n");

    free(vector);
    
    return 0;
}
