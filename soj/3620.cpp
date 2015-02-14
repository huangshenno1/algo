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
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
const int maxn = 60;

int T,n;
int a[maxn];

bool isAAB()
{
    for (int l=1;l*2<n;l++)
    {
        bool go=1;
        for (int i=1;i<=l;i++)
            if (a[i]!=a[i+l]) {go=0; break;}
        if (go) return 1;
    }
    return 0;
}

bool isABB()
{
    for (int l=1;l*2<n;l++)
    {
        bool go=1;
        for (int i=1;i<=l;i++)
            if (a[n+1-i]!=a[n+1-i-l]) {go=0; break;}
        if (go) return 1;
    }
    return 0;
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        if (n<3) {puts("no"); continue;}
        if (isAAB() || isABB()) puts("yes");
        else puts("no");
    }
    return 0;
}
