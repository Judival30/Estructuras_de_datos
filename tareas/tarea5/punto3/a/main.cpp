/*
Estructuras de datos - tarea5 - punto 3a
Juan Diego Valencia Alomia 
code: 8977467

Para el desarrollo de este punto se escogió la implementación creada por el docente Carlos Ramirez de una lista simple, y se implementaron las funciones
sin modificar la interfaz del TAD:

Complejidad:
La función insertarEnListaOrdenada hace uso de la función infoLista() como punto de parada para encontrar la posición donde se debe insertar, por lo que
llamaremos k al numero que corresponde a la posición donde se debe insertar v, además se usa longLista para saber el tamaño de la lista y finalmente 
la función de insertar que tiene complejidad k, por lo tanto T(n) = n + 2k, por lo tanto demuestra un comportamiento lineal, es decir que su complejidad
es O(n)

Explicación de uso de las funciones:
Se hace uso del procedimiento printlist() el cual es usado para imprimir la lista. Entonces se crea en el main una lista y se llama a las dos funciones 
analizadoras que acabamos de crear y se comprueba su funcionalidad.
*/
#include "lista.h"

void insertarEnListaOrdenada(Lista &l, int v)
{
    int ins = 0;
    int size = l.longLista();
    for (int i = 1; i <= size and l.infoLista(i) < v; i++)
    {
        ins = i + 1;
    }
    l.insLista(v, ins);
}

void printLista(Lista &l)
{
    for (int i = 1; i <= l.longLista(); i++)
    {
        cout << l.infoLista(i) << " ";
    }
    cout << endl;
}

int main()
{
    Lista list;
    list.anxLista(0);
    list.anxLista(1);
    list.anxLista(2);
    list.anxLista(4);
    list.anxLista(5);
    list.anxLista(8);
    printLista(list);

    insertarEnListaOrdenada(list, 3);
    insertarEnListaOrdenada(list, 1);
    printLista(list);
    return 0;
}
