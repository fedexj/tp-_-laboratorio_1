#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXITEMS 5

typedef struct {

    char nombre[50];
    int edad;
    int isEmpty;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int espacioLibreFc(EPersona lista[], int length);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDniFc(EPersona lista[], int length);

/** \brief inicializa en 1 el parametro isEmpty de una estructura todo
 *
 * \param lista el array se pasa como parametro.
 * \param int numero maximo de elementos en la estructura
 * \return void
 *
 */
void isEmptyFc(EPersona lista[],int length);

/** \brief Pide al usuario que cargue los campos de informacion de la estructura, los valida y los carga a la estructura
 *
 * \param lista el array se pasa como parametro.
 * \param int numero maximo de elementos en la estructura
 * \return devuelve un int 0 si logro hacer la carga, -1 si no
 *
 */
int addEmployeeFc(EPersona lista[], int length);

/** \brief ordena las entradas de la estructura en orden alfabetico por nombre
 *
 * \param lista el array se pasa como parametro.
 * \param int numero maximo de elementos en la estructura
 * \return evuelve un int 0 si logro ordenar, -1 si no
 */
int sortEmployeesByNameFc(EPersona lista[], int length);

/** \brief imprime todos los elementos de la estructura
 *
 * \param lista el array se pasa como parametro.
 * \param int numero maximo de elementos en la estructura
 * \return void
 *
 */
void printEmployeesFc(EPersona lista[], int length);

/** \brief cuenta los elementos de un conjunto deseado, en este caso para el parametro edad de la estructura
 *
 * \param lista el array se pasa como parametro.
 * \param int numero maximo de elementos en la estructura
 * \param parametro limite inferior del conjunto a crear
 * \param parametro limite superior del conjunto a crear
 * \return int devuelve la cantidad de elementos en el conjunto deseado
 *
 */
int groupBuilderFc(EPersona lista[], int length, int lowParameter, int hiParameter);

/** \brief verifica si un dato de la estructura esta duplicado, en este caso el DNI
 *
 * \param int dni cargado a verificar
 * \param lista el array se pasa como parametro.
 * \param int numero maximo de elementos en la estructura
 * \return int devuelve 0 si esta duplicado el DNI, 1 si no lo esta
 *
 */
int checkDniFc(int auxDni,EPersona lista[],int length);

/** \brief imprime un grafico de barras verticales, marcando un asterisco por elemento del conjunto
 *
 * \param int numero de elementos en la columna 1
 * \param int numero de elementos en la columna 2
 * \param int numero de elementos en la columna 3
 * \param int numero totales de columnas
 * \return void
 *
 */
void printGraphic(int col1, int col2, int col3, int totalBars);



#endif // FUNCIONES_H_INCLUDED
