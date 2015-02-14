#include <cstdio>
#include <algorithm>
using namespace std;

struct Part
{
    int id;
    double f,m;
    bool operator < (const Part t) const
    {
        return f/m>t.f/t.m;
    }
}part[10010];
int n;
double f,m;
bool vis[10010];
int cnt;

int main()
{
    while (scanf("%lf%lf%d",&f,&m,&n)==3)
    {
        for (int i=0;i<n;i++)
        {
            part[i].id=i+1;
            vis[i+1]=0;
            scanf("%lf%lf",&part[i].f,&part[i].m);
        }
        sort(part,part+n);
        for (int i=0;i<n;i++)
        {
            if ((f+part[i].f)/(m+part[i].m)<f/m) break;
            f+=part[i].f;
            m+=part[i].m;
            vis[part[i].id]=1;
        }
        cnt=0;
        for (int i=1;i<=n;i++)
        {
            if (vis[i])
            {
                printf("%d\n",i);
                cnt++;
            }
        }
        if (cnt==0) puts("NONE");
    }
    return 0;
}