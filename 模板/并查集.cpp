//²¢²é¼¯

int fa[maxn];

void init()
{
	for (int i = 0; i < n; i++)
		fa[i] = i;
}

int findset(int x)
{
	if (fa[x] == x)
		return x;
	return fa[x] = findset(fa[x]);
}

void mergeset(int x, int y)
{
	x = findset(x);
	y = findset(y);
	if (x != y)
		fa[y] = x;
}