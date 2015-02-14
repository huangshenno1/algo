#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <cassert>
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

#define ll long long
#define pii pair<int, int>
#define fr first
#define sc second
#define mp make_pair
#define FOR(i,j,k) for(int i=j;i<=(k);i++)
#define FORD(i,j,k) for(int i=j;i>=(k);i--)
#define REP(i,n) for(int i=0;i<(n);i++)

int cnt1[10], cnt2[10];

void f(int n, int *cnt)
{
    for (int i=0;i<10;i++) cnt[i] = 0;
    int sum = 0;
    for (int i=0,r=1; n; i++,n/=10,r*=10)
    {
        int x = n % 10;
        for (int j=0;j<10;j++) cnt[j] += x * i * (r / 10);
        for (int j=0;j<x;j++) cnt[j] += r;
        cnt[x] += 1 + sum;
        cnt[0] -= r;
        sum += x * r;
    }
}

int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) == 2 && a)
    {
        if (a > b) swap(a, b);
        f(a-1, cnt1);
        f(b, cnt2);
        for (int i=0;i<9;i++) printf("%d ", cnt2[i] - cnt1[i]);
        printf("%d\n", cnt2[9] - cnt1[9]);
    }
    return 0;
}
