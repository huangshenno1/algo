// Splay Tree

#include <cstdio>
typedef long long ll;

const int maxn = 100010;
int n, q, a[maxn];
int val[maxn], fa[maxn], ch[maxn][2], size[maxn], root, tot;
int add[maxn];
ll sum[maxn];

void init()
{
    root = tot = 0;
    val[0] = fa[0] = ch[0][0] = ch[0][1] = size[0] = 0;
    add[0] = sum[0] = 0;
}

void newnode(int &x, int value, int father)
{
    x = ++tot;
    val[x] = value;
    fa[x] = father;
    ch[x][0] = ch[x][1] = 0;
    size[x] = 1;
    add[x] = 0;
    sum[x] = value;
}

void push_down(int x)
{
    if (!add[x]) return;
    val[x] += add[x];
    add[ch[x][0]] += add[x]; add[ch[x][1]] += add[x];
    sum[ch[x][0]] += (ll)add[x] * size[ch[x][0]]; sum[ch[x][1]] += (ll)add[x] * size[ch[x][1]];
    add[x] = 0;
}

void push_up(int x)
{
    size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
    sum[x] = sum[ch[x][0]] + sum[ch[x][1]] + val[x] + add[x];
}

void rotate(int x, int kind)
{
    int y = fa[x];
    push_down(x); push_down(y);
    ch[y][kind^1] = ch[x][kind];
    fa[ch[x][kind]] = y;
    if (fa[y]) ch[fa[y]][ch[fa[y]][1]==y] = x;
    fa[x] = fa[y];
    ch[x][kind] = y;
    fa[y] = x;
    push_up(y);
}

void splay(int x, int goal)
{
    push_down(x);
    while (fa[x] != goal)
    {
        int y = fa[x];
        if (fa[y] == goal)
        {
            push_down(y); push_down(x);
            rotate(x, ch[y][0]==x);
        }
        else
        {
            push_down(fa[y]); push_down(y); push_down(x);
            int kind = ch[fa[y]][0]==y;
            if (ch[y][kind] == x) {rotate(x, kind^1); rotate(x, kind);}
            else {rotate(y, kind); rotate(x, kind);}
        }
    }
    push_up(x);
    if (goal == 0) root = x;
}

int get_kth(int k)
{
    int x = root;
    push_down(x);
    while (size[ch[x][0]] != k-1)
    {
        if (size[ch[x][0]] >= k) x = ch[x][0];
        else
        {
            k -= size[ch[x][0]] + 1;
            x = ch[x][1];
        }
        push_down(x);
    }
    return x;
}

void get_interval(int l, int r)
{
    splay(get_kth(l-1), 0);
    splay(get_kth(r+1), root);
    push_up(ch[root][1]);
    push_up(root);
}

bool insert(int value)
{
    int x = root;
    if (val[x] == value) return 0;
    while (ch[x][val[x]<value])
    {
        x = ch[x][val[x]<value];
        if (val[x] == value) return 0;
    }
    newnode(ch[x][val[x]<value], value, x);
    return 1;
}

void remove(int x)
{
    int y = fa[x];
    if (!ch[x][0])
    {
        ch[y][ch[y][1]==x] = ch[x][1];
        fa[ch[x][1]] = y;
    }
    else
    {
        int z = ch[x][0];
        push_down(z);
        while (ch[z][1])
        {
            z = ch[z][1];
            push_down(z);
        }
        splay(z, y);
        ch[z][1] = ch[x][1];
        fa[ch[x][1]] = z;
        ch[y][ch[y][1]==x] = z;
        fa[z] = y;
    }
}

void build(int &x, int l, int r, int father)
{
    if (l > r) return;
    int mid = (l + r) >> 1;
    newnode(x, a[mid], father);
    if (l < mid) build(ch[x][0], l, mid-1, x);
    if (mid < r) build(ch[x][1], mid+1, r, x);
    push_up(x);
}

int main()
{
    while (scanf("%d%d", &n, &q) == 2)
    {
        for (int i=1;i<=n;i++) scanf("%d", &a[i]);

        init();
        newnode(root, -1, 0);
        newnode(ch[root][1], -1, root);
        size[root] = 2;
        build(ch[ch[root][1]][0], 1, n, ch[root][1]);
        push_up(ch[root][1]);
        push_up(root);

        while (q--)
        {
            char cmd[3];
            int l, r;
            scanf("%s%d%d", cmd, &l, &r);
            get_interval(l+1, r+1);
            if (cmd[0] == 'Q')
            {
                printf("%lld\n", sum[ch[ch[root][1]][0]]);
            }
            else
            {
                int d;
                scanf("%d", &d);
                add[ch[ch[root][1]][0]] += d;
                sum[ch[ch[root][1]][0]] += size[ch[ch[root][1]][0]] * d;
            }
        }
    }
    return 0;
}

//Speed up!

inline void zig(int x)
{  
    int y = fa[x], z = fa[y];  
    ch[y][1] = ch[x][0]; fa[ch[x][0]] = y;  
    ch[x][0] = y; fa[y] = x;  
    fa[x] = z;  
    if (z) ch[z][ch[z][1]==y] = x;  
    push_up(y);  
}  

inline void zag(int x)
{  
    int y = fa[x], z = fa[y];  
    ch[y][0] = ch[x][1]; fa[ch[x][1]] = y;  
    ch[x][1] = y; fa[y] = x;  
    fa[x] = z;  
    if (z) ch[z][ch[z][1]==y] = x;  
    push_up(y);  
}  

inline void zigzig(int x)
{
    int y = fa[x], z = fa[y], fz = fa[z];  
    ch[z][1] = ch[y][0]; fa[ch[y][0]] = z;  
    ch[y][1] = ch[x][0]; fa[ch[x][0]] = y;  
    fa[z] = y; ch[y][0] = z;  
    fa[y] = x; ch[x][0] = y;  
    fa[x] = fz;  
    if (fz) ch[fz][ch[fz][1]==z] = x;  
    push_up(z); push_up(y);
}

inline void zagzag(int x)
{  
    int y = fa[x], z = fa[y], fz = fa[z];  
    ch[z][0] = ch[y][1]; fa[ch[y][1]] = z;  
    ch[y][0] = ch[x][1]; fa[ch[x][1]] = y;  
    fa[z] = y; ch[y][1] = z;  
    fa[y] = x; ch[x][1] = y;  
    fa[x] = fz;  
    if (fz) ch[fz][ch[fz][1]==z] = x;  
    push_up(z); push_up(y);  
}  

inline void zigzag(int x)
{  
    int y = fa[x], z = fa[y], fz = fa[z];  
    ch[y][1] = ch[x][0]; fa[ch[x][0]] = y;  
    ch[z][0] = ch[x][1]; fa[ch[x][1]] = z;  
    fa[y] = fa[z] = x;  
    ch[x][0] = y; ch[x][1] = z;  
    fa[x] = fz;  
    if (fz) ch[fz][ch[fz][1]==z] = x;  
    push_up(z); push_up(y);  
}  

inline void zagzig(int x)
{  
    int y = fa[x], z = fa[y], fz = fa[z];  
    ch[y][0] = ch[x][1]; fa[ch[x][1]] = y;  
    ch[z][1] = ch[x][0]; fa[ch[x][0]] = z;  
    fa[y] = fa[z] = x;  
    ch[x][1] = y; ch[x][0] = z;  
    fa[x] = fz;  
    if (fz) ch[fz][ch[fz][1]==z] = x;  
    push_up(z); push_up(y);  
}  

void splay(int x, int goal)
{  
    int y, z;  
    push_down(x);  
    while(fa[x] != goal)
	{  
		int y = fa[x];
        if (fa[y] == goal){  
            push_down(y); push_down(x);  
            if (ch[y][1] == x) zig(x);  
            else zag(x);  
        }  
        else
		{  
            z = fa[y];  
            push_down(z); push_down(y); push_down(x);  
            if (ch[z][1] == y)
			{  
                if (ch[y][1] == x) zigzig(x);  
                else zagzig(x);  
            }  
            else
			{  
                if (ch[y][0] == x) zagzag(x);  
                else zigzag(x);  
            }  
        }
    }  
    push_up(x);  
    if (fa[x] == 0) root=x;  
}  