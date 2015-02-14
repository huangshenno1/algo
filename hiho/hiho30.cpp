#include <cstdio>

const int maxn = 100005;
int T;
int n, a1[maxn], a0[maxn], b[maxn];
int cnt1, cnt0, ans1[maxn], ans0[maxn];

bool solve(int fr, int *a) {
    a[0] = 0;
    a[1] = fr;
    for (int i=2;i<=n;i++) {
        int d = b[i-1] - (a[i-1] + a[i-2]);
        if (d == 1 || d == 0) a[i] = d;
        else return false;
    }
    if (a[n-1] + a[n] != b[n]) return false;
    return true;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i=1;i<=n;i++) scanf("%d", &b[i]);
        bool f1 = solve(1, a1);
        bool f0 = solve(0, a0);
        cnt1 = cnt0 = 0;
        if (f1 && f0) {
            for (int i=1;i<=n;i++)
                if (a1[i] == 1 && a0[i] == 1) ans1[cnt1++] = i;
                else if (a1[i] == 0 && a0[i] == 0) ans0[cnt0++] = i;
        } else if (f1) {
            for (int i=1;i<=n;i++)
                if (a1[i] == 1) ans1[cnt1++] = i;
                else ans0[cnt0++] = i;
        } else {
            for (int i=1;i<=n;i++)
                if (a0[i] == 1) ans1[cnt1++] = i;
                else ans0[cnt0++] = i;
        }
        printf("%d", cnt1);
        for (int i=0;i<cnt1;i++) printf(" %d", ans1[i]);
        printf("\n%d", cnt0);
        for (int i=0;i<cnt0;i++) printf(" %d", ans0[i]);
        printf("\n");
    }
    return 0;
}
