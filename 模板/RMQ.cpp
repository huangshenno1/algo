//RMQ  Sparse-Table

int d[maxn][maxn];

void RMQ_init()
{
	for (int i = 1; i <= n; i++) d[i][0] = a[i];
	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= n; i++)
			d[i][j] = min(d[i][j-1], d[i + (1<<(j-1))][j-1]);
}

int RMQ(int L, int R)
{
	int j = 0;
	while ((1<<(j+1)) <= R-L+1) j++;
	return min(d[L][j], d[R-(1<<j)+1][j]);
}