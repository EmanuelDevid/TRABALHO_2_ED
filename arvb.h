typedef struct arv ArvB;
typedef struct fila Fila;
typedef struct lista Lista;

//Função que cria uma Árvore Binária de Busca Vazia.
ArvB* arvb_cria_vazia(void);

//Testa se uma Árvore Binária é vazia.
int arvb_vazia(ArvB *a);

//Função que busca a sub-árvore que contém um inteiro.
ArvB* arvb_busca(ArvB *a,int c);

//Função que imprime os elementos de uma Árvore.
void arvb_imprime(ArvB *a);

//Função que insere um inteiro em uma Árvore.
ArvB* arvb_insere(ArvB *a, int c);

//Função que remove um inteiro em uma Árvore.
ArvB* arvb_remove(ArvB *a, int c);

//Libera o espaço alocado para uma Árvore.
void arvb_libera(ArvB *a);

//Função que retorna a altura de uma Árvore.
int arvb_altura(ArvB *a);

//Função que retorna o números de folhas divisíveis por um parâmetro n.
int folhas_div_n(ArvB* a, int n);

//Função que retorna 1 se a árvore for degenerada e 0 caso contrário.
int isdegenerada(ArvB* a);

//Função que retorna a quantidade de nós com fator de balanceamento iguais a uma parÂmetro n.
int nos_fb_n(ArvB* a, int n);

//Função que preenche uma fila com elementos de uma árvore.
void preenche_fila(ArvB* a, Fila* f);

//Função que imprime os elementos em comum de duas árvores.
void impressao_arv_elem_comuns(ArvB* a, ArvB* b);

//Função que retorna o número de nós de uma árvore.
int num_nos(ArvB* a);

//Função que auxilia a função que imprime os elementos em seus respectivos níveis.
void aux_impressao_arv_niveis(ArvB *a, int nivel);

//Função que imprime os elementos em seus respectíveis níveis.
void impressao_arv_niveis(ArvB* a);
