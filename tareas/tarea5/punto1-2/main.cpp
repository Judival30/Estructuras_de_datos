/*
Estructuras de datos - tarea5 - punto 1 - 2
Juan Diego Valencia Alomia 
code: 8977467

Para el desarrollo de este punto se escogió la implementación creada por el docente Carlos Ramirez de una lista simple, y se implementaron las funciones
sin modificar la interfaz del TAD:

Complejidad punto 1: 
En este caso la complejidad es O(n^2) ya que se llama a función longLista() que tiene complejidad n y posteriormente se llama
a la función infolista() que tiene complejidad n, por lo que se recorre la lista n veces, dando consigo su comportamiento cuadratico

Complejidad punto 2: 
En este caso como en el punto 1 la complejidad es O(n^2) ya que se recorre n veces la lista por el uso de las funciones infolista()
y longLista(), cabe resaltar que la función anxlista tiene implicaciones en la complejidad del algoritmo al recorrer la lista ans, sin embargo, no cambia 
el comportamiento cuadratico de la función, por lo que la complejidad se conserva O(n^2)

Explicación de uso de las funciones:
Se hace uso del procedimiento printlist() el cual es usado para imprimir la lista. Entonces se crea en el main una lista y se llama a las dos funciones 
analizadoras que acabamos de crear y se comprueba su funcionalidad.
*/

#include "lista.h"

/**/
// Punto 1
int contarOcurrencias(Lista &l, int v)
{
    int cont = 0;
    int size = l.longLista();
    for (int i = 1; i <= size; i++)
    {
        if (l.infoLista(i) == v)
        {
            cont++;
        }
    }
    return cont;
}

// Punto 2

Lista obtenerMenores(Lista &l, int v)
{
    Lista ans;
    for (int i = 1; i <= l.longLista(); i++)
    {
        int num = l.infoLista(i);
        if (num < v)
        {
            ans.anxLista(num);
        }
    }
    return ans;
}

void printLista(Lista &l)
{
    for (int i = 1; i <= l.longLista(); i++)
    {
        cout << l.infoLista(i) << endl;
    }
}

int main()
{
    Lista list;
    list.anxLista(0);
    list.anxLista(2);
    list.anxLista(5);
    list.anxLista(3);
    list.anxLista(2);
    list.anxLista(4);
    int ans = contarOcurrencias(list, 2);
    cout << ans << endl
         << endl;
    Lista result = obtenerMenores(list, 4);
    printLista(result);
    return 0;
}
