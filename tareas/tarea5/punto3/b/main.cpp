/*
Estructuras de datos - tarea5 - punto 3b
Juan Diego Valencia Alomia 
code: 8977467

Para el desarrollo de este punto se escogió la implementación creada por el docente Carlos Ramirez de una lista simple, y se modificó la interfaz para
sustituir las funciones modificadoras por la función insListaOrdenada:

Complejidad:
La función insListaOrdenada recorre la lista por medio de sus nodos desde la interfaz hasta que el elemento nuevo sea mayor o igual al nodo en que está, 
por lo que la complejidad sería O(k) que es la posición donde el nuevo elemento se debe insertar, o en el peor caso O(n) donde el elemento es mayor a todos
los elementos de la lista, y por ultimo en el mejor caso sería O(1) si el elemento es menor que todo el resto de la lista

Explicación de uso de las funciones:
Se hace uso del procedimiento printlist() el cual es usado para imprimir la lista. Entonces se crea en el main una lista con datos al azar con la función
creada y se comprueba su funcionalidad.
*/
#include "lista.h"

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
    list.insListaOrdenada(4);
    list.insListaOrdenada(19);
    list.insListaOrdenada(31);
    list.insListaOrdenada(1);
    list.insListaOrdenada(0);
    list.insListaOrdenada(13);
    list.insListaOrdenada(20);
    printLista(list);
    return 0;
}
