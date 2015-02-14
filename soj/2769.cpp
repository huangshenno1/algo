#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int n,ans,x,d,i;
int a[maxn];
multiset<int> b;
multiset<int>::iterator it;

int main()
{
    while (scanf("%d",&n)==1)
    {
        b.clear();
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        ans=a[n-1];
        b.insert(a[n-1]);
        for (i=n-2;i>=0;i--)
        {
            x=a[i];
            b.insert(x);
            d=0x7fffffff;
            it=b.find(x);
            if (it!=b.begin())
            {
                d=min(d,x-*(--it));
                it++;
            }
            if (++it!=b.end())
                d=min(d,*it-x);
            ans+=d;
        }
        printf("%d\n",ans);
    }
    return 0;
}