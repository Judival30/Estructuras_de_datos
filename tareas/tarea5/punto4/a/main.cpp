/*
Estructuras de datos - tarea5 - punto 4a
Juan Diego Valencia Alomia 
code: 8977467

Para el desarrollo de este punto se escogió la implementación creada por el docente Carlos Ramirez de una lista simple, y se implementaron la función
sin modificar la interfaz del TAD:

Complejidad:
La función concatenarListas hace uso de longLista, anxLista e infoLista entonces lo que hace es recorrer la lista2 
para ingresar sus elementos en la lista1, por lo que al usar anxlista se recorre las lista 1 cuantas 
veces elementos tenga lista2, por lo tanto el comportamiento es cuadratico, es decir que la complejidad es O(n^2)

Explicación de uso de las funciones:
Se hace uso del procedimiento printlist() el cual es usado para imprimir la lista. Entonces se crea en el main dos listas y se llama la función 
pasandole las dos listas y se comprueba su funcionalidad.
*/
#include "lista.h"

void concatenarListas(Lista &l1, Lista &l2)
{
    int l2size = l2.longLista();
    for (int i = 1; i <= l2size; i++)
    {
        l1.anxLista(l2.infoLista(i));
    }
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
    Lista list1, list2;
    // Creación lista 1
    list1.anxLista(2);
    list1.anxLista(4);
    list1.anxLista(5);
    list1.anxLista(8);
    // Creación lista 2
    list2.anxLista(4);
    list2.anxLista(19);
    list2.anxLista(31);
    list2.anxLista(1);

    // Impresión de forma separada
    printf("Lista 1:\n");
    printLista(list1);
    printf("Lista 2:\n");
    printLista(list2);
    // Concatenar las listas
    concatenarListas(list1, list2);
    printf("Lista 1 + Lista 2:\n");
    printLista(list1);

    return 0;
}
