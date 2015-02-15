//×óÆ«Ê÷

struct LeftistTree
{
    int v, dis;
    int l, r, fa;
}heap[maxn];

int merge(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    if (heap[a].v <heap[b].v) swap(a,b);
    heap[a].r = merge(heap[a].r, b);
    heap[heap[a].r].fa = a;
    if (heap[heap[a].l].dis < heap[heap[a].r].dis) swap(heap[a].l, heap[a].r);
    if (heap[a].r == 0) heap[a].dis = 0;
    else heap[a].dis = heap[heap[a].r].dis + 1;
    return a;
}

int pop(int a)
{
    int l = heap[a].l, r = heap[a].r;
    heap[l].fa = l;
    heap[r].fa = r;
    heap[a].l = heap[a].r = heap[a].dis = 0;
    return merge(l, r);
}

int find(int a)
{
    return heap[a].fa == a ? a : find(heap[a].fa);
}
