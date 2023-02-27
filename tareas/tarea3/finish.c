#include <stdio.h>


int main()
{
    int t, n, i, j, x, k, flag, subFlag;
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
        subFlag = 0;
        while (j < n && flag == 0)
        {
            disponible = 0;
            k = j;
            while (k < n && disponible >= 0)
            {
                disponible += p[k];
                disponible -= q[k];
                if (k == n - 1)
                {
                    subFlag = 1;
                }
                k++;
            }

            if (subFlag == 1)
            {
                for (k = 0; k < j; k++)
                {
                    disponible += p[k];
                    disponible -= q[k];
                }
                if (disponible >= 0)
                {
                    flag = 1;
                    x = j;
                }
            }
            j++;
        }

        disponible = 0;
        for (j = 0; j < n; j++)
        {
            disponible += p[j];
            disponible -= q[j];
        }

        if (flag == 1 && disponible >= 0)
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
