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

int calhp(char *name)
{
    int ret = 0, n = strlen(name);
    for (int i=0;i<n;i++) ret += (83 - name[i]) * (83 - name[i]);
    ret = 300 - ret % 97;
    return ret;
}

int calstr(char *name)
{
    int ret = 1, n = strlen(name);
    for (int i=0;i<n;i++) ret = (ret * name[i]) % 79;
    ret = 22 + ret;
    return ret;
}

int calspd(char *name)
{
    int ret = 0, n = strlen(name);
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            ret += ((int)name[i] * name[j]);
    ret = ret % 11;
    return ret;
}

int main()
{
    int T;
    char name[2][25];
    int hp[2], str[2], spd[2];
    scanf("%d", &T);
    while (T--)
    {
        for (int i=0;i<2;i++)
        {
            scanf("%s", name[i]);
            hp[i] = calhp(name[i]);
            str[i] = calstr(name[i]);
            spd[i] = calspd(name[i]);
        }
        int win, t = 0;
        while (1)
        {
            t++;
            for (int i=0;i<2;i++)
                if (t % (20 - spd[i]) == 0)
                    hp[i^1] -= str[i];
            if (hp[0] <= 0 || hp[1] <= 0)
            {
                if (hp[0] <= 0 && hp[1] <= 0) win = 0;
                else if (hp[0] <= 0) win = -1;
                else win = 1;
                break;
            }
        }
        if (win == 1) puts("win");
        else if (win == 0) puts("tie");
        else puts("lose");
    }
    return 0;
}
