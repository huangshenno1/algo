#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long

const double PI = acos(-1.0);

struct Complex
{
    double r, i;
    Complex(double r=0, double i=0) : r(r), i(i) {}
    Complex operator + (const Complex &o) {return Complex(r+o.r, i+o.i);}
    Complex operator - (const Complex &o) {return Complex(r-o.r, i-o.i);}
    Complex operator * (const Complex &o) {return Complex(r*o.r-i*o.i, r*o.i+o.r*i);}
};

const int maxn = 15005;
Complex x1[maxn*4], x2[maxn*4];

void brc(Complex *y, int len)
{
    for (int i=1, j=len/2; i < len-1; i++)
    {
        if (i < j) swap(y[i], y[j]);
        int k = len/2;
        while (j >= k) { j -= k; k /= 2; }
        if (j < k) j += k;
    }
}

void fft(Complex *y, int len, int on)
{
    brc(y, len);
    for (int i = 2; i <= len; i <<= 1)
    {
        Complex wn(cos(on*2.0*PI/i), sin(on*2.0*PI/i));
        for (int j = 0; j < len; j += i)
        {
            Complex w(1.0, 0.0);
            for (int k = j; k < j+i/2; k++)
            {
                Complex u = y[k];
                Complex t = w*y[k+i/2];
                y[k] = u + t;
                y[k+i/2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1)
        for (int i = 0; i < len; i++)
            y[i].r /= len;
}

int T, cas = 1;
int n, m, tot;
int a[305];
int xa[maxn], xb[maxn];
int ans;

int main ()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        tot = 0;
        for (int i=1;i<=n;i++) scanf("%d", &a[i]);
        sort(a+1, a+n+1); tot = n;
        for (int i=1;i<=n;i++) a[++tot] = a[i]*2;
        for (int i=1;i<n;i++) a[++tot] = a[i]*3;
        n = tot;
        memset(xa, 0, sizeof(xa)); xa[0] = 1;
        memset(xb, 0, sizeof(xb)); xb[0] = 1;
        for (int i=1;i<=n;i++) xa[a[i]] = xb[a[i]] = 1;

        tot = m-1;
        while (tot--)
        {
            int len = 1<<14;
            for (int i=0;i<=15000;i++) {x1[i].r = xa[i]; x1[i].i = 0;}
            for (int i=15000;i<len;i++) x1[i].r = x1[i].i = 0;
            for (int i=0;i<=15000;i++) {x2[i].r = xb[i]; x2[i].i = 0;}
            for (int i=15000;i<len;i++) x2[i].r = x2[i].i = 0;
            fft(x1, len, 1);
            fft(x2, len, 1);
            for (int i=0;i<len;i++) x1[i] = x1[i] * x2[i];
            fft(x1, len, -1);
            for (int i=0;i<=15000;i++) xa[i] = x1[i].r + 0.5;
        }
        ans = 0;
        for (int i=0;i<=15000;i++) if (xa[i]) ans++;
        printf("Scenario #%d:\n", cas++);
        printf("%d\n\n", ans);
    }
    return 0;
}
