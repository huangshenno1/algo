#include <cstdio>

int main()
{
    int a,b,n;
    while (scanf("%d%d%d",&a,&b,&n)==3)
    {
        if (n==0)
            printf("0\n");
        else printf("%d\n",(a+b)%2);
    }
    return 0;
}