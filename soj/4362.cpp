#include <cstdio>
#include <cstring>

int main()
{
    int T;
    char str[1100];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", str);
        bool yes = 1;
        int len = strlen(str);
        for (int i=1;i<len;i++)
            if (str[i] < str[i-1]) yes = 0;
        if (yes) puts("Yes");
        else puts("No");
    }
    return 0;
}