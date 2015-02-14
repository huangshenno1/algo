#include <cstdio>
#include <cstring>

int T, ans;
int a[2005], b[2005];
int n, m;
int dp[2005][2005];

const int maxnode = 50000;
const int sigma_size = 26;
int ch[maxnode][sigma_size];
int val[maxnode];
int sz, tot;
char str[25000], tmp[20];
inline int idx(char c) {return c - 'a';}

void init()
{
    tot = 0;
    sz = 1;
    memset(ch[0], 0, sizeof(ch[0]));
    memset(val, 0, sizeof(val));
}

int insert(char *s, int l)
{
    int u = 0;
    for (int i = 0; i < l; i++)
    {
        int c = idx(s[i]);
        if (!ch[u][c])
        {
            memset(ch[sz], 0, sizeof(ch[sz]));
            val[sz] = 0;
            ch[u][c] = sz++;
        }
        u = ch[u][c];
    }
    if (val[u] == 0) val[u] = ++tot;
    return val[u];
}

void read(int *a, int &n)
{
    gets(str);
    int l = strlen(str); str[l] = ' ';
    n = 0; int k = 0;
    for (int i=0;i<=l;i++)
    {
        if (str[i] == ' ')
        {
            tmp[k] = 0;
            a[++n] = insert(tmp, k);
            k = 0;
        }
        else tmp[k++] = str[i];
    }
}

inline int max(int a, int b) {return a > b ? a : b;}

int main()
{
    scanf("%d", &T); getchar();
    while (T--)
    {
        init();
        read(a, n);
        read(b, m);

        for (int i=0;i<=n;i++) dp[i][0] = 0;
        for (int j=0;j<=m;j++) dp[0][j] = 0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                dp[i][j] = max(dp[i-1][j-1] + (a[i] == b[j]), max(dp[i][j-1], dp[i-1][j]));

        ans = n + m - dp[n][m];
        printf("%d\n", ans);
    }
    return 0;
}
