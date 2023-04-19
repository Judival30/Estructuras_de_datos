/*
Estructuras de datos - tarea5 - punto 4b
Juan Diego Valencia Alomia 
code: 8977467

Para el desarrollo de este punto se escogió la implementación creada por el docente Carlos Ramirez de una lista simple, y se implementaron una sobrecarga
del + para sumar listas

Complejidad:
La sobrecargar del + tiene dos momentos, el primer momento recorre la lista 1 por medio de sus nodos y se hace uso de la función anxlista para agregar
los elementos de la lista 1 a la lista ans, por lo que se genera una sumatoria de 0 a n siendo n el tamaño de l1 ya que se mofica en cada iteración el 
tamaño de la lista ans, dando un comportamiento cuadratico. En el segundo momento es algo similar pero esta vez son dos sumatorias con respecto al recorrido
de la lista ans con anxlista y luego el recorrido de la lista est con info lista, por lo que tambien es un comportamiento cudratico. De esta manera se 
puede concluir que la complejidad es O(n^2)

Explicación de uso de las funciones:
Se hace uso del procedimiento printlist() el cual es usado para imprimir la lista. Entonces se crea en el main dos listas l1 y l2
y posteriormente se crea una tercera l3 a la cual se le asigna la suma de l1 + l2 y se comprueba su funcionalidad.
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
    Lista l1, l2;
    // Creación lista 1
    l1.anxLista(2);
    l1.anxLista(4);
    l1.anxLista(5);
    l1.anxLista(8);
    // Creación lista 2
    l2.anxLista(4);
    l2.anxLista(19);
    l2.anxLista(31);
    l2.anxLista(1);

    // Impresión de forma separada
    printf("Lista 1:\n");
    printLista(l1);
    printf("Lista 2:\n");
    printLista(l2);
    // Concatenar las listas
    Lista l3 = l1 + l2;
    printf("Lista 1 + Lista 2:\n");
    printLista(l3);

    return 0;
}
