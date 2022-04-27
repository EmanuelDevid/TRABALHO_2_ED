typedef struct arv ArvB;
typedef struct fila Fila;
typedef struct lista Lista;

//Fun��o que cria uma �rvore Bin�ria de Busca Vazia.
ArvB* arvb_cria_vazia(void);

//Testa se uma �rvore Bin�ria � vazia.
int arvb_vazia(ArvB *a);

//Fun��o que busca a sub-�rvore que cont�m um inteiro.
ArvB* arvb_busca(ArvB *a,int c);

//Fun��o que imprime os elementos de uma �rvore.
void arvb_imprime(ArvB *a);

//Fun��o que insere um inteiro em uma �rvore.
ArvB* arvb_insere(ArvB *a, int c);

//Fun��o que remove um inteiro em uma �rvore.
ArvB* arvb_remove(ArvB *a, int c);

//Libera o espa�o alocado para uma �rvore.
void arvb_libera(ArvB *a);

//Fun��o que retorna a altura de uma �rvore.
int arvb_altura(ArvB *a);

//Fun��o que retorna o n�meros de folhas divis�veis por um par�metro n.
int folhas_div_n(ArvB* a, int n);

//Fun��o que retorna 1 se a �rvore for degenerada e 0 caso contr�rio.
int isdegenerada(ArvB* a);

//Fun��o que retorna a quantidade de n�s com fator de balanceamento iguais a uma par�metro n.
int nos_fb_n(ArvB* a, int n);

//Fun��o que preenche uma fila com elementos de uma �rvore.
void preenche_fila(ArvB* a, Fila* f);

//Fun��o que imprime os elementos em comum de duas �rvores.
void impressao_arv_elem_comuns(ArvB* a, ArvB* b);

//Fun��o que retorna o n�mero de n�s de uma �rvore.
int num_nos(ArvB* a);

//Fun��o que auxilia a fun��o que imprime os elementos em seus respectivos n�veis.
void aux_impressao_arv_niveis(ArvB *a, int nivel);

//Fun��o que imprime os elementos em seus respect�veis n�veis.
void impressao_arv_niveis(ArvB* a);
