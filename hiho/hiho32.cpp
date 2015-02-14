#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int di[] = {1, 1, 1, -1, -1, -1, 0, 0}, dj[] = {1, 0, -1, 1, 0, -1, 1, -1};
const int maxn = 15;
int T;
int n, m;
int a[maxn][maxn], b[maxn];
int ui[maxn], uj[maxn], ans[maxn], k, tot;

inline bool valid(int i, int j) {
	return i >= 1 && i <=n && j >= 1 && j <= m;
}

bool check(int u) {
    int i = ui[u], j = uj[u];
    for (int r=0;r<8;r++) {
        int ni = i+di[r], nj = j+dj[r];
        if (!valid(ni, nj)) continue;
        if (a[ni][nj] == 0) return false;
    }
    for (int r=0;r<8;r++) {
        int ni = i+di[r], nj = j+dj[r];
        if (!valid(ni, nj)) continue;
        if (a[ni][nj] != -1) a[ni][nj]--;
    }
    return true;
}

void uncheck(int u) {
    int i = ui[u], j = uj[u];
    for (int r=0;r<8;r++) {
        int ni = i+di[r], nj = j+dj[r];
        if (!valid(ni, nj)) continue;
        if (a[ni][nj] != -1) a[ni][nj]++;
    }
}

bool check2(int u) {
    int i = ui[u], j = uj[u];
    for (int r=0;r<8;r++) {
        int ni = i+di[r], nj = j+dj[r];
        if (!valid(ni, nj)) continue;
        if (a[ni][nj] > 0) return false;
    }
    return true;
}

void dfs(int u) {
    if (u == k) {
        for (int i=0;i<k;i++)
            if (!check2(i)) return;
        for (int i=0;i<k;i++) {
            if (ans[i] == -1 || ans[i] == b[i]) ans[i] = b[i];
            else ans[i] = -2;
        }
        return;
    }
    int i = ui[u], j = uj[u];
    b[u] = 1;
    if (check(u)) {
        dfs(u+1);
        uncheck(u);
    }
    b[u] = 0;
    dfs(u+1);
}

void solve() {
    k = 0; tot = 0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j] == -1) {
                ui[k] = i;
                uj[k++] = j;
            }
    if (k == 0) return;
    dfs(0);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d", &a[i][j]);
		memset(b, -1, sizeof(b));
		memset(ans, -1, sizeof(ans));
		solve();
		int ans1 = 0, ans2 = 0;
		for (int i=0;i<k;i++)
            if (ans[i] == 1) ans1++;
            else if (ans[i] == 0) ans2++;
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
