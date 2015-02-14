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

const int maxn = 100010;
char s[maxn];
int n, ss[maxn], sa[maxn], sx[maxn], sy[maxn], c[maxn];
int rank[maxn], height[maxn];

void build_sa(int m)
{
    int *x = sx, *y = sy;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = ss[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i-1];
    for (int i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        int p = 0;
        for (int i = n-k; i < n ; i++) y[p++] = i;
        for (int i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 1; i < m; i++) c[i] += c[i-1];
        for (int i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1; x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = (y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k]) ? p-1 : p++;
        if (p >= n) break;
        m = p;
    }
}

void getHeight()
{
    int k = 0;
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (rank[i] <= 0) continue;
        if (k) k--;
        int j = sa[rank[i]-1];
        while (i+k<n && j+k<n && s[i+k] == s[j+k]) k++;
        height[rank[i]] = k;
    }
}

int main()
{
    while (scanf("%s", s) == 1 && strcmp(s, "*") != 0)
    {
        n = strlen(s);
        for (int i=0;i<n;i++) ss[i] = s[i] + 1;
        ss[n++] = 0;
        build_sa(129);
        //for (int i=0;i<n;i++) cout << sa[i] << " "; cout << endl;
        getHeight();
        ll ans = 0;
        for (int i=1;i<n;i++)
            ans += height[i] - min(height[i-1], height[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
