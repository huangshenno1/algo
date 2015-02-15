//数学

//组合数
C(n,0) = C(n,n) = 1
C(n,k) = C(n,n-k)
C(n,k) + C(n,k+1) = C(n+1,k+1)
C(n,k+1) = C(n,k) * (n-k)/(k+1)

//Catalan数
1,1,2,5,14,42,132,429,1430,4862,16796...
h(n) = h(n-1) * (4n-2)/(n+1)

//扩展欧几里得
void Extended_Euclid(int a, int b, int &d, int &x, int &y) //ax + by = gcd(a, b)
{
	if (!b) {d=a; x=1; y=0;}
	else {Extended_Euclid(b,a%b,d,y,x); y-=x*(a/b);}
}

//模线性方程
int Modular_Linear_Equation(int a, int b, int n) //ax = b mod n
{
	int x,y,e,d;
	Extended_Euclid(a,n,d,x,y);
	if (b % d) return -1;
	e = (b/d * x) % n + n;
	return e % (n/d);
}

//欧拉函数，不超过n且与n互素的整数个数
int Euler_Phi(int n)
{
	int t = (int)sqrt(n+0.5);
	int res = n;
	for (int i = 2; i <= m; i++)
		if (n % i == 0)
		{
			res = res / i * (i-1);
			while (n % i == 0) n /= i;
		}
	if (n > 1) res = res / n * (n-1);
	return res;
}

int phi[maxn];
void Phi_table(int n)
{
	for (int i = 2; i <= n; i++) phi[i] = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
		if (!phi[i])
			for (int j = i; j <= n; j+=i)
			{
				if (!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i-1);
			}
}

//乘法逆，不存在返回-1
int inv(int a, int n)
{
	int d, x, y;
	Extended_Euclid(a, n, d, x, y);
	return d==1 ? (x+n)%n : -1;
}

//可以预处理或记忆化使时间复杂度压缩为O(n)
int inv(int x)
{
	return x == 1 ? 1 : (long long)(mod - mod / x) * inv(mod % x) % mod;
}

//Lucas定理
int C(int a, int b)
{
    if (a < b) return 0;
    if (b == 0) return 1;
    if (a >= mod) return C(a/mod, b/mod) * C(a%mod, b%mod) % mod;
    int ret = ((pii[a] * inv(pii[a-b])) % mod * inv(pii[b])) % mod;
    return ret;
}

//中国剩余定理
//x = r[i] (mod m[i]) (0<=i<n)
int CRT(int *r, int *m, int n)
{
	int M = 1, d, x = 0, y;
	for (int i = 0; i < n; i++) M *= m[i];
	for (int i = 0; i < n; i++)
	{
		int w = M / m[i];
		Extended_Euclid(m[i], w, d, d, y);
		x = (x + y*w*r[i]) % M;
	}
	return (x+M) % M;
}

//Polya定理
Burnside引理：等价类数目为所有C(f)的平均值
Polya定理：等价类的个数等于所有置换f的k^m(f)的平均数

//高斯消元
//要求系数矩阵可逆
//A[i][n]是第i个方程右边的常数bi，运行结束后是第i个未知数
typedef double Matrix[maxn][maxn];
void Gauss_Elimination(Matrix A, int n)
{
	int i, j, k, r;
	for (i = 0; i < n; i++)
	{
		r = i;
		for (j = i+1; j < n; j++)
			if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
		if (r != i) for (j = 0; j <= n; j++) swap(A[r][j], A[i][j]);
		for (k = i+1; k < n; k++)
		{
			double f = A[k][i] / A[i][i];
			for (j = i; j <=n; j++) A[k][j] -= f * A[i][j];
		}
	}
	for (i = n-1; i >= 0; i--)
	{
		for (j = i+1; j < n; j++)
			A[i][n] -= A[j][n] * A[i][j];
		A[i][n] /= A[i][i];
	}
}

//连分数 a/b < p/q < c/d，求q
ll dfs(ll a,ll b,ll c,ll d)
{
	ll k=a/b;
	a-=b*k;c-=d*k;
	if(c>d) return 1;
	if(a==0) return d/c+1;
	return d*dfs(d,c,b,a)/c+1;
}

//五边形定理
int p[maxn];
void init()
{
    p[0] = 1;
    for (int i = 1; i <= 100000; i++)
    {
        int s = 0;
        for (int k=1, j, sgn=1; (j = k*(3*k-1)/2) <= i; k++, sgn*=-1)
        {
            p[i] = ((p[i] + sgn * p[i-j]) % mod + mod) % mod;
            if ((j = (-k)*(3*(-k)-1)/2) <= i)
                p[i] = ((p[i] + sgn * p[i-j]) % mod + mod) % mod;
        }
    }
}

//Mobius反演
//f(n) = sigma(d|n, g(d))
//g(n) = sigma(d|n, mu(d)*f(n/d))

//f(n) = sigma(n|d, g(d))
//g(n) = sigma(n|d, mu(d/n)*f(d))

void getmu()  
{  
    nprime=0;  
    mu[1]=1;  
    for (int i=2;i<maxn;i++)  
    {  
        if (!notprime[i]) {prime[nprime++]=i; mu[i]=-1;}  
        for (int j=0;j<nprime&&i*prime[j]<maxn;j++)  
        {  
            notprime[i*prime[j]]=1;  
            if (i%prime[j]) mu[i*prime[j]]=-mu[i];  
            else {mu[i*prime[j]]=0; break;}  
        }  
    }  
    sum[0]=0;  
    for (int i=1;i<maxn;i++) sum[i]=sum[i-1]+mu[i];  
}  

//小步大步
ll exgcd(ll a, ll b, ll &x, ll &y)  
{  
    if (b==0) {x=1; y=0; return a;}  
    ll res = exgcd(b,a%b,x,y);  
    ll t=x; x=y; y=t-a/b*y;  
    return res;  
}  
  
ll Babystep_Giantstep(ll x, ll z, ll p)  
{  
    z %= p;  
    ll val = 1;  
    for (int i=0;i<=100;i++,val=(val*x)%p)  
        if (val==z) return i;  
    ll q=1, cnt=0;  
    while ((val = gcd(x,p)) != 1)  
    {  
        if (z%val) return -1;  
        p/=val; z/=val; q=q*x/val%p;  
        cnt++;  
    }  
  
    ll m = (ll)sqrt((double)p);  
    for (int i=0;i<NN;i++) hash[i].clear();  
    val = 1;  
    for (int i=0;i<=m;i++)  
    {  
        int vv = val % NN;  
        hash[vv].push_back(Node(i,val));  
        val = (val * x) % p;  
    }  
  
    ll xm = pow_mod(x,m,p), a, b;  
    for (int i=0;i<=m;i++)  
    {  
        exgcd(q,p,a,b);  
        val = ((z*a)%p+p)%p;  
        ll vv = val % NN;  
        for (int j=0;j<hash[vv].size();j++)  
            if (hash[vv][j].xi == val)  
                return i*m+hash[vv][j].i+cnt;  
        q=(q*xm)%p;  
    }  
    return -1;  
}  
