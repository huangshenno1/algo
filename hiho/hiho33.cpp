#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 10005;
int T, n, m;
vector<int> g[maxn];
int color[maxn];

void addEdge(int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}

void init() {
	for (int i=0;i<n;i++) {
		g[i].clear();
		color[i] = 0;
	}
}

bool bipartite(int u) {
	for (int i=0;i<g[u].size();i++) {
		int v = g[u][i];
		if (color[u] == color[v]) return false;
		if (!color[v]) {
			color[v] = 3 - color[u];
			if (!bipartite(v)) return false;
		}
	}
	return true;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		init();
		for (int i=0;i<m;i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u-1, v-1);
		}
		bool correct = true;
		for (int i=0;i<n;i++) {
			if (!color[i]) {
				color[i] = 1;
				correct = bipartite(i);
				if (!correct) break;
			}
		}
		puts(correct ? "Correct" : "Wrong");
	}
	return 0;
}
