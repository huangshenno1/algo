#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int d[4]={1,-1,3,-3};
int ans,a[10],b[10],bb[10][2];
bool vis[400000];
int c[9]={1,1,2,6,24,120,720,5040,40320};

void swap(int &a, int &b)
{
    int t=a;a=b;b=t;
}

bool inside(int i,int j)
{
    if (i+j<0 || i+j>=9) return 0;
    if (i%3==0 && j==-1) return 0;
    if (i%3==2 && j==1) return 0;
    return 1;
}

struct Node
{
    int num[10];
    int f,g,h,hash;
    bool operator < (const Node &o) const {return f>o.f;}
    void geth()
    {
        h=0;
        for (int i=0;i<9;i++)
            if (num[i]) h+=abs(i/3-bb[num[i]][0])+abs(i%3-bb[num[i]][1]);
    }
    void gethash()
    {
        hash=0;
        int cnt=0,zero;
        for (int i=0;i<9;i++)
        {
            if (num[i]==0) {zero=i; continue;}
            int k=0;
            for (int j=0;j<i;j++)
                if (num[j]>num[i]) k++;
            hash+=k*c[cnt++];
        }
        hash+=(8-zero)*c[8];
    }
    void hehe()
    {
        gethash();
        if (vis[hash]) return;
        geth();
        f=g+h;
    }
}t,tt;
priority_queue<Node> Q;

void Astar()
{
    while (!Q.empty()) Q.pop();
    memset(vis,0,sizeof(vis));
    for (int i=0;i<9;i++) t.num[i]=a[i];
    t.g=0; t.hehe();
    Q.push(t);
    while (!Q.empty())
    {
        t=Q.top(); Q.pop();
        if (vis[t.hash]) continue;
        vis[t.hash]=1;
        if (t.h==0) {ans=t.g; return;}
        int zero;
        for (int i=0;i<9;i++)
            if (t.num[i]==0) zero=i;
        for (int r=0;r<4;r++)
        {
            if (!inside(zero,d[r])) continue;
            tt=t;
            swap(tt.num[zero],tt.num[zero+d[r]]);
            tt.g=t.g+1; tt.hehe();
            if (vis[tt.hash]) continue;
            Q.push(tt);
        }
    }
}

int main()
{
    int T,x;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=0;i<9;i++) scanf("%d",&a[i]);
        for (int i=0;i<9;i++) scanf("%d",&b[i]);
        int inv=0;
        for (int i=0;i<9;i++)
            for (int j=0;j<i;j++)
            {
                if (a[i]&&a[j]&&a[i]<a[j]) inv++;
                if (b[i]&&b[j]&&b[i]<b[j]) inv++;
            }
        if (inv&1)
        {
            puts("-1");
            continue;
        }

        for (int i=0;i<9;i++)
        {
            x=b[i];
            bb[x][0]=i/3;
            bb[x][1]=i%3;
        }

        ans=-1;
        Astar();
        printf("%d\n",ans);
    }
    return 0;
}
