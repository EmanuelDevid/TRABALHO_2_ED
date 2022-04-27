typedef struct lista Lista;
typedef struct fila Fila;

//Fun��o que cria uma Fila.
Fila* fila_cria(void);

//Testa se uma Fila � vazia.
int fila_vazia(Fila *f);

//Fun��o que adiciona um elemento em uma Fila.
void fila_insere(Fila *f, int info);

//Fun��o que imprime os elementos de uma Fila.
void fila_imprime(Fila *f);
