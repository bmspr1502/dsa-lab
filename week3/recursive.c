#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define size 100

char lower[size], upper[size];
int l = 0, u = 0;

void string_change(char a[], int i, int n) // Time complexity=O(n)
{
    if (i == n)
    {
        i = 0;
        int j;
        for (j = 0; upper[j]; j++) //O(n)
        {
            a[i++] = upper[j];
        }

        for (j = 0; lower[j]; j++) //O(n)
        {
            a[i++] = lower[j];
        }

        return;
    }
    else
    {
        if (islower(a[i]))
        {
            lower[l++] = a[i];
            lower[l] = '\0';
        }
        else 
        {
            upper[u++] = a[i];
            upper[u] = '\0';
        }
    }
    return string_change(a, i + 1, n);
}

int main()
{
    int i, l, m;
    char a[size];
    scanf("%s", a);

    string_change(a, 0, strlen(a));

    printf("%s", a);

    return 0;
}