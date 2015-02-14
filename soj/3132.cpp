#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k;
int sg[110][110];

int mex(vector<int> next)
{
    int res=0;
    sort(next.begin(),next.end());
    for (int i=0;i<next.size();i++)
    {
        if (res==next[i])
            res++;
    }
    return res;
}

int SG(int x,int y)
{
    if (sg[x][y]>=0)
        return sg[x][y];
    vector<int> next;
    next.clear();
    if (x-2>=0 && y-1>=0)
        next.push_back(SG(x-2,y-1));
    if (x-2>=0 && y+1<m)
        next.push_back(SG(x-2,y+1));
    if (x-1>=0 && y-2>=0)
        next.push_back(SG(x-1,y-2));
    if (x+1<n && y-2>=0)
        next.push_back(SG(x+1,y-2));
    if (next.size()==0)
        return sg[x][y]=0;
    return sg[x][y]=mex(next);
}

int main()
{
    int ans,x,y;
    while (scanf("%d%d%d",&n,&m,&k)==3)
    {
        ans=0;
        memset(sg,-1,sizeof(sg));
        for (int i=0;i<k;i++)
        {
            scanf("%d%d",&x,&y);
            ans^=SG(x,y);
        }
        if (ans) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}