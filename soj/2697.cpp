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

const int maxn = 110;
int T, l, i;
char str[maxn];

bool check1()
{
    int br = 0;
    for (int j=0;j<l;j++)
    {
        if (str[j] == '(') br++;
        else if (str[j] == ')')
        {
            br--;
            if (br < 0) return 0;
        }
    }
    return br == 0;
}

bool check2()
{
    int num = 0;
    while (i <= l)
    {
        if (isdigit(str[i]))
        {
            i++;
            if (num == 2) return 0;
            num = 1;
        }
        else if (str[i] == '(')
        {
            i++;
            if (num == 1) return 0;
            if (!check2()) return 0;
            num = 2;
        }
        else if (str[i] == ')' || str[i] == 0)
        {
            i++;
            if (num == 0) return 0;
            return 1;
        }
        else
        {
            i++;
            if (num == 0) return 0;
            num = 0;
        }
    }
    return 1;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", str);
        l = strlen(str); i = 0;
        if (check1() && check2()) puts("Yes");
        else puts("No");
    }
    return 0;
}
