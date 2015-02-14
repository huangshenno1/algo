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
const int maxn = 510;

int n,m;
char a[maxn][maxn];
int cnt[5];

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=0;i<5;i++) cnt[i]=0;
        for (int i=0;i<1+n*5;i++)
            scanf("%s",a[i]);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                int x=0;
                for (int k=1;k<=4;k++)
                    if (a[i*5+k][j*5+1]=='*') x++;
                cnt[x]++;
            }
        for (int i=0;i<4;i++) printf("%d ",cnt[i]);
        printf("%d\n",cnt[4]);
    }
    return 0;
}
