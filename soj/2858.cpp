#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
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

int n,m,k,ans;
bool nprime[1000001];
int prime[1000001],cnt;

int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}

int main()
{
    while (scanf("%d%d",&m,&k)==2)
    {
        if (m==1)
        {
            printf("%d\n",k);
            continue;
        }
        for (int i=0;i<=m;i++) nprime[i]=0;
        n=m;
        for (int p=2;p*p<=n;p++)
        {
            if (n%p==0)
            {
                for (int i=p;i<=m;i+=p) nprime[i]=1;
                while (n%p==0) n/=p;
            }
        }
        if (n>1) {for (int i=n;i<=m;i+=n) nprime[i]=1;}

        cnt=0;
        for (int i=1;i<=m;i++)
            if (!nprime[i]) prime[cnt++]=i;

        ans = k/cnt;
        k = k%cnt;
        if (k==0) {ans--; k=cnt;}
        ans = ans*m + prime[k-1];
        printf("%d\n",ans);
    }
    return 0;
}
