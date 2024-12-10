#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

typedef struct no{
  int chave;
  struct no *prox;
} NO;

typedef struct lista{
  NO *raiz;
  int profundidade;
  int capacidadde;
} LISTA;

LISTA *lista_criar(){
  LISTA *lis = (LISTA *)malloc(sizeof(LISTA));
  if(lis == NULL) return NULL;
  lis->raiz = NULL;
  lis->profundidade = -1;
  return lis;
}