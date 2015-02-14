#include <cstdio>
#include <cstring>
#include <cctype>
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

const int maxn = 205;
int T, n;
char str[maxn];

int main()
{
    while (scanf("%d", &T) == 1)
    {
        while (T--)
        {
            scanf("%d %s", &n, str);
            bool go = 1; int cnt = 0;
            for (int i=0;i<n;i++)
            {
                if (str[i] == '<') cnt--;
                else cnt++;
                if (cnt < 0) {go = 0; break;}
            }
            if (cnt != 0) go = 0;
            if (go) puts("legal");
            else puts("illegal");
        }
    }
    return 0;
}
