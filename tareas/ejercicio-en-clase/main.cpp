/*
Autor: Juan Diego Valencia Alomia
5/05/2023
Implementación del TAD cola de prioridad

Complejidad de los metodos:
-front():
    Tiene una complejidad de O(1) ya que se obtiene el iterador en la primera posición con begin() y se retorna lo que se 
    encuentra dentro de dicho iterador.
-enqueue():
    Tiene una complejidad de nlog(n) siendo n el tamaño de la lista, ya que esta es la complejidad de organizar la lista interna
    por medio del sort.
-deque():
    Tiene una complejidad de O(1) ya que eliminar el primer elemento de la lista doble-circ es constante
-vaciaCola():
    Tiene una complejidad de O(1) ya que la función empty() tan solo verifica si la lista está vacía, lo cual realiza en tiempo 
    constante

Cabe resaltar que se podría optimizar la funcion de enqueue ya que se podría usar monticulos (heap), la cual tiene una menor complejidad.

*/


#include "cola-prioridad.h"

void imprimirElementos(Cola &c)
{
    while (!c.vaciaCola())
    {
        printf("%d\n", c.front());
        c.deque();
    }
}

int main()
{
    Cola c;
    c.enqueue(1);
    c.enqueue(4);
    c.enqueue(6);
    c.enqueue(8);
    imprimirElementos(c);

    return 0;
}
