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
const int INF = 0x3f3f3f3f;
const int maxn = 10010;

int n,m,r,c;
char a[maxn],b[maxn];

int main()
{
    while (scanf("%s%s",a,b)==2)
    {
        n=strlen(a); m=strlen(b);
        r=c=-1;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
                if (a[i]==b[j])
                {
                    r=j;
                    c=i;
                    break;
                }
            if (r>=0) break;
        }
        for (int j=0;j<m;j++)
        {
            if (j==r)
                printf("%s\n",a);
            else
            {
                for (int i=0;i<n;i++)
                {
                    if (i==c) printf("%c",b[j]);
                    else printf(".");
                }
                puts("");
            }
        }
    }
    return 0;
}
