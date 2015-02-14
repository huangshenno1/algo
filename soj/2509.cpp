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

const int maxn = 25010;
int n,t,ans;
struct Cow
{
    int a,b;
    bool operator < (const Cow &o) const
    {
        return min(b,o.a) > min(o.b,a);
    }
}cow[maxn];

int main()
{
    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<n;i++) scanf("%d%d",&cow[i].a,&cow[i].b);
        sort(cow,cow+n);
        ans=0; t=0;
        for (int i=0;i<n;i++)
        {
            ans+=cow[i].a;
            t=max(0,t-cow[i].a);
            t+=cow[i].b;
        }
        ans+=t;
        printf("%d\n",ans);
    }
    return 0;
}
