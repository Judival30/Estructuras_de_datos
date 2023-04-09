#include "lista.h"


// Punto 1
int contarOcurrencias(Lista &l, int v)
{
    int cont = 0;
    for (int i = 1; i <= l.longLista(); i++)
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
        if (l.infoLista(i) < v)
        {
            ans.anxLista(l.infoLista(i));
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
}
