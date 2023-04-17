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
