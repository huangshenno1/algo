#include <cstdio>

int main()
{
    int n,k,s,x,i;
    while (scanf("%d%d",&n,&k)==2)
    {
        s=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&x);
            s=s^(x%(k+1));
        }
        if (s) printf("windy7926778\n");
        else printf("fgjlwj\n");
    }
    return 0;
}