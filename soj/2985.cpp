#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

int n,ans;
double win[130][130];
double p[8][130],maxp;

double dfs(int k,int x)
{
    if (p[k][x]>=0) return p[k][x];
    int tt=1<<k,t;
    t=(x-1)/tt; t=t*tt; tt>>=1;
    p[k][x]=0;
    if (x<=t+tt)
    {
        for (int i=t+tt+1;i<=t+(tt<<1);i++)
            p[k][x]+=dfs(k-1,x)*dfs(k-1,i)*win[x][i];
    }
    else
    {
        for (int i=t+1;i<=t+tt;i++)
            p[k][x]+=dfs(k-1,x)*dfs(k-1,i)*win[x][i];
    }
    return p[k][x];
}

int main()
{
    while (scanf("%d",&n)==1 && n>0)
    {
        for (int i=1;i<=(1<<n);i++)
            for (int j=1;j<=(1<<n);j++)
                scanf("%lf",&win[i][j]);
        for (int j=1;j<=(1<<n);j++)
            p[0][j]=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=(1<<n);j++)
                p[i][j]=-1;
        ans=0; maxp=0;
        for (int i=1;i<=(1<<n);i++)
        {
            if (dfs(n,i)>maxp)
            {
                maxp=p[n][i];
                ans=i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}