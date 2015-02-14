#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int s,n;
struct Node
{
    int a,b;
    bool operator<(const Node &o) const
    {
        return  b-a>o.b-o.a;
    }
}c[maxn];
bool flag;

int main()
{
    while (scanf("%d%d",&s,&n)==2)
    {
        for (int i=0;i<n;i++) scanf("%d%d",&c[i].a,&c[i].b);
        sort(c,c+n);
        flag=1;
        for (int i=0;i<n;i++)
        {
            if (s<c[i].b)
            {
                flag=0;
                break;
            }
            s-=c[i].a;
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}