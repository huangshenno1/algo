#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 1005;
char line[maxn];
ll a[maxn], n;
ll x = 31, powx[maxn];
ll h[maxn], hn;

int find(int l)
{
    ll hash = 0;
    for (int i=0;i<l;i++) hash = hash*x + a[i];
    hn = 0;
    for (int i=l;i<n;i++)
    {
        hash = hash*x + a[i];
        h[hn++] = hash;
        hash = hash - a[i-l]*powx[l];
    }
    sort(h, h+hn);
    int ret = 1;
    for (int i=0;i<hn;)
    {
        int j = i+1;
        while (j<hn && h[j]==h[i]) j++;
        ret = max(ret, j-i);
        i = j;
    }
    return ret;
}

int main()
{
    powx[0] = 1;
    for (int i=1;i<maxn;i++) powx[i] = powx[i-1]*x;
    while (gets(line) && strcmp(line, "")!=0)
    {
        n = 0;
        for (int i=0;line[i];i++)
        {
            if (line[i] != ' ')
                a[n++] = line[i] - 'A';
        }
        for (int i=0;i<n;i++)
        {
            int ret = find(i);
            if (ret <= 1) break;
            printf("%d\n", ret);
        }
        printf("\n");
    }
    return 0;
}
