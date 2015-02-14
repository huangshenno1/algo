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

struct Node
{
    int v, dis;
    int l, r;
}heap[maxn];

int merge(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    if (heap[a].v < heap[b].v) swap(a,b);
    heap[a].r = merge(heap[a].r, b);
    if (heap[heap[a].l].dis < heap[heap[a].r].dis) swap(heap[a].l, heap[a].r);
    if (heap[a].r == 0) heap[a].dis = 0;
    else heap[a].dis = heap[heap[a].r].dis + 1;
    return a;
}

int pop(int a)
{
    int l = heap[a].l, r = heap[a].r;
    heap[a].l = heap[a].r = heap[a].dis = 0;
    return merge(l, r);
}

int T, n;
int a[maxn];
int root[maxn], size[maxn], l[maxn], r[maxn], tot;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
            heap[i].v = a[i];
            heap[i].l = heap[i].r = heap[i].dis = 0;
        }
        tot = 0;
        for (int i=1;i<=n;i++)
        {
            tot++; root[tot] = l[tot] = r[tot] = i; size[tot] = 1;
            while (tot > 1 && heap[root[tot]].v <= heap[root[tot-1]].v)
            {
                int u = root[tot-1], v = root[tot];
                u = merge(u, v);
                bool go = ((r[tot-1]-l[tot-1]+1)%2 == 1 && (r[tot]-l[tot]+1)%2 == 1);
                size[tot-1] += size[tot]; r[tot-1] = r[tot]; tot--;
                if (go) {u = pop(u); size[tot]--;}
                root[tot] = u;
            }
        }
/*
        for (int i=1;i<=tot;i++)
            for (int j=l[i];j<=r[i];j++)
                cout << heap[root[i]].v << " ";
        cout << endl;
*/
        int ans = 0;
        for (int i=1;i<=tot;i++)
            for (int j=l[i];j<=r[i];j++)
                ans += abs(heap[root[i]].v - a[j]);
        printf("%d\n", ans);
    }
    return 0;
}
