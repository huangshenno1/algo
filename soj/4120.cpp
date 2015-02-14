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

int T,n,l,ans;

int C(int a,int b)
{
    if (a==0 || a==b) return 1;
    return C(a-1,b-1)+C(a,b-1);
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        ans=n;
        l=-1;
        while (n) {l++; n>>=1;}
        ans=ans-1-C(l/2,l);
        printf("%d\n",ans);
    }
    return 0;
}
