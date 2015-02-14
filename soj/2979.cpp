#include <cstdio>

const int maxn = 50010;
int n,m,ans;
int fa[maxn],lv[maxn];

int find(int x)
{
    if (fa[x]==x) return x;
    int t=find(fa[x]);
    lv[x]=(lv[x]+lv[fa[x]])%3;
    return fa[x]=t;
}

int main()
{
    int d,x,y,fx,fy;
    while (~scanf("%d%d",&n,&m))
    {
        ans=0;
        for (int i=1;i<=n;i++) {fa[i]=i; lv[i]=0;}
        while (m--)
        {
            scanf("%d%d%d",&d,&x,&y);
            if (x>n || y>n) {ans++; continue;}
            if (d==2 && x==y) {ans++; continue;}
            if (d==1 && x==y) continue;
            fx=find(x); fy=find(y);
            if (fx==fy)
            {
                if ((lv[y]-lv[x]+3)%3!=d-1) {ans++; continue;}                
            }
            else
            {
                fa[fy]=fx;
                lv[fy]=(lv[fy]+lv[x]-lv[y]+d+2)%3;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
