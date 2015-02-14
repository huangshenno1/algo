#include <cstdio>

struct Pair
{
    int a,b;
}ans[20];
int s[20000];
int cnt;

void solve()
{
    for (int i=0;i<20000;i++)
        s[i]=0;
    for (int i=1;i<20000;i++)
        for (int j=i<<1;j<20000;j+=i)
            s[j]+=i;
    ans[0].a=0;
    cnt=1;
    for (int i=6;i<20000;i++)
    {
        if (s[i]!=i && s[i]<20000 && s[s[i]]==i)
        {
            ans[cnt].a=i;
            ans[cnt++].b=s[i];
        }
    }
}

int main()
{
    solve();
    int n,m;
    while (scanf("%d",&n)==1)
    {
        for (m=cnt-2;m>=0;m--)
        {
            if (ans[m].a<n)
            {
                printf("%d %d\n",ans[m+1].a,ans[m+1].b);
                break;
            }
        }
    }
    return 0;
}