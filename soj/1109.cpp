#include <cstdio>
#include <cstring>
#include <cctype>
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

ll h(ll x)
{
    ll res=0;
    while (x)
    {
        res++;
        x/=10;
    }
    return res;
}

ll g(ll a,ll b,ll c)
{
    return (a+b)*(a-b+1)/2*c;
}

ll f(ll x)
{
    if (x==0) return 0;
    ll res=0,t=1;
    while (x>=t*10)
    {
        res+=g(x-t+1,x-t*10+2,h(t));
        t*=10;
    }
    res+=g(x-t+1,1,h(t));
    return res;
}

int find(ll x)
{
    ll t=1;
    while (x>(t*10-t)*h(t))
    {
        x-=(t*10-t)*h(t);
        t*=10;
    }
    t+=(x-1)/h(t);
    x=(x-1)%h(t)+1;
    x=h(t)-x;
    while (x) {t/=10; x--;}
    return t%10;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        ll low=0,mid,high=100000;
        while (low<=high)
        {
            mid=(low+high)/2;
//              cout<<low<<" "<<high<<" "<<mid<<" "<<f(mid)<<endl;
            if (f(mid)<(ll)n&&f(mid+1)>=(ll)n) break;
            else if (f(mid)>=(ll)n) high=mid-1;
            else if (f(mid+1)<(ll)n) low=mid+1;
        }
//        cout<<mid<<" "<<f(mid)<<endl;
        n-=f(mid);
        printf("%d\n",find(n));
    }
    return 0;
}
