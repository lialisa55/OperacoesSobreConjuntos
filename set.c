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

bool set_inserir(SET *s, int elemento){
  if(s->tipo == 0){
    return avl_inserir(s->arvore, elemento);
  }else{
    return lista_inserir(s->lista, elemento);
  }
}

bool set_remover(SET *s, int elemento){
  if(s->tipo == 0){
    return avl_remover(s->arvore, elemento);
  }else{
    return lista_remover(s->lista, elemento);
  }
}

void set_apagar(SET **s){
  if((*s)->tipo == 0){
    avl_apagar(&((*s)->arvore));
  }else{
    lista_apagar(&((*s)->lista));
  }
  free(*s);
  *s = NULL;
}

void set_imprimir(SET *s){
  if(s->tipo == 0){
    avl_imprimir(s->arvore);
  }else{
    lista_imprimir(s->lista);
  }
}

SET *set_uniao(SET *A, SET *B){
  SET *uniao = set_criar(A->tipo);
  if(A->tipo == 0){
    NO *raiz = avl_get_raiz(A->arvore);
    while(raiz != NULL){
      set_inserir(uniao, raiz->chave);
      raiz = avl_sucessor(raiz);
    }
    raiz = avl_get_raiz(B->arvore);
    while(raiz != NULL){
      set_inserir(uniao, raiz->chave);
      raiz = avl_sucessor(raiz);
    }
  }else{
    NO *no = lista_get_cabeca(A->lista);
    while(no != NULL){
      set_inserir(uniao, no->chave);
      no = lista_get_proximo(no);
    }
    no = lista_get_cabeca(B->lista);
    while(no != NULL){
      set_inserir(uniao, no->chave);
      no = lista_get_proximo(no);
    }
  }
  return uniao;
}

SET *set_interseccao(SET *A, SET *B){
  SET *interseccao = set_criar(A->tipo);
  if(A->tipo == 0){
    NO *raiz = avl_get_raiz(A->arvore);
    while(raiz != NULL){
      if(avl_pertence(B->arvore, raiz->chave)){
        set_inserir(interseccao, raiz->chave);
      }
      raiz = avl_sucessor(raiz);
    }
  }else{
    NO *no = lista_get_cabeca(A->lista);
    while(no != NULL){
      if(lista_pertence(B->lista, no->chave)){
        set_inserir(interseccao, no->chave);
      }
      no = lista_get_proximo(no);
    }
  }
  return interseccao;
}