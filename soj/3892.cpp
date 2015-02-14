#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <cassert>
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

#define ll long long
#define pii pair<int, int>
#define fr first
#define sc second
#define mp make_pair
#define FOR(i,j,k) for(int i=j;i<=(k);i++)
#define FORD(i,j,k) for(int i=j;i>=(k);i--)
#define REP(i,n) for(int i=0;i<(n);i++)

const int maxn = 1010;
int n, ans, add[maxn], a, b;
char ch;

int main()
{
    while (scanf("%d", &n) == 1 && n)
    {
        ch = 'g';
        memset(add, 0, sizeof(add));
        while (1)
        {
            if (ch == '\n') break;
            scanf("%d", &a);
            ch = getchar();
            if (ch == '-')
            {
                scanf("%d", &b);
                ch = getchar();
                if (a > n || a > b) continue;
                if (b > n) b = n;
                add[a]++; add[b+1]--;
            }
            else
            {
                if (a > n) continue;
                add[a]++; add[a+1]--;
            }
        }
        ans = 0;
        for (int i=0,go=0;i<=n;i++)
        {
            go += add[i];
            ans += (go > 0);
        }
        printf("%d\n", ans);
    }
    return 0;
}
