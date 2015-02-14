#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x7fffffff;
int n,m,n1;
int a[50];
long long s;
int ans;
vector<int> ss[2];
int i,j;

int getsum(int l,int r,int k)
{
    for (i=0;i<(1<<(r-l+1));i++)
    {
        s=0;
        for (j=0;j<r-l+1;j++)
        {
            if (i&(1<<j))
                s=s+a[j+l];
        }
        if (s==m)
            return 1;
        ss[k].push_back(s);
    }
    return 0;
}

int solve(int x)
{
    if (x>=m)
        return x;
    if (ss[1][ss[1].size()-1]<m-x)
        return INF;
    if (ss[1][0]>=m-x)
        return x+ss[1][0];
    int low=1,high=ss[1].size()-1;
    int mid;
    while (low<=high)
    {
        mid=(low+high)>>1;
        if (ss[1][mid]>=m-x && ss[1][mid-1]<m-x)
            return x+ss[1][mid];
        if (ss[1][mid]<m-x)
            low=mid+1;
        if (ss[1][mid-1]>=m-x)
            high=mid-1;
    }
    return INF;
}

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        for (i=0,s=0;i<n;i++)
        {    
            scanf("%d",&a[i]);
            s+=a[i];
        }
        if (s<m)
        {
            printf("-1\n");
            continue;
        }
        ss[0].clear();
        ss[1].clear();
        n1=n/2;
        if (getsum(0,n1,0))
        {
            printf("%d\n",m);
            continue;
        }
        if (getsum(n1+1,n-1,1))
        {
            printf("%d\n",m);
            continue;
        }
        sort(ss[0].begin(),ss[0].end());
        sort(ss[1].begin(),ss[1].end());
        ans=INF;
        for (i=0;i<ss[0].size();i++)
            ans=min(ans,solve(ss[0][i]));
        printf("%d\n",ans);
    }
    return 0;
}