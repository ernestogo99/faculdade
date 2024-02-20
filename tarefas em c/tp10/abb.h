typedef struct no {
    int chave;
    float valor;
    struct no *esquerda;
    struct no *direita;
} No;

typedef struct ArvoreBB {
    No *raiz;
} ArvoreBB;

No *criar_no(int chave, float valor);
void inicializar(ArvoreBB **a);
int inserir_interativo(No **a, int chave, float val);
int inserir_recursivo(No **a, int chave, float val);
float buscar_interativo(No *a, int chave);
float buscar_recursivo(No *a, int chave);
void listar_elementos(No *a);