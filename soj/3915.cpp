#include <cstdio>

int main()
{
    int k,n,r;
    while (scanf("%d",&k)==1)
    {
        n=1,r=2;
        while (k>r)
        {
            k-=r;
            r<<=1;
            n++;
        }
        k--;
        for (int i=n-1;i>=0;i--)
            printf("%d",k&(1<<i)?7:4);
        printf("\n");
    }
    return 0;
}