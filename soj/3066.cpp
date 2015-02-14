#include <cstdio>

int main()
{
    int t,n,s,ss,a,i;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        s=ss=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a);
            s^=a;
            if (a==1)
                ss++;
        }
        if (ss==n)
            n&1?printf("Brother\n"):printf("John\n");
        else
            s?printf("John\n"):printf("Brother\n");
    }
    return 0;
}