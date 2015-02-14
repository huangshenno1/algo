#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

int a, b, c;

int main()
{
    while (scanf("%d%d%d", &a, &b, &c) == 3 && (a||b||c))
    {
        if (a>b) swap(a, b);
        if (b>c) swap(b, c);
        if (a>b) swap(a, b);
        if (a*a+b*b==c*c) puts("right");
        else puts("wrong");
    }
    return 0;
}
