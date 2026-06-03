#include <stdio.h>

int main()
{
    int n, t, p = -1;

    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &t);

    for(int i = 0; i < n; i++)
    {
        if(a[i] == t)
        {
            p = i;
            break;
        }
    }

    if(p != -1)
        printf("Element found at index %d", p);
    else
        printf("Element not found");

    return 0;
}
