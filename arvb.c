#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"
#include "fila.h"
#include "lista.h"

typedef struct arv{
	int info;
	ArvB *esq;
	ArvB *dir;
}ArvB;

typedef struct fila{
	Lista *ini;
	Lista *fim;
}Fila;

typedef struct lista {
	int info;
	Lista *prox;
}Lista;

ArvB* arvb_cria_vazia(void){
	return NULL;
}

int arvb_vazia(ArvB *a){
	return a == NULL;
}

ArvB* arvb_busca(ArvB *a, int c){
	if(arvb_vazia(a))
		return NULL;
	else if(a->info < c)
		return arvb_busca(a->dir,c);
	else if(a->info > c)
		return arvb_busca(a->esq,c);
	else //(a->info == c)
		return a;
}

void arvb_imprime(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		printf("%d ",a->info);
		arvb_imprime(a->dir);
	}
}

ArvB* arvb_insere(ArvB *a, int c){
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = c;
		a->esq = NULL;
		a->dir = NULL;
	}
	else if(a->info > c)
		a->esq = arvb_insere(a->esq,c);
	else if (a->info < c)
		a->dir = arvb_insere(a->dir,c);
	else
		printf("\nElemento Ja Pertence a Arvore");
	return a;
}

ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c)
			a->esq = arvb_remove(a->esq,c);
		else if (a->info < c)
			a->dir = arvb_remove(a->dir,c);
		else{
			ArvB* t;
			if (a->esq == NULL){
			t = a; a = a->dir;
			free(t);
			}
			else if (a->dir == NULL){
				t = a; a = a->esq;
				free(t);
			}
			else{
				t = a->esq;
				while(t->dir!=NULL)
				t = t->dir;
				a->info = t->info; t->info = c;
				a->esq = arvb_remove(a->esq,c);
			}
		}
	}
	return a;
}

void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
}

//Função que retorna a altura de uma Árvore.
int arvb_altura(ArvB *a){
	if(arvb_vazia(a))
		return -1;
	else{
		int hSAE = arvb_altura(a->esq);
		int hSAD = arvb_altura(a->dir);
		if(hSAE > hSAD)
			return 1+hSAE;
		else
			return 1+hSAD;
	}
}

int folhas_div_n(ArvB* a, int n){
	if(arvb_vazia(a)){
		return 0;
	}
	else{
		int contador = 0;
		contador = folhas_div_n(a->dir, n);
		if(a->dir == NULL && a->esq == NULL){
			if(a->info % n == 0){
				return 1;
			}
		}
		contador = contador + folhas_div_n(a->esq, n);
		return contador;
	}
}

int isdegenerada(ArvB* a){
	if(!arvb_vazia(a)){
		if(num_nos(a) == (arvb_altura(a) + 1)){//Em uma árvore degenerada o número de nós é igual a sua altura mais (+) um (1)
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}

int nos_fb_n(ArvB* a, int n){
	int quant = 0;
	if(arvb_vazia(a)){
		return quant;
	}
	int fb = arvb_altura(a->dir) - arvb_altura(a->esq);
	if(fb == n){
		quant++;
	}
	quant = quant + nos_fb_n(a->esq, n) + nos_fb_n(a->dir, n);
	return quant;
}

//Função que preenche uma fila com elementos de uma árvore.
void preenche_fila(ArvB* a, Fila* f){
	if(!arvb_vazia(a)){
		preenche_fila(a->esq,f);
		fila_insere(f,a->info);
		preenche_fila(a->dir,f);
 	}
}

void impressao_arv_elem_comuns(ArvB* a, ArvB* b){
	Fila* f1 = fila_cria();
	Fila* f2 = fila_cria();
	
	preenche_fila(a,f1);
	preenche_fila(b,f2);
	
	Lista* l1 = lst_cria();
	Lista* l2 = lst_cria();
	Lista* l = lst_cria();
	Lista* lAux = lst_cria();
	Lista* lCont = lst_cria();
	
	l1 = f1->ini;
	l2 = f2->ini;
	
	lAux = l1;
	while(lAux != NULL){
		lCont = l2;
		while(lCont != NULL){
			if(lAux->info == lCont->info){
				l = lst_insere(l,lAux->info);
			}
			lCont = lCont->prox;
		}
		lAux = lAux->prox;
	}
	lst_imprime(l);
}

//Função que retorna o número de nós de uma árvore.
int num_nos(ArvB* a){
	int contador = 0;
	if(!arvb_vazia(a)){
		contador = contador + num_nos(a->esq);
		contador = contador + num_nos(a->dir);
	}
	else{
		return 0;
	}
	contador++;
	return contador;
}

//Função que auxilia a função que imprime os elementos em seus respectivos níveis.
void aux_impressao_arv_niveis(ArvB *a, int nivel){
	if(arvb_vazia(a)){
		return;
	}
	if(nivel == 1){
		printf(" %d ", a->info);
	}
	else if(nivel > 1){
		aux_impressao_arv_niveis(a->esq, nivel-1);
		aux_impressao_arv_niveis(a->dir, nivel-1);
	}
}

void impressao_arv_niveis(ArvB *a){
	int h = arvb_altura(a) + 1;
	int i;
	for(i = 1; i <= h; i++){
		aux_impressao_arv_niveis(a, i);
		printf("- Nivel %d\n", i-1);
	}
}
