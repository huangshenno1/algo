#include <cstdio>
#include <cstring>

int t,tt,n;
int a[15];
int num[101];
bool ff;

void solve(int cur,int count,int s)
{
    int i;
    if (count>12)
        return;
    if (s==t)
    {
        for (i=0;i<count;i++)
        {
            if (i>0) printf("+");
            printf("%d",a[i]);
        }
        printf("\n");
        ff=1;
        return;
    }
    for (i=cur;i>0;i--)
    {
        if (num[i]>0 && s+i<=t)
        {
            a[count]=i;
            num[i]--;
            solve(i,count+1,s+i);
            num[i]++;
        }
    }
}

int main()
{
    int i;
    while (scanf("%d%d",&t,&n)==2 && n)
    {
        memset(num,0,sizeof(num));
        for (i=0;i<n;i++)
        {
            scanf("%d",&tt);
            num[tt]++;
        }
        ff=0;
        printf("Sums of %d:\n",t);
        solve(100,0,0);
        if (!ff)
            printf("NONE\n");
    }
    return 0;
}