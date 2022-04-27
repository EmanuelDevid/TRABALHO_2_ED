typedef struct lista Lista;

//Cria uma lista vazia.
Lista* lst_cria();

//Insere um elemento no in�cio da lista.
Lista* lst_insere(Lista *l, int info);

//Imprime uma lista.
void lst_imprime(Lista *l);

//Libera o espa�o alocado por uma lista.
void lst_libera(Lista *l);
