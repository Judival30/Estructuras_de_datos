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
