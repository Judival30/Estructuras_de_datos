#include <stdio.h>


int main()
{
    int i, t, n, j, x, min, max, ans;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d", &n);
        min = 100;
        max = 0;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &x);
            if (min > x)
            {
                min = x;
            }
            if (max < x)
            {
                max = x;
            }
        }
        ans = (max - min) * 2;
        printf("%d\n", ans);
    }
    return 0;
}
