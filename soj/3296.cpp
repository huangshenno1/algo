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

const int maxn = 100010;
int T;
char str[maxn];

int MinimumRepresentation(char *s, int l)
{
    int i = 0, j = 1, k = 0, d;
    while (i < l && j < l && k < l)
    {
        d = s[i+k>=l ? i+k-l : i+k] - s[j+k>=l ? j+k-l : j+k];
        if (d == 0) k++;
        else
        {
            if (d > 0) i = i + k + 1;
            else j = j + k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    return i < j ? i : j;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", str);
        int l = strlen(str);
        int st = MinimumRepresentation(str, l);
        for (int i=st;i<l;i++) printf("%c", str[i]);
        for (int i=0;i<st;i++) printf("%c", str[i]);
        puts("");
    }
    return 0;
}
