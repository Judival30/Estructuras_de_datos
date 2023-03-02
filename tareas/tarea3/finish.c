#include <stdio.h>

int main()
{
    int t, n, i, j, x, k, flag;
    int disponible;
    int p[100001], q[100001];
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {

        disponible = 0;
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &p[j]);
        }
        for (j = 0; j < n; j++)
        {
            scanf("%d", &q[j]);
        }
        flag = 0;
        j = 0;

        disponible = 0;
        int s = 0;
        int contador = 0;
        while (j < 2 * n && contador < n)
        {
            if (disponible + p[s] - q[s] >= 0)
            {
                if (flag == 0)
                {
                    x = s;
                    flag = 1;
                }
                disponible += p[s];
                disponible -= q[s];
                contador++;
            }
            else
            {
                disponible = 0;
                flag = 0;
                contador = 0;
            }
            s = (s + 1) % n;
            j++;
        }

        if (contador == n)
        {
            printf("Case %d: Possible from station %d\n", i, x + 1);
        }
        else
        {
            printf("Case %d: Not possible\n", i);
        }
    }
    return 0;
}
