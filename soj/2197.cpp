#include <cstdio>

int main()
{
    int n;
    while (scanf("%d",&n)==1 && n)
    {
        if (n<3)
            printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}