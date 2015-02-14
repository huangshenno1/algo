//#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

const int mod = 10000;
int T, n;
int a[2][2], b[2][2], c[2][2];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        a[0][0] = 1; a[0][1] = 1;
        a[1][0] = 0; a[1][1] = 0;
        b[0][0] = 1; b[0][1] = 1;
        b[1][0] = 1; b[1][1] = 0;
        while (n)
        {
            if (n & 1)
            {
                for (int i=0;i<2;i++)
                    for (int j=0;j<2;j++)
                    {
                        c[i][j] = 0;
                        for (int k=0;k<2;k++)
                            c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
                    }
                for (int i=0;i<2;i++)
                    for (int j=0;j<2;j++)
                        a[i][j] = c[i][j];
            }

            for (int i=0;i<2;i++)
                for (int j=0;j<2;j++)
                {
                    c[i][j] = 0;
                    for (int k=0;k<2;k++)
                        c[i][j] = (c[i][j] + b[i][k] * b[k][j]) % mod;
                }
            for (int i=0;i<2;i++)
                for (int j=0;j<2;j++)
                    b[i][j] = c[i][j];

            n >>= 1;
        }
        printf("%d\n", a[0][0]);
    }
    return 0;
}
