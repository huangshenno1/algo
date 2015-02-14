#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long ll;

bool notprime[25];
int prime[10], nprime;
int fac[10];

int main()
{
    memset(notprime, 0, sizeof(notprime));
    nprime = 0;
    fac[0] = 1;
    for (int i=2;i<25;i++)
        if (!notprime[i])
        {
            prime[nprime+1] = i;
            fac[nprime+1] = fac[nprime] * i;
            nprime++;
            for (int j=i*i;j<25;j+=i) notprime[j] = 1;
        }
    int n, x, ans[10];
    while (scanf("%d", &n) == 1 && n)
    {
        x = n;
        for (int i=nprime;i>=0;i--)
        {
            ans[i] = x / fac[i];
            x %= fac[i];
        }
        printf("%d = ", n);
        bool plus = 0;
        if (ans[0]) {printf("1"); plus = 1;}
        for (int i=1;i<=nprime;i++)
            if (ans[i])
            {
                if (plus) printf(" + ");
                else plus = 1;
                printf("%d", ans[i]);
                for (int j=1;j<=i;j++) printf("*%d", prime[j]);
            }
        printf("\n");
    }
    return 0;
}
