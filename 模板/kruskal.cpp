//kruskal

struct Edge
{
    int from,to;
    int d;
	bool operator < (const Edge rhs) const
	{
		return d < rhs.d;
	}
}edge[maxm];

int ans;
int fa[maxn];

int findset(int x)
{
	if (fa[x] == x)
		return x;
	return fa[x] = findset(fa[x]);
}

bool mergeset(int x, int y, int d)
{
	x = findset(x);
	y = findset(y);
	if (x == y) return 0;
	fa[y] = x;
	ans += d;
	return 1;
}

void kruskal()
{
	ans=0;
	for (int i = 0; i < n; i++) fa[i] = i;
	sort(edge, edge+m); //�����б� ���ݱߵ�Ȩֵ ��С��������
	int nn = n;
	for (int i = 0; i < m; i++)
	{
		if (mergeset(edge[i].from, edge[i].to, edge[i].d)) nn--; //���ϲ��ɹ���ɭ�ֵ�������һ��
	}//���nn!=1,˵��������ͼ������ͨͼ,��������С������
}