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

#define lhs rt<<1
#define rhs rt<<1|1

const int maxn = 20010;
int T, n, l[maxn], r[maxn], ans;
int val[maxn*4], lazy[maxn*4];
vector<int> num;
int tot;
map<int, int> dic;
bool vis[maxn];

void update(int x, int rt, int L, int R)
{
    lazy[rt] = x;
    val[rt] = x;
}

void query(int ql, int qr, int x, int rt = 1, int L = 1, int R = tot)
{
    if (ql <= L && R <= qr)
    {
        update(x, rt, L, R);
        return;
    }
    int M = (L+R) >> 1;
    if (lazy[rt])
    {
        update(lazy[rt], lhs, L, M);
        update(lazy[rt], rhs, M+1, R);
        lazy[rt] = 0;
    }
    if (ql <= M) query(ql, qr, x, lhs, L, M);
    if (qr > M) query(ql, qr, x, rhs, M+1, R);
}

void init(int rt = 1, int L = 1, int R = tot)
{
    val[rt] = 0; lazy[rt] = 0;
    if (L == R) return;
    int M = (L+R) >> 1;
    init(lhs, L, M);
    init(rhs, M+1, R);
}

void dfs(int rt = 1, int L = 1, int R = tot)
{
    if (L == R)
    {
        vis[val[rt]] = 1;
        return;
    }
    int M = (L+R) >> 1;
    if (lazy[rt])
    {
        update(lazy[rt], lhs, L, M);
        update(lazy[rt], rhs, M+1, R);
        lazy[rt] = 0;
    }
    dfs(lhs, L, M);
    dfs(rhs, M+1, R);
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        num.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d", &l[i], &r[i]);
            num.push_back(l[i]);
            num.push_back(r[i]);
        }
        sort(num.begin(), num.end());
        num.erase(unique(num.begin(), num.end()), num.end());
        tot = num.size();
        dic.clear();
        for (int i=0;i<tot;i++) dic[num[i]] = i+1;

        init();
        for (int i=1;i<=n;i++) query(dic[l[i]], dic[r[i]], i);
        memset(vis, 0, sizeof(vis));
        dfs();
        ans = 0;
        for (int i=1;i<=n;i++)
            if (vis[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
