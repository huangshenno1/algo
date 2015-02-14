#include <cstdio>

int main() {
    int T, n, id, ans, tot;
    scanf("%d", &T);
    while (T--) {
        ans = tot = 0;
        scanf("%d", &n);
        for (int i=0;i<n;i++) {
            scanf("%d", &id);
            if (ans == 0) ans = id;
            if (ans == id) {
                tot ++;
            } else {
                tot --;
                if (tot == 0) ans = 0;
            }
        }
        printf("%d\n", ans); 
    }
    return 0;
}