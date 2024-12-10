#ifndef LISTA_H
	#define LISTA_H
	#define inicial 0
	#define ERRO -32000
	                       
	typedef struct lista_ LISTA;

	LISTA *lista_criar(bool ordenada);
	bool lista_inserir(LISTA *lista, int item);
	int lista_remover(LISTA *lista, int chave);
	bool lista_apagar(LISTA **lista);
	int lista_busca(LISTA *lista, int chave);
	int lista_tamanho(LISTA *lista);
	bool lista_vazia(LISTA *lista);
	bool lista_cheia(LISTA *lista);
	void lista_imprimir(LISTA *lista);
	bool lista_pertence(LISTA *lista, int chave);

#endif
