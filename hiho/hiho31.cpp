#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int di[] = {1, 1, 1, -1, -1, -1, 0, 0}, dj[] = {1, 0, -1, 1, 0, -1, 1, -1};
const int di2[] = {-2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0}, dj2[] = {-2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1};
const int maxn = 205;
int T;
int n, m;
int a[maxn][maxn], b[maxn][maxn];

inline bool valid(int i, int j) {
	return i >= 1 && i <=n && j >= 1 && j <= m;
}

inline bool near(int i1, int j1, int i2, int j2) {
	return abs(i1-i2) <= 1 && abs(j1-j2) <= 1;
}

void solve1() {
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j] == 0) {
				for (int k=0;k<8;k++) {
					int ni = i+di[k], nj = j+dj[k];
					if (valid(ni, nj) && a[ni][nj] == -1) b[ni][nj] = 0;
				}
			} else if (a[i][j] > 0) {
				int cnt = 0;
				for (int k=0;k<8;k++) {
					int ni = i+di[k], nj = j+dj[k];
					if (valid(ni, nj) && a[ni][nj] == -1) cnt++;
				}
				if (a[i][j] == cnt) {
					for (int k=0;k<8;k++) {
						int ni = i+di[k], nj = j+dj[k];
						if (valid(ni, nj) && a[ni][nj] == -1) b[ni][nj] = 1;
					}
				}
			}
}

void check(int i1, int j1, int i2, int j2) {
	if (a[i1][j1] < a[i2][j2]) {
		swap(i1, i2);
		swap(j1, j2);
	}
	for (int k=0;k<8;k++) {
		int ni = i2+di[k], nj = j2+dj[k];
		if (valid(ni, nj) && a[ni][nj] == -1 && !near(i1, j1, ni, nj)) return;
	}
	int sa_b = 0;
	for (int k=0;k<8;k++) {
		int ni = i1+di[k], nj = j1+dj[k];
		if (valid(ni, nj) && a[ni][nj] == -1 && !near(i2, j2, ni, nj)) sa_b++;
	}
	if (sa_b == a[i1][j1] - a[i2][j2]) {
		for (int k=0;k<8;k++) {
			int ni = i1+di[k], nj = j1+dj[k];
			if (valid(ni, nj) && a[ni][nj] == -1 && !near(i2, j2, ni, nj)) b[ni][nj] = 1;
		}
	}
}

void solve2() {
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j] != -1) {
				for (int k=0;k<12;k++) {
					int ni = i+di2[k], nj = j+dj2[k];
					if (valid(ni, nj) && a[ni][nj] != -1 && a[i][j] != a[ni][nj]) check(i, j, ni, nj);
				}

			}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d", &a[i][j]);
		memset(b, -1, sizeof(b));
		solve1();
		solve2();
		int ans1 = 0, ans2 = 0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (b[i][j] == 1) ans1++;
				else if (b[i][j] == 0) ans2++;
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
