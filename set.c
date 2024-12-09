#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "set.h"
#include "AVL.h"
#include "lista.h"

typedef struct set{
  AVL *arvore;
  LISTA *lista;
  unsigned int tipo;
} SET;

SET *set_criar(unsigned int tipo){
  SET *s = (SET *)malloc(sizeof(SET));
  if(s == NULL) return NULL;
  s->arvore = avl_criar();
  s->lista = lista_criar();
  s->tipo = tipo;
  return s;
}

bool set_pertence(SET *A, int elemento){
  if(A->tipo == 'A'){
    return avl_pertence(A->arvore, elemento);
  }else{
    return lista_pertence(A->lista, elemento);
  }
}

