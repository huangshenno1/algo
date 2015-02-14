#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int st, ed;
    bool operator < (const Node &rhs) const
    {
        if (ed == rhs.ed) return st > rhs.st;
        return ed < rhs.ed;
    }
};

int n, m;
bool can[110];
Node a[110], b[110];

void erase()
{
    for (int i=0;i<n;i++) can[i] = 1;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            if (!(a[i].st >= b[j].ed || a[i].ed <= b[j].st))
            {
                can[i] = 0;
                break;
            }
        }
}

int main()
{
    int x, y;
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i=0;i<m;i++) scanf("%d%d", &b[i].st, &b[i].ed);
        for (int i=0;i<n;i++) scanf("%d%d", &a[i].st, &a[i].ed);
        sort(a, a+n);
        erase();
        int ans = 0, last = 0;
        for (int i=0;i<n;i++)
        {
            if (can[i] && a[i].st >= last)
            {
                last = a[i].ed;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
