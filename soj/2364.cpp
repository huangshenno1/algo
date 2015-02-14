#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);

struct Complex
{
    double r, i;
    Complex(double r=0, double i=0) : r(r), i(i) {}
    Complex operator + (const Complex &o) {return Complex(r+o.r, i+o.i);}
    Complex operator - (const Complex &o) {return Complex(r-o.r, i-o.i);}
    Complex operator * (const Complex &o) {return Complex(r*o.r-i*o.i, r*o.i+o.r*i);}
};

const int maxn = 2000010;
char a[maxn], b[maxn], c[maxn*2];
Complex x1[maxn*2], x2[maxn*2];
int sum[maxn*2];

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

void mult(char *a, char *b, char *c)
{
    int len = 1, l1 = strlen(a), l2 = strlen(b);
    while (len < l1*2 || len < l2*2) len <<= 1;
    for (int i = 0; i < l1; i++) { x1[i].r = a[l1-1-i] - '0'; x1[i].i = 0.0;}
    for (int i = l1; i < len; i++) x1[i].r = x1[i].i = 0.0;
    for (int i = 0; i < l2; i++) { x2[i].r = b[l2-1-i] - '0'; x2[i].i = 0.0;}
    for (int i = l2; i < len; i++) x2[i].r = x2[i].i = 0.0;
    fft(x1, len, 1);
    fft(x2, len, 1);
    for (int i = 0; i < len; i++) x1[i] = x1[i] * x2[i];
    fft(x1, len, -1);
    for (int i = 0; i < len; i++) sum[i] = x1[i].r + 0.5;
    for (int i = 0; i < len; i++)
    {
        sum[i+1] += sum[i] / 10;
        sum[i] = sum[i] % 10;
    }
    len = l1 + l2 - 1;
    while (sum[len] <= 0 && len > 0) len--;
    len++;
    reverse(sum, sum+len);
    for (int i = 0; i < len; i++) c[i] = sum[i] + '0';
    c[len] = '\0';
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s %s", a, b);
        mult(a,b,c);
        printf("%s\n",c);
    }
    return 0;
}
