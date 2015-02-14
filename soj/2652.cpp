#include <cstdio>
#include <cstring>

int T,lenS,lenP,ans;
char str[1000010], pattern[10010];
int next[10010];

void getnext(char *P,int *next)
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i <= lenP)
    {
        if (j == -1 || P[i] == P[j])
        {
            i++; j++;
            if (P[i] == P[j]) next[i] = next[j];
            else next[i] = j;
        }
        else j = next[j];
    }
}

void kmp(char* S,char* P,int *next)
{
    int i = 0, j = 0;
    ans = 0;
    while (i < lenS)
    {
        if (j == -1 || S[i] == P[j])
        {
            i++; j++;
            if (j == lenP)
            {
                ans++;
                j = next[j];
            }
        }
        else j = next[j];
    }
}

int main()
{
    scanf("%d\n", &T);
    while (T--)
    {
        gets(pattern);
        lenP = strlen(pattern);
        gets(str);
        lenS = strlen(str);

        getnext(pattern, next);
        kmp(str, pattern, next);
        printf("%d\n",ans);
    }
    return 0;
}