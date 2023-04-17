#include "lista.h"

void concatenarListas(Lista &l1, Lista &l2)
{
    for (int i = 1; i <= l2.longLista(); i++)
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
