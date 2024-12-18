#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AVL.h"

typedef struct no{
  int chave;
  struct no *esq, *dir;
  int FB;
} NO;

struct avl{
  NO *raiz;
  int profundidade;
};

AVL *avl_criar(){
  AVL *arvore = (AVL *)malloc(sizeof(AVL));
  if(arvore == NULL) return NULL;
  arvore->raiz = NULL;
  arvore->profundidade = -1;
  return arvore;
}

void avl_apagar_aux(NO *raiz){
  if(raiz != NULL){
    avl_apagar_aux(raiz->esq);
    avl_apagar_aux(raiz->dir);
    free(raiz);
  }
}

void avl_apagar(AVL **arvore){
  avl_apagar_aux((*arvore)->raiz);
  free(*arvore);
  *arvore = NULL;
}

int avl_altura(NO *raiz){
  if(raiz == NULL) return -1;
  int altura_esq = avl_altura(raiz->esq);
  int altura_dir = avl_altura(raiz->dir);
  return 1 + ((altura_esq > altura_dir) ? altura_esq : altura_dir);
}

int *avl_cria_no(int chave){
  int *novo = (int *)malloc(sizeof(int));
  if(novo == NULL) return NULL;
  *novo = chave;
  return novo;
}

NO *rodar_direita(NO *raiz){
  NO *aux = raiz->esq;
  raiz->esq = aux->dir;
  aux->dir = raiz;
  return aux;
}

NO *rodar_esquerda(NO *raiz){
  NO *aux = raiz->dir;
  raiz->dir = aux->esq;
  aux->esq = raiz;
  return aux;
}

NO *rodar_dupla_direita(NO *raiz){
  raiz->esq = rodar_esquerda(raiz->esq);
  return rodar_direita(raiz);
}

NO *rodar_dupla_esquerda(NO *raiz){
  raiz->dir = rodar_direita(raiz->dir);
  return rodar_esquerda(raiz);
}

NO *insere(NO *raiz, int chave, bool *h){
  if(raiz == NULL){
    raiz = (NO *)malloc(sizeof(NO));
    if(raiz == NULL) return NULL;
    raiz->chave = chave;
    raiz->esq = raiz->dir = NULL;
    raiz->FB = 0;
    *h = true;
  }else if(chave < raiz->chave){
    raiz->esq = insere(raiz->esq, chave, h);
    if(*h){
      switch(raiz->FB){
        case 1:
          raiz->FB = 0;
          *h = false;
          break;
        case 0:
          raiz->FB = -1;
          break;
        case -1:
          if(raiz->esq->FB == -1){
            raiz = rodar_direita(raiz);
            raiz->FB = 0;
            raiz->dir->FB = 0;
          }else{
            raiz = rodar_dupla_direita(raiz);
            raiz->FB = 0;
          }
          *h = false;
          break;
      }
    }
  }else if(chave > raiz->chave){
    raiz->dir = insere(raiz->dir, chave, h);
    if(*h){
      switch(raiz->FB){
        case -1:
          raiz->FB = 0;
          *h = false;
          break;
        case 0:
          raiz->FB = 1;
          break;
        case 1:
          if(raiz->dir->FB == 1){
            raiz = rodar_esquerda(raiz);
            raiz->FB = 0;
            raiz->esq->FB = 0;
          }else{
            raiz = rodar_dupla_esquerda(raiz);
            raiz->FB = 0;
          }
          *h = false;
          break;
      }
    }
  }
  return raiz;
}