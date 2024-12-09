#define max(a, b) ((a > b) ? a : b)

typedef struct no NO;
typedef struct avl AVL;

AVL *avl_criar();
void avl_apagar(AVL **arvore);
int avl_altura(NO *raiz);
int *avl_cria_no(int chave);
NO *rodar_direita(NO *raiz);
NO *rodar_esquerda(NO *raiz);
NO *rodar_dupla_direita(NO *raiz);
NO *rodar_dupla_esquerda(NO *raiz);