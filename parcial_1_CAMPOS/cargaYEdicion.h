typedef struct
{
    char nombre[50];
    char usuario[50];
    char clave[50];
    int id;
    int estado;
} EPersona;

typedef struct
{
    char nombrePublicacion[50];
    int idPublicaion;
    int precio;
    int stock;
    int estado;
} EPublicaciones;

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);
int getNumeroAleatorio(int desde, int hasta, int iniciar);
void getString(char mensaje[],char arrayChar[]);
int getNumerosChar (char array[],char mensaje[]);
int getStringLetras(char mensaje[],char input[]);
int obtenerEspacioLibre(EPersona lista[], int cantidad_elementos, int estado);
void inicializarListaDeUsuario(EPersona lista[],int cantidad,int estado);
int buscarPorDni(EPersona lista[], int cantidad,char dni[]);
int buscarPorusuario(EPersona lista[], int cantidad,char usuario[]);
int obtenerEspacioLibrePublicacion(EPublicaciones lista[], int cantidad_elementos, int estado);
void inicializarListaDePublicacion(EPublicaciones lista[],int cantidad,int estado);
int buscarPorId(EPersona lista[], int cantidad, int valor);
int buscarPorIdPublicacion(EPublicaciones lista[], int cantidad,int valor);
