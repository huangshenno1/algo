//Ïß¶ÎÊ÷_µã

int c[maxn*4];

void update(int x, int d, int rt = 1, int L = 1, int R = n)
{
	if (L == R)
		c[rt] = d;
	else
	{
		int M = (L+R) >> 1;
		if (x <= M) update(x, d, rt<<1, L, M);
		else update(x, d, rt<<1|1, M+1, R);
		c[rt] = max(c[rt<<1], c[rt<<1|1]);
	}
}

int query(int ql, int qr, int rt = 1, int L = 1, int R = n)
{
	if (ql <= L && R <= qr)
		return c[rt];
	int M = (L+R) >> 1;
	int ret = 0;
	if (ql <= M) ret = max(ret, query(ql, qr, rt<<1, L, M));
	if (M < qr) ret = max(ret, query(ql, qr, rt<<1|1, M+1, R));
	return ret;
}

void init(int rt = 1, int L = 1, int R = n)
{
	if (L == R) {c[rt] = a[L]; return;}
	int M = (L+R) >> 1;
	init(rt<<1, L, M);
	init(rt<<1|1, M+1, R);
	c[rt] = max(c[rt<<1], c[rt<<1|1]);
}