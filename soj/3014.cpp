#include <cstdio>
#include <cstring>

int lenP,pos,i,k;
char pattern[400010];
int next[400010];
int ans[400010];

void getnext(char *P)
{
    int i = 1, j = -1;
    next[0] = -1;
    while(i < lenP)
    {
        while (j > -1 && P[j+1] != P[i])
            j = next[j];
        if (P[j+1] == P[i])
            j = j + 1;
        next[i] = j;
        i++;
    }
}

int main()
{
    while (gets(pattern))
    {
        lenP = strlen(pattern);
        getnext(pattern);

        for (k=0, i=lenP-1; i>=0; i=next[i])
            ans[k++] = i+1;
        printf("%d",ans[k-1]);
        for (i=k-2; i>=0; i--)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}