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
