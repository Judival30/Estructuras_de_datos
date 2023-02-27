#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int num, n, i, j, suma;
    int arreglo[3001];

    while (scanf("%d", &n) != EOF)
    {
        int secuencia[3001] = {0};
        int flag = 1;
        scanf("%d", &arreglo[0]);
        for (i = 1; i < n; i++)
        {
            scanf("%d", &arreglo[i]);
            num = abs(arreglo[i - 1] - arreglo[i]);
            if (num > n - 1)
            {
                flag = 0;
            }
            else
            {
                secuencia[num] = 1;
            }
        }
        j = 1;
        while (j < n && flag == 1)
        {
            if (secuencia[j] != 1)
            {
                flag = 0;
            }
            j++;
        }

        if (flag == 1)
        {
            printf("Jolly\n");
        }
        else
        {
            printf("Not jolly\n");
        }
    }
    return 0;
}
