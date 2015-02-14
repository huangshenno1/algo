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

const int maxn = 1000005;
char in[maxn], out[maxn], c;
int bra[maxn], top, cur;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (gets(in) && strcmp(in, "$") != 0)
    {
        cur = 0; top = -1;
        for (int i=0;in[i];i++)
        {
            c = in[i];
            if (c == '$') {out[cur] = '\0'; break;}
            else if (c == ' ') continue;
            else if (c == '(') bra[++top] = cur;
            else if (c == ')') top--;
            else if (isdigit(c))
            {
                int k = 0, st = bra[top], ed = cur;
                while (isdigit(c))
                {
                    k = k * 10 + c - '0';
                    c = in[++i];
                }
                i--;
                if (k == 0)
                {
                    for (int j=st;j<ed;j++) cur--;
                }
                while (k>1)
                {
                    for (int j=st;j<ed;j++) out[cur++] = out[j];
                    k--;
                }
            }
            else out[cur++] = c;
        }
        printf("%s\n", out);
    }
    return 0;
}
