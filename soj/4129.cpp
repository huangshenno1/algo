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
const int maxn = 1000010;

int n;
char str[maxn];
int dpA[maxn],dpB[maxn];

int main()
{
    while (scanf("%d",&n)==1)
    {
        scanf("%s",str+1);
        dpA[0]=dpB[0]=0;
        for (int i=1;i<=n;i++)
        {
            if (str[i]=='A')
            {
                dpA[i]=min(dpA[i-1],dpB[i-1]+1);
                dpB[i]=min(dpA[i-1]+1,dpB[i-1]+1);
            }
            else
            {
                dpA[i]=min(dpA[i-1]+1,dpB[i-1]+1);
                dpB[i]=min(dpA[i-1]+1,dpB[i-1]);
            }
        }
        printf("%d\n",dpA[n]);
    }
    return 0;
}
