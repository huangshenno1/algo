#include <cstdio>

const int maxn = 10;
const int maxnn = 1024;
int n,m;
int w[maxn],b[maxn];
double d[maxn][maxn];
double price[maxnn][maxn];

int max(int a,int b) {return a>b?a:b;}

int f(int state, double money)
{
    int res=0;
    for (int i=0;i<n;i++)
    {
        if (state&1<<i) continue;
        if (money<price[state][i]) continue;
        res=max(res,b[i]+f(state|1<<i,money-price[state][i]));
    }
    return res;
}

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=0;i<n;i++) scanf("%d",&w[i]);
        for (int i=0;i<n;i++) scanf("%d",&b[i]);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                scanf("%lf",&d[i][j]);
        for (int i=0;i<(1<<n);i++)
        {
            for (int j=0;j<n;j++)
            {
                if (i&1<<j) continue;
                int x=i,k=0;
                price[i][j]=w[j];
                while (x)
                {
                    if (x&1) price[i][j]*=d[k][j];
                    x>>=1; k++;
                }
            }
        }
        printf("%d\n",f(0,m));
    }
    return 0;
}
