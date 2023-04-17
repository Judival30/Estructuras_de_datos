#include "lista.h"

void insertarEnListaOrdenada(Lista &l, int v)
{
    int ins = 0;
    for (int i = 1; i <= l.longLista() and l.infoLista(i) < v; i++)
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
