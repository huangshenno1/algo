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

const int maxn = 100010;
int cas = 1, l, n, x, step;
char str[maxn], tmp[maxn];
map<int, string> dic;

void go(int i)
{
    if (n >= 10000) step = 5;
    else if (n >= 1000) step = 4;
    else if (n >= 100) step = 3;
    else if (n >= 10) step = 2;
    x = 0;
    for (int j=0;j<step;j++)
        x = x*10 + str[i+j] - '0';
    dic[n] += dic[x][0];
    printf("%s", dic[x].c_str());
    dic[++n] = dic[x];
}

int main()
{
    while (scanf("%s", str) == 1 && strcmp(str, "0") != 0)
    {
        dic.clear();
        scanf("%d", &n);
        for (int i=0;i<n;i++)
        {
            scanf("%s", tmp);
            dic[i] = tmp;
        }

        printf("Case %d: ", cas++);
        l = strlen(str);
        if (n <= 10) step = 1;
        else step = 2;

        x = 0;
        for (int j=0;j<step;j++)
            x = x*10 + str[j] - '0';
        printf("%s", dic[x].c_str());
        dic[n] = dic[x];
        for (int i=step;i<l;i+=step) go(i);

        printf("\n");
    }
    return 0;
}
