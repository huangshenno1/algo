//KD-Tree

struct Point
{
    int x, y, id;
};
bool cmpX(const Point &a, const Point &b) {return a.x < b.x;}
bool cmpY(const Point &a, const Point &b) {return a.y < b.y;}

bool divX[maxn];
void buildKD(int l, int r, Point *p)
{
    if (l > r) return;
    int mid = (l + r) >> 1;
    int minX = min_element(p+l, p+r+1, cmpX)->x;
    int maxX = max_element(p+l, p+r+1, cmpX)->x;
    int minY = min_element(p+l, p+r+1, cmpY)->y;
    int maxY = max_element(p+l, p+r+1, cmpY)->y;
    divX[mid] = maxX - minX >= maxY - minY;
    nth_element(p+l, p+mid, p+r+1, divX[mid] ? cmpX : cmpY);
    buildKD(l, mid-1, p);
    buildKD(mid+1, r, p);
}

ll mindis;
void find(int l, int r, Point a, Point *p)
{
    if (l > r) return;
    int mid = (l + r) >> 1;
    ll dis = ((ll)a.x-p[mid].x)*((ll)a.x-p[mid].x) + ((ll)a.y-p[mid].y)*((ll)a.y-p[mid].y);
    if (dis > 0 && dis < mindis) mindis = dis; // 无重点
    ll d = divX[mid] ? a.x-p[mid].x : a.y-p[mid].y;
    int l1 = l ,r1 = mid-1, l2 = mid+1, r2 = r;
    if (d > 0) {swap(l1, l2); swap(r1, r2);}
    find(l1, r1, a, p);
    if (d * d < mindis) find(l2, r2, a, p);
}

// n维空间最近m点
int n, k, idx, q, m;

struct Point
{
    int x[5];
    bool operator < (const Point &o) const {return x[idx] < o.x[idx];}
}p[maxn], a, ans[15];

typedef pair<double, Point> tp;
priority_queue<tp> nq;

Point pt[maxn << 2];
int son[maxn << 2];

void buildKD(int l, int r, int rt = 1, int dep = 0)
{
    if (l > r) return;
    son[rt] = r - 1;
    son[rt<<1] = son[rt<<1|1] = -1;
    idx = dep % k;
    int mid = (l + r) >> 1;
    nth_element(p+l, p+mid, p+r+1);
    pt[rt] = p[mid];
    buildKD(l, mid-1, rt<<1, dep+1);
    buildKD(mid+1, r, rt<<1|1, dep+1);
}

void find(Point a, int m, int rt = 1, int dep = 0)
{
    if (son[rt] == -1) return;
    tp node(0, pt[rt]);
    for (int i = 0; i < k; i++) node.first += ((double)a.x[i]-pt[rt].x[i]) * ((double)a.x[i]-pt[rt].x[i]);
    int dim = dep % k, lhs = rt << 1, rhs = rt << 1 | 1, flag = 0;
    if (a.x[dim] >= pt[rt].x[dim]) swap(lhs, rhs);
    if (son[lhs] != -1) find(a, m, lhs, dep+1);
    if (nq.size() < m) nq.push(node), flag = 1;
    else
    {
        if (node.first < nq.top().first) nq.pop(), nq.push(node);
        if ((a.x[dim]-pt[rt].x[dim])*(a.x[dim]-pt[rt].x[dim]) < nq.top().first) flag = 1;
    }
    if (son[rhs] != -1 && flag) find(a, m, rhs, dep+1);
}

