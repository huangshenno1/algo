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

typedef long long ll;
int n,n1,n2,lim;
int a[50],b[50];
ll ans,suma,sumb,mina;
struct Node
{
    ll sa,sb;
    bool operator<(const Node &o) const {return sb<o.sb;}
}s1[1100000],s2[1100000];
int k1,k2;

int main()
{
    while (scanf("%d%d",&n,&lim)==2)
    {
        ans=-1;
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        sumb=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            sumb+=b[i];
        }
        if (lim==0)
        {
            puts("0");
            continue;
        }
        if (sumb<lim)
        {
            puts("-1");
            continue;
        }
        if (n==1)
        {
            if (b[0]>=lim) ans=a[0];
            printf("%lld\n",ans);
            continue;
        }

        n1=n/2; n2=n-n1;
        k1=k2=0;
        for (int x=1;x<(1<<n1);x++)
        {
            suma=sumb=0;
            for (int i=0;i<n1;i++)
                if (x&(1<<i))
                {
                    suma+=a[i];
                    sumb+=b[i];
                }
            if (sumb>=lim)
            {
                if (ans==-1 || ans>suma) ans=suma;
            }
            else
            {
                s1[k1].sa=suma;
                s1[k1].sb=sumb;
                k1++;
            }
        }
        mina=-1;
        for (int x=1;x<(1<<n2);x++)
        {
            suma=sumb=0;
            for (int i=0;i<n2;i++)
                if (x&(1<<i))
                {
                    suma+=a[n1+i];
                    sumb+=b[n1+i];
                }
            if (sumb>=lim)
            {
                if (mina==-1 || mina>suma) mina=suma;
                if (ans==-1 || ans>suma) ans=suma;
            }
            else
            {
                s2[k2].sa=suma;
                s2[k2].sb=sumb;
                k2++;
            }
        }
        sort(s1,s1+k1); sort(s2,s2+k2);

        int j=k2-1;
        for (int i=0;i<k1;i++)
        {
            while (j>=0 && s1[i].sb+s2[j].sb>=lim)
            {
                if (mina==-1 || mina>s2[j].sa) mina=s2[j].sa;
                j--;
            }
            if (mina>=0 && (ans==-1 || ans>s1[i].sa+mina)) ans=s1[i].sa+mina;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
