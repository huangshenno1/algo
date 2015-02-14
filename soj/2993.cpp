#include <cstdio>

int main()
{
    int n;
    int a[1010];
    int s,i;
    int ans;
    while (scanf("%d",&n)==1 && n)
    {
        s=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            s=s^a[i];
        }
        if (s)
        {
            ans=0;
            for (i=0;i<n;i++)
            {
                if (a[i]>(a[i]^s))
                    ans++;
            }
            printf("%d\n",ans);
        }
        else printf("0\n");
    }
    return 0;
}