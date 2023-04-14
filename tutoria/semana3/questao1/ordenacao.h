# ifndef ordenacao_h
# define ordenacao_h

typedef struct upa Upa;

Upa *alocaUpas(int);

void lerUpas(Upa **, int);

void imprime(Upa *, int);

void mergeSort(Upa *, int, int);

void merge(Upa *, int, int, int);

void desalocaUpas(Upa**);

Upa *copy(Upa *, int, int);

# endif