#include <cstdio>
#include <cstring>
using namespace std;

int T,n;
char str[20];
long long fac[20],no;

long long cal()
{
    long long res=0;
    for (int i=0;i<n;i++)
    {
        int cnt=0;
        for (int j=i+1;j<n;j++)
            if (str[i]>str[j]) cnt++;
        res+=fac[n-i-1]*cnt;
    }
    return res;
}

void solve()
{
    int i,j,k;
    for (i=n-2;i>=0;i--)
        if (str[i]>str[i+1]) break;
    for (j=n-1;j>i;j--)
        if (str[j]<str[i]) break;
    if (j<=i) return;
    char tmp[20];
    strcpy(tmp,str);
    str[i]=tmp[j];
    str[j]=tmp[i];
    tmp[i]=str[i];
    tmp[j]=str[j];
    for (k=i+1;k<n;k++)
        str[k]=tmp[n-k+i];
}

int main()
{
    fac[0]=1;
    for (int i=1;i<20;i++)
        fac[i]=fac[i-1]*i;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %s",&n,str);
        no=cal();
        if (no==0)
        {
            puts("0 NULL!");
            continue;
        }
        solve();
        printf("%lld ",no);
        printf("%s\n",str);
    }
    return 0;
}