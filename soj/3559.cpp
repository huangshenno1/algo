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

int main()
{
    int T, ans, s, zero;
    char str[40];
    scanf("%d", &T);
    while (T--)
    {
        ans = 1;
        zero = 0;
        for (int i=0;i<32;i++)
        {
            s = 0;
            scanf("%s", str);
            for (int j=0;j<32;j++) s += str[j] - '0';
            if (s == 0) zero = 1;
            ans = ans * s % 9;
        }
        if (zero) puts("0");
        else if (ans == 0) puts("9");
        else printf("%d\n", ans);
    }
    return 0;
}
