#define MAXNOME 100
#define MAXEMAIL 100
typedef struct Registro {
  char nome[MAXNOME];
  int matricula;
  int ddd;
  int telefone;
  char email[MAXEMAIL];
  char tipo;
  struct Registro *prox;
  struct Registro *ant;
} Registro;
Registro *buscar(Registro **, int);
void inicializarLista(Registro **lista);
int inserirFinal(Registro **lista, char nome[], int matricula, int ddd,int telefone, char email[], char tipo);
void inserir_inicio(Registro **lista, char nome[], int matricula, int ddd, int telefone, char email[], char tipo);
void agd_remover(Registro **lista, char []);
void agd_ordenar(Registro **lista);
void percorrerLista(Registro *lista);
int carregarDados(Registro **lista, const char *nomeArquivo);
int salvarDados(Registro *lista, const char *nomeArquivo);
