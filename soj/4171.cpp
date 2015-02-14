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
const int mod = 1000000;
const int maxn = 1010;

ll catalan[maxn]={0};

int main()
{
    catalan[0]=catalan[1]=1;
    for (int i=2;i<=1000;i++)
    {
        for (int j=0;j<i;j++)
            catalan[i]=(catalan[i]+catalan[j]*catalan[i-j-1])%mod;
    }
    int n;
    while (scanf("%d",&n)==1 && n)
    {
        printf("%lld\n",catalan[n]);
    }
    return 0;
}
