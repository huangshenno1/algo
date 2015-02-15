//后缀数组

const int maxn = 200010;
char s[maxn];
int n, sa[maxn], sx[maxn], sy[maxn], c[maxn];
int rank[maxn], height[maxn], lent[maxn], f[maxn][20];

void build_sa(int m)
{
    int *x = sx, *y = sy;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = (s[i]-'a')]++;
    for (int i = 1; i < m; i++) c[i] += c[i-1];
    for (int i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        int p = 0;
        for (int i = n-k; i < n ; i++) y[p++] = i;
        for (int i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 1; i < m; i++) c[i] += c[i-1];
        for (int i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1; x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = (y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k]) ? p-1 : p++;
        if (p >= n) break;
        m = p;
    }
}

int cmp_suffix(char *pattern, int p, int k) // k = 模板串长度
{
    return strncmp(pattern, s+sa[p], k);
}

int find(char *pattern)
{
    int k = strlen(pattern);
    if (cmp_suffix(pattern, 0, k) < 0) return -1;
    if (cmp_suffix(pattern, n-1, k) > 0) return -1;
    int low = 0, high = n-1, mid, res;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        res = cmp_suffix(pattern, mid, k);
        if (!res) return mid;
        if (res < 0) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

void getHeight()
{
    int k = 0;
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (rank[i] <= 0) continue;
        if (k) k--;
        int j = sa[rank[i]-1];
        while (i+k<n && j+k<n && s[i+k] == s[j+k]) k++;
        height[rank[i]] = k;
    }
}

void lcpinit()
{
    int k = 1, l = 0;
    for (int i = 0; i < n; i++)
    {
        f[i][0] = height[i];
        if (i+1 > k*2) {k*=2; l++;}
        lent[i+1] = l;
    }
    for (int j = 1; (1<<j)-1 < n; j++)
        for (int i = 0; i+(1<<j)-1 < n; i++)
            f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
}

int lcp(int x, int y) // rank
{
    if (x > y) swap(x, y);
    if (x == y) return n - sa[x];
    x ++;
    int k = lent[y-x+1];
    return min(f[x][k], f[y-(1<<k)+1][k]);
}
