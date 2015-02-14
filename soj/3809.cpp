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
int T;
ll x,y,d;

ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lld%lld",&x,&y);
        d=gcd(x,y);
        while (gcd(x,d)>1) x/=gcd(x,d);
        while (gcd(y,d)>1) y/=gcd(y,d);
        if (x>1 || y>1) puts("no");
        else puts("yes");
    }
    return 0;
}
