#include <stdio.h>


int main()
{
    int i, n1, n2, n3, cuenta, factor;
    scanf("%d %d %d %d", &i, &n1, &n2, &n3);
    while (i + n1 + n2 + n3 != 0)
    {
        /* Primeras dos vueltas y factor de conversion numero a grado*/
        cuenta = 360 * 2;
        factor = 360 / 40;

        /* Busqueda del primer numero  */
        if (n1 > i)
        {
            cuenta += ((i + 40 - n1) * factor);
        }
        else if (n1 < i)
        {
            cuenta += ((i - n1) * factor);
        }

        /* 1 giro completo */
        cuenta += 360;
        /* Busqueda del segundo numero  */

        if (n1 > n2)
        {
            cuenta += ((n2 + 40 - n1) * factor);
        }
        else if (n1 < n2)
        {
            cuenta += ((n2 - n1) * factor);
        /* Busqueda del tercer numero  */
        }

        if (n2 > n3)
        {
            cuenta += ((n2 - n3) * factor);
        }
        else if (n2 < n3)
        {
            cuenta += ((n2 + 40 - n3) * factor);
        }

        printf("%d\n", cuenta);
        scanf("%d %d %d %d", &i, &n1, &n2, &n3);
    }
    return 0;
}
